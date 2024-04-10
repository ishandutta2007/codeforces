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

typedef pair<int, int> pii;

string f[20];
int N;
int dp[40][1 << 20];
int pos[20][20];
vector<pii> diag[50];

int score(char c) {
    if (c == 'a') {
        return 1;
    }
    if (c == 'b') {
        return -1;
    }
    return 0;
}

int dpCount(int s, int sub) {
    if (dp[s][sub] > -1e8) {
        return dp[s][sub];
    }
    if (s == 2 * (N - 1)) {
        return dp[s][sub] = 0;
    }
    int p = s % 2;
    int t[26] = {};
    for (size_t i = 0; i < diag[s].size(); ++i) {
        if (!(sub & (1 << i))) {
            continue;
        }
        int x = diag[s][i].first, y = diag[s][i].second;
        if (x + 1 < N) {
            int p = pos[x + 1][y];
            int l = f[x + 1][y] - 'a';
            t[l] |= (1 << p);
        }
        if (y + 1 < N) {
            int p = pos[x][y + 1];
            int l = f[x][y + 1] - 'a';
            t[l] |= (1 << p);
        }
    }
    int res = p ? -1e9 : 1e9;
    for (int i = 0; i < 26; ++i) {
        if (t[i] == 0) {
            continue;
        }
        int r = score(i + 'a') + dpCount(s + 1, t[i]);
        if (p && r > res || !p && r < res) {
            res = r;
        }
    }
    return dp[s][sub] = res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i <= 2 * (N - 1); ++i) {
        for (int j = 0; j < (1 << N); ++j) {
            dp[i][j] = -1e9;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i + 1 >= N || j - 1 < 0) {
                int p = 0;
                int x = i, y = j;
                while (x >= 0 && y < N) {
                    diag[x + y].pb(mp(x, y));
                    pos[x][y] = p++;
                    --x; ++y;
                }
            }
        }
    }
    int r = score(f[0][0]) + dpCount(0, 1);
    if (r > 0) {
        cout << "FIRST\n";
    }
    if (r < 0) {
        cout << "SECOND\n";
    }
    if (r == 0) {
        cout << "DRAW\n";
    }

	return 0;
}