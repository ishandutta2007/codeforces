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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 1000;




int a[MAXN], b[MAXN], c[MAXN];
int e[MAXN][MAXN];
bool good[MAXN];


void gauss(vector < vector<int> > a, vector<int> & ans) {
    if (a.empty()) {
        return;
    }
    int n = sz(a);
    int m = sz(a[0]) - 1;
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++) {
            if (a[i][col] > a[sel][col]) {
                sel = i;
            }
        }

        if (a[sel][col] == 0) {
            continue;
        }
        for (int i = col; i <= m; i++) {
            swap(a[sel][i], a[row][i]);
        }
        for (int i = 0; i < n; i++) {
            if (i != row) {
                int c = (a[i][col] * a[row][col]) % 3;
                for (int j = col; j <= m; j++) {
                    a[i][j] -= a[row][j] * c;
                    a[i][j] %= 3;
                    if (a[i][j] < 0) {
                        a[i][j] += 3;
                    }
                }
            }
        }
        row++;
    }

    memset(good, 0, sizeof(good));
    ans.resize(m, 0);
    for (int i = sz(a) - 1; i >= 0; i--) {
        int res = a[i].back();
        vector<int> st;
        for (int j = 0; j < sz(a[i]) - 1; j++) {
            if (a[i][j]) {
                if (good[j]) {
                    res = (res - ans[j] * a[i][j]) % 3;
                    if (res < 0) {
                        res += 3;
                    }
                } else {
                    st.pb(j);
                }
            }
        }
        if (st.empty()) {
            continue;
        }
        if (sz(st) > 1) {
            for (int i = 0; i < sz(st) - 1; i++) {
                good[st[i]] = true;
            }
        }
        good[st.back()] = true;
        ans[st.back()] = (res * a[i][st.back()]) % 3;
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        e[a[i]][b[i]] = i;
        e[b[i]][a[i]] = i;
    }
    vector<vector<int> > a;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (e[i][j] && e[i][k] && e[j][k]) {
                    vector<int> ids;
                    ids.pb(e[i][j]);
                    ids.pb(e[i][k]);
                    ids.pb(e[j][k]);
                    vector<int> fx;
                    int rem = 0;
                    for (auto x: ids) {
                        if (c[x] == -1) {
                            fx.pb(x);
                        } else {
                            rem = (rem - c[x] + 3) % 3;
                        }
                    }
                    if (fx.empty()) {
                        if (rem != 0) {
                            cout << -1 << endl;
                            return;
                        }
                        continue;
                    }
                    vector<int> b(m + 1, 0);
                    for (auto z: fx) {
                        b[z - 1] = 1;
                    }
                    b[m] = rem;
                    a.pb(b);
                }
            }
        }
    }
    vector<int> res;
    res.resize(m, 0);
    gauss(a, res);
    for (int i = 1; i <= m; i++) {
        if (c[i] != -1) {
            res[i - 1] = c[i];
        }
    }
    for (int j = 0; j < sz(a); j++) {
        int rese = 0;
        for (int k = 0; k < sz(a[j]) - 1; k++) {
            rese += a[j][k] * res[k];
        }
        rese %= 3;
        if (rese != a[j].back()) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (res[i] == 0) {
            res[i] = 3;
        }
        cout << res[i] << ' ';
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}