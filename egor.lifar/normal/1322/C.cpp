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
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 500228;



ll gcd(ll a, ll b) {
    return (a == 0 ? b: gcd(b % a, a));
}

int n, m;
vector<int> g[MAXN];
ll c[MAXN];
vector<int> rg[MAXN];
map<vector<int>, ll> kek;


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        rg[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        rg[b].pb(a);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        for (auto x: g[i]) {
            sum += c[x];
        }
        ans = gcd(ans, sum);
    }
    kek.clear();
    for (int i = 1; i <= n; i++) {
        if (rg[i].empty()) {
            continue;
        }
        sort(all(rg[i]));
        kek[rg[i]] += c[i];
    }
    for (auto x: kek) {
        ans = gcd(ans, x.second);
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}