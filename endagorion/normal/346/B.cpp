#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MAXN = 105;

struct TState {
    int x, y, z;
    TState(int x = 0, int y = 0, int z = 0)
        : x(x)
        , y(y)
        , z(z)
    {
    }
};

int reach[MAXN][MAXN][MAXN];
TState p[MAXN][MAXN][MAXN];

int trans[MAXN][30];
int N, M, K;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s1, s2, v;
    cin >> s1 >> s2 >> v;
    N = s1.size();
    M = s2.size();
    K = v.size();
    reach[0][0][0] = true;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < 26; ++j) {
            string q = string(v.begin(), v.begin() + i) + (char)('A' + j);
            for (int k = i + 1; k >= 0; --k) {
                if (string(v.begin(), v.begin() + k) == string(q.end() - k, q.end())) {
                    trans[i][j] = k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            for (int k = 0; k <= K; ++k) {
                reach[i][j][k] = -1e9;                
            }
        }
    }
    s1 += '#';
    s2 += '$';
    reach[0][0][0] = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            for (int k = 0; k < K; ++k) {
                if (reach[i][j][k] < 0) {
                    continue;
                }
                if (s1[i] == s2[j] && reach[i][j][k] + 1 > reach[i + 1][j + 1][trans[k][s1[i] - 'A']]) {
                    reach[i + 1][j + 1][trans[k][s1[i] - 'A']] = reach[i][j][k] + 1;
                    p[i + 1][j + 1][trans[k][s1[i] - 'A']] = TState(i, j, k);
                }
                if (reach[i][j][k] > reach[i + 1][j][k]) {
                    reach[i + 1][j][k] = reach[i][j][k];
                    p[i + 1][j][k] = TState(i, j, k);
                }
                if (reach[i][j][k] > reach[i][j + 1][k]) {
                    reach[i][j + 1][k] = reach[i][j][k];
                    p[i][j + 1][k] = TState(i, j, k);
                }
            }
        }
    }

    int bk = 0;
    for (int i = 0; i < K; ++i) {
        if (reach[N][M][i] > reach[N][M][bk]) {
            bk = i;
        }
    }
    if (reach[N][M][bk] <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    TState cur(N, M, bk);
    string ans;
    while (cur.x > 0 && cur.y > 0) {
        TState pp = p[cur.x][cur.y][cur.z];
        if (pp.x < cur.x && pp.y < cur.y) {
            ans = s1[pp.x] + ans;
        }
        cur = pp;
    }
    cout << ans << '\n';
    
	return 0;
}