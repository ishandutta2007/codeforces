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
const int MAXN = 100000;
using ll = long long;


int n, m, k;
vector<int> g[MAXN];
pair<int, ll> kek[MAXN];


void dfs(int u, multiset<pair<int, ll> > &s) {
    for (auto h: g[u]) {
        multiset<pair<int, ll> > s1;
        dfs(h, s1);
        if (sz(s) < sz(s1)) {
            swap(s, s1);
        }
        for (auto x: s1) {
            s.insert(x);
        }
    }
    if (kek[u].first == 0) {
        return;
    }
    auto it = s.upper_bound(mp(kek[u].first, (ll)1e18));
    ll cur = 0;
    vector<pair<int, ll> > st;
    int last = -1;
    while (it != s.end()) {
        cur += it->second;
        last = it->first;
        st.pb(*it);
        if (cur >= kek[u].second) {
            break;
        }
        it++;
    }
    for (auto x: st) {
        s.erase(s.find(x));
    } 
    s.insert({kek[u].first, kek[u].second});
    if (last != -1 && cur > kek[u].second) {
        s.insert({last, cur - kek[u].second});
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n >> m >> k;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    }
    for (int i = 0; i < n; i++) {
        kek[i] = {0, 0};
    }
    for (int i = 0; i < m; i++) {
        int v, d, w;
        cin >> v >> d >> w;
        v--;
        kek[v] = {d, w};
    }
    multiset<pair<int, ll> > s;
    dfs(0, s);
    ll ans = 0;
    for (auto x: s) {
        ans += x.second;
    }
    cout << ans << '\n';
    return 0; 
}