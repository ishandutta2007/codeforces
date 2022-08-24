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

int n1 = 0, n2 = 0;

const long long P = 1000000000 + 7;

int mind[51][51][2];
long long ways[51][51][2];
long long CNK[51][51];

struct Triple {
    int x, y, k;

    Triple(int _x = 0, int _y = 0, int _k = 0)
        : x(_x)
        , y(_y)
        , k(_k)
    {
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        (x == 50) ? ++n1 : ++n2;
    }
    for (int i = 0; i <= 50; ++i) {
        for (int j = 0; j <= 50; ++j) {
            for (int k = 0; k < 2; ++k) {
                mind[i][j][k] = 1e9;
                ways[i][j][k] = 0;
            }
        }
    }
    mind[0][0][0] = 0;
    ways[0][0][0] = 1;

    CNK[0][0] = 1;
    for (int i = 1; i <= 50; ++i) {
        CNK[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            CNK[i][j] = (CNK[i - 1][j - 1] + CNK[i - 1][j]) % P;
        }
    }
    vector<Triple> q;
    q.pb(Triple(0, 0, 0));
    int cur = 0;
    while (cur < q.size()) {
        int x = q[cur].x, y = q[cur].y, k = q[cur].k;
        int D = mind[x][y][k];
        long long W = ways[x][y][k];
        ++cur;
        if (k == 0) {
            x = n1 - x;
            y = n2 - y;
        }
        for (int i = 0; i <= x && 50 * i <= K; ++i) {
            for (int j = 0; j <= y && 50 * i + 100 * j <= K; ++j) {
                if (i + j == 0) {
                    continue;
                }
                int xx = n1 - x + i, yy = n2 - y + j, kk = 1 - k;
                if (kk == 0) {
                    xx = n1 - xx;
                    yy = n2 - yy;
                }
                if (mind[xx][yy][kk] <= D) {
                    continue;
                }
                if (mind[xx][yy][kk] > D + 1) {
                    mind[xx][yy][kk] = D + 1;
                    ways[xx][yy][kk] = 0;
                    q.pb(Triple(xx, yy, kk));
                }
                ways[xx][yy][kk] += (W * CNK[x][i]) % P * CNK[y][j] % P;
                ways[xx][yy][kk] %= P;
            }
        }
    }

    cout << ((mind[n1][n2][1] < 1e9) ? mind[n1][n2][1] : -1) << '\n';
    cout << ways[n1][n2][1] << '\n';
	return 0;
}