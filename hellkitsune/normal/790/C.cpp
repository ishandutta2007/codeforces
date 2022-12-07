#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
string s;
int a[75];
int d[77][77][77][3];
int c[3] = {};

inline void upd(int &x, int y) {
    x = min(x, y);
}

int main() {
    cin >> n >> s;
    forn(i, n) {
        if (s[i] == 'V') {
            a[i] = 0;
        } else if (s[i] == 'K') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
    }
    forn(i, n) ++c[a[i]];
    forn(i, 77) forn(j, 77) forn(k, 77) forn(t, 3) {
        d[i][j][k][t] = INF;
    }
    forn(i, n) {
        if (a[i] == 0) {
            upd(d[1][0][0][0], i);
        } else if (a[i] == 1) {
            upd(d[0][1][0][1], i);
        } else {
            upd(d[0][0][1][2], i);
        }
    }
    forn(i, c[0] + 1) forn(j, c[1] + 1) forn(k, c[2] + 1) forn(t, 3) if (d[i][j][k][t] != INF) {
        if (i < c[0]) {
            int f[3] = {i, j, k};
            int pos = 0;
            while (f[0] >= 0) {
                --f[a[pos]];
                ++pos;
            }
            upd(d[i + 1][j][k][0], d[i][j][k][t] - min(0, f[1]) - min(0, f[2]));
        }
        if (j < c[1] && t != 0) {
            int f[3] = {i, j, k};
            int pos = 0;
            while (f[1] >= 0) {
                --f[a[pos]];
                ++pos;
            }
            upd(d[i][j + 1][k][1], d[i][j][k][t] - min(0, f[0]) - min(0, f[2]));
        }
        if (k < c[2]) {
            int f[3] = {i, j, k};
            int pos = 0;
            while (f[2] >= 0) {
                --f[a[pos]];
                ++pos;
            }
            upd(d[i][j][k + 1][2], d[i][j][k][t] - min(0, f[0]) - min(0, f[1]));
        }
    }
    cout << min({d[c[0]][c[1]][c[2]][0], d[c[0]][c[1]][c[2]][1], d[c[0]][c[1]][c[2]][2]}) << endl;
    return 0;
}