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
const int MAXN = 300228;


int n, m;
vector<pair<int, int> > g[MAXN];
bool used[MAXN];
vector<int> sts, fk;

bool dfs(int u) {
    used[u] = true;
    int cnt = 0;
    bool was = false;
    for (auto h: g[u]) {
        if (!used[h.first]) {
            if (!dfs(h.first) && !was) {
                was = true;
                fk.pb(h.second);
            }
            cnt++;
        }
    }
    if (cnt == 0) {
        sts.pb(u);
    }
    return was;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        cin >> n >> m;
        for (int i = 0; i < 3 * n; i++) {
            g[i].clear();
            used[i] = false;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb({b, i + 1});
            g[b].pb({a, i + 1});
        }
        sts.clear();
        fk.clear();
        for (int i = 0; i < 3 * n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }
        if (sz(sts) >= n) {
            cout << "IndSet" << '\n';
            for (int i = 0; i < n; i++) {
                cout << sts[i] + 1 << ' ';
            }
            cout << '\n';
            continue;
        }
        cout << "Matching" << '\n';
        for (int i = 0; i < n; i++) {
            cout << fk[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}