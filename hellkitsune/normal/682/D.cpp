#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
string s, t;
int d[1005][1005][21] = {};

inline void upd(int &x, int y) {
    x = max(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> s >> t;
    k = 2 * k + 1;
    REP(i, n + 1) REP(j, m + 1) {
        REP(z, k - 1) upd(d[i][j][z + 1], d[i][j][z]);
        REP(z, k) {
            if (z & 1) {
                if (i < n && j < m && s[i] == t[j]) {
                    upd(d[i + 1][j + 1][z], d[i][j][z] + 1);
                }
            } else {
                if (i < n) upd(d[i + 1][j][z], d[i][j][z]);
                if (j < m) upd(d[i][j + 1][z], d[i][j][z]);
            }
        }
    }
    cout << d[n][m][k - 1] << endl;
    return 0;
}