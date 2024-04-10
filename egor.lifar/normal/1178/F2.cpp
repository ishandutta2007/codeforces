/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 1025;
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b) % Mod;
}


int mul(int a, int b) {
    return (1LL * a * b) % Mod;
}


int n, m;
int c[1000228];
int pos[MAXN];
int dp[MAXN][MAXN];
int cc[1000228];
vector<int> who[MAXN];
int f[1000228];
int posl[MAXN], posr[MAXN];


void upd(int i, int val) {
    for (int j = i; j < m; j |= (j + 1)) {
        f[j]+= val;
    }
}


int get(int i) {
    int res = 0;
    for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
        res += f[j];
    }
    return res;
}


int getsum(int l, int r) {
    return get(r) - get(l - 1);
}


vector<pair<int, int> > gt[MAXN];
vector<int> ft[MAXN], ft1[MAXN];
int bad[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        pos[c[i]] = i;
        cc[i] = c[i];
        who[c[i]].pb(i);
        upd(i, 1);
    }
    vector<pair<int, int> > st;
    for (int i = n; i >= 1; i--) {
        sort(all(who[i]));
        for (auto z: who[i]) {
            upd(z, -1);
        }
        int fl = who[i][0];
        int fr = who[i].back();
        if (getsum(fl, fr)) {
            cout << 0 << endl;
            exit(0);
        }
        st.pb({fl, i});
        st.pb({fr, i});
    }
    sort(all(st));
    st.resize(distance(st.begin(), unique(all(st))));
    m = sz(st);
    for (int i = 0; i < m; i++) {
        cc[i] = st[i].second;
        posr[st[i].second] = i;
    }
    for (int i = m - 1; i >= 0; i--) {
        posl[st[i].second] = i;
    }
    for (int i = 1; i <= n; i++) {
        ft[posl[i]].pb(i);
        ft1[posr[i]].pb(i);
    }
    set<int> curs;
    for (int i = 0; i < m; i++) {
        for (auto x: ft[i]) {
            curs.insert(x);
        }
        for (auto x: ft1[i]) {
            curs.erase(x);
        }
        bad[i] = (curs.empty() ? 0: *curs.rbegin());
    }
   // cout << m << endl;
    for (int i = 1; i <= n; i++) {
        int last = -1;
      //  cout << posl[i] << ' ' << posr[i] << endl;
        for (auto x: who[i]) {
            if (last != -1) {
                int fl = last;
                int fr = x - 1;
                int fit = lower_bound(all(st), mp(fl, 0)) - st.begin();
                int fit1 = upper_bound(all(st), mp(fr, 1000000000)) - st.begin();
                fit1--;
                //cout << fit << ' ' << fit1 << endl;
                if (fit <= fit1) {
                    gt[i].pb({fit, fit1});
                }
            }
            last = x + 1;
        }
    }
    for (int j = m - 1; j >= 0; j--) {
        for (int k = j; k < m; k++) {
            int ress = 1e9;
            bool bad = false;
            for (int t = j; t <= k; t++) {
                if (posl[cc[t]] < j || posr[cc[t]] > k) {
                    bad = true;
                }
                chkmin(ress, cc[t]);
            }
            if (bad) {
                dp[j][k] = 0;
                continue;
            }
            if (j == k) {
                dp[j][k] = 1;
                continue;
            }
            int g = posl[ress];
            int g1 = posr[ress];
            if (g < j || g1 > k) {
                dp[j][k] = 0;
                continue;
            }
            if (j == g && g1 == k) {
                if (j + 1 == k) {
                    dp[j][k] = 1;
                } else {
                    dp[j][k] = 1;
                    for (auto z: gt[ress]) {
                        if (z.first > g && z.second < g1) {
                            dp[j][k] = mul(dp[j][k], dp[z.first][z.second]);
                        }
                    }
                }
                continue;
            }
            int res = 0;
            for (int f = g - 1; f >= j - 1; f--) {
                res = sum(res, mul((f < j ? 1: dp[j][f]), (f + 1 > g - 1 ? 1: dp[f + 1][g - 1])));
            }
            if (g == j) {
                res = 1;
            }
            int res1 = 0;
            for (int f = g1 + 1; f <= k + 1; f++) {
                res1 = sum(res1, mul((k < f ? 1: dp[f][k]), (g1 + 1 > f - 1 ? 1: dp[g1 + 1][f - 1])));
            }
            if (g1 == k) {
                res1 = 1;
            }
           // cout << res << ' ' << res1 << endl;
            dp[j][k] = mul(res, res1);
            for (auto z: gt[ress]) {
                if (z.first > g && z.second < g1) {
                   // cout << j << ' ' << k << ' ' << z.first << ' ' << z.second << endl;
                    dp[j][k] = mul(dp[j][k], dp[z.first][z.second]);
                }
            }
        }
    }
    cout << dp[0][m - 1] << '\n';
    return 0;
}