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
const int MAXN = 300229;


int n, k;
vector<int> g[MAXN];
int deep[MAXN];
int prs[MAXN];
int cnt[MAXN];
int fk[MAXN];


void dfs(int u, int pr = -1) {
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        fk[u]++;
        deep[h] = deep[u] + 1;
        prs[h] = u;
        dfs(h, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> k;
    for (int i = 0 ; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    set<pair<ll, int> > s;
    for (int i = 0; i < n; i++) {
        if (fk[i] == 0) {
            s.insert({deep[i], i});
        }
    }
    ll ans = 0;
    for (int it = 0; it < k; it++) {
        auto x = *s.rbegin();
        s.erase(x);
        ans += x.first;
        int u = x.second;
        if (u != 0) {
            fk[prs[u]]--;
            cnt[prs[u]] += cnt[u] + 1;
            if (fk[prs[u]] == 0) {
                s.insert({deep[prs[u]] - cnt[prs[u]], prs[u]});
            }
        }
    }
    cout << ans << '\n';
}