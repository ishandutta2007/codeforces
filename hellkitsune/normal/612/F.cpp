#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, s, m;
int a[2000];
vector<int> u;
vector<int> num[2000];
int nx[2000], pre[2000];
int d[2][2000], p[2][2000], h[2000];

inline int dist(int x, int y) {
    return min(abs(x - y), n - abs(x - y));
}

inline int distDir(int x, int y) {
    int res = y - x;
    if (res < 0) res += n;
    return res;
}

const int INF = 1e9;

vector<string> vans;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &s), --s;
    REP(i, n) scanf("%d", a + i);
    REP(i, n) u.pb(a[i]);
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    REP(i, n) a[i] = lower_bound(u.begin(), u.end(), a[i]) - u.begin();
    m = (int)u.size();
    REP(i, n) num[a[i]].pb(i);
    REP(i, m) {
        int sz = (int)num[i].size();
        REP(j, sz - 1) nx[num[i][j]] = num[i][j + 1];
        nx[num[i][sz - 1]] = num[i][0];
        REP(j, sz - 1) pre[num[i][j + 1]] = num[i][j];
        pre[num[i][0]] = num[i][sz - 1];
    }
    for (int x : num[0]) {
        d[0][x] = dist(s, x);
        p[0][x] = -1;
    }
    REP(i, m) REP(j, 2) if (i || j) {
        int sz = (int)num[i].size();
        if (j == 0) {
            vector<int> &a = num[i - 1];
            vector<int> &b = num[i];
            for (int x : b) d[0][x] = INF;
            for (int x : a) for (int y : b) {
                int ndist = d[1][x] + dist(x, y);
                if (d[0][y] > ndist) {
                    d[0][y] = ndist;
                    p[0][y] = x;
                }
            }
        } else {
            if (sz == 1) {
                d[1][num[i][0]] = d[0][num[i][0]];
                p[1][num[i][0]] = 0;
                continue;
            }
            REP(pp, sz) {
                int q = pp + 1;
                if (q == sz) q = 0;
                d[1][num[i][q]] = d[0][num[i][pp]] + distDir(num[i][q], num[i][pp]);
                p[1][num[i][q]] = 1;
                h[num[i][q]] = num[i][pp];
            }
            REP(pp, sz) {
                int q = pp - 1;
                if (q == -1) q = sz - 1;
                int val = d[0][num[i][pp]] + distDir(num[i][pp], num[i][q]);
                if (val < d[1][num[i][q]]) {
                    d[1][num[i][q]] = val;
                    p[1][num[i][q]] = -1;
                    h[num[i][q]] = num[i][pp];
                }
            }
        }
    }
    int ans = INF, pos = -1;
    REP(i, n) if (a[i] == m - 1 && d[1][i] < ans) {
        ans = d[1][i];
        pos = i;
    }
    printf("%d\n", ans);
    int f = 1;
    while (true) {
        if (f == 1) {
            if (p[1][pos] == 1) {
                int cnt = 0;
                int i = pos;
                while (true) {
                    if (++i == n) i = 0;
                    ++cnt;
                    if (a[i] == a[pos]) {
                        ostringstream oss;
                        oss << "-" << cnt;
                        vans.pb(oss.str());
                        cnt = 0;
                    }
                    if (i == h[pos]) break;
                }
                pos = h[pos];
            } else if (p[1][pos] == -1) {
                int cnt = 0;
                int i = pos;
                while (true) {
                    if (--i == -1) i = n - 1;
                    ++cnt;
                    if (a[i] == a[pos]) {
                        ostringstream oss;
                        oss << "+" << cnt;
                        vans.pb(oss.str());
                        cnt = 0;
                    }
                    if (i == h[pos]) break;
                }
                pos = h[pos];
            }
            f = 0;
        } else {
            int y = p[0][pos];
            if (y == -1) y = s;
            if (distDir(pos, y) < distDir(y, pos)) {
                ostringstream oss;
                oss << "-" << distDir(pos, y);
                vans.pb(oss.str());
            } else {
                ostringstream oss;
                oss << "+" << distDir(y, pos);
                vans.pb(oss.str());
            }
            if (p[0][pos] == -1) break;
            pos = y;
            f = 1;
        }
    }
    reverse(vans.begin(), vans.end());
    for (string x : vans) printf("%s\n", x.c_str());
    return 0;
}