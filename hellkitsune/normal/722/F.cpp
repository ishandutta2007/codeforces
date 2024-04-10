#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> a[100000];
vector<int> where[100000];
vector<vector<int> > pos[100000];
bool was[100000] = {};
int ans[100000] = {};
int gc[41][41];

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int lcnt[41], c[41][40];
int rres[41][41];

int solve(int num, int from, int to) {
    memset(lcnt, 0, sizeof lcnt);
    memset(c, 0, sizeof c);
    vector<int> &where = ::where[num];
    vector<vector<int> > &pos = ::pos[num];
    int res = 1;
    int le = from;
    for (int i = from; i < to; ++i) {
        if (res >= to - le) {
            break;
        }
        int sz = (int)a[where[i]].size();
        while (le < i) {
            memset(rres, -1, sizeof rres);
            bool ok = false;
            for (int j : pos[i]) {
                bool flag = true;
                for (int len = 1; len <= 40; ++len) if (lcnt[len]) {
                    int g = gc[sz][len];
                    int jj = j % g;
                    if (rres[jj][len] == -1) {
                        int sum = 0;
                        for (int k = jj; k < len; k += g) {
                            sum += c[len][k];
                        }
                        rres[jj][len] = (sum == lcnt[len]);
                    }
                    if (rres[jj][len] == 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
            int ssz = (int)a[where[le]].size();
            --lcnt[ssz];
            for (int x : pos[le]) {
                --c[ssz][x];
            }
            ++le;
        }
        res = max(res, i - le + 1);
        if (res >= to - le) {
            break;
        }
        if (i < to - 1) {
            ++lcnt[sz];
            for (int x : pos[i]) {
                ++c[sz][x];
            }
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    forn(i, 41) forn(j, 41) {
        gc[i][j] = gcd(i, j);
    }
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int cnt;
        scanf("%d", &cnt);
        a[i].resize(cnt);
        forn(j, cnt) scanf("%d", &a[i][j]), --a[i][j];
    }
    forn(i, n) {
        forn(j, a[i].size()) {
            if (!was[a[i][j]]) {
                where[a[i][j]].pb(i);
                pos[a[i][j]].pb(vector<int>());
            }
            pos[a[i][j]].back().pb(j);
        }
        for (int x : a[i]) {
            was[x] = false;
        }
    }
    forn(i, m) {
        for (int beg = 0; beg < (int)where[i].size(); ) {
            int end = beg + 1;
            while (end < (int)where[i].size() && where[i][end] == where[i][beg] + end - beg) {
                ++end;
            }
            ans[i] = max(ans[i], solve(i, beg, end));
            beg = end;
        }
    }
    forn(i, m) {
        printf("%d\n", ans[i]);
    }
    return 0;
}