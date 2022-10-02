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
 
template<class T1, class T2> inline int chkmin(T1 &x, const T2 &y) {
    if (x > y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}
 
template<class T1, class T2> inline int chkmax(T1 &x, const T2 &y) {
    if (x < y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}
 
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
 
template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}
 
 
template<class T> void output(const T &x, ostream &out = cerr) {
    output(x.begin(), x.end(), out);
}
 
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
}
const int MAXN = 500228;



int n;
vector<int> g[MAXN];
int sz[MAXN];
long long cntbad[MAXN];
long long res = 1e18;
long long opt[MAXN];

void dfs(int u, int pr = -1) {
    sz[u] = 1;
    for (auto h: g[u]) {
        if (h != pr) {
            dfs(h, u);
            sz[u] += sz[h];
        }
    }
}



long long get(int val) {
    return (1LL * val * (val - 1)) / 2;
}

void calc(int u, int pr = -1) {
    long long sum = 0;
    for (auto h: g[u]) {
        if (h != pr) {
            sum += get(sz[h] + 1);
        }
    }
    opt[u] = cntbad[u] + get(sz[u]);
    long long m1 = 1e18;
    long long m2 = 1e18;
    vector<pair<int, long long> > kek, kek1 ;
    for (auto h: g[u]) {
        if (h != pr) {
            cntbad[h] = cntbad[u] + get(sz[u] - sz[h]);
            //cout << cntbad[h] << endl;
            calc(h, u);
            chkmin(opt[u], opt[h]);
            long long val = opt[h] - (cntbad[u] + get(sz[u] - sz[h]));
           // cout << val << ' ' << h << endl;
           // cout << sz[h] << endl;
            chkmin(res, val+ get(n - sz[h]));
            kek.pb({sz[h], val});
        }
    }
    sort(all(kek));
    reverse(all(kek));
    for (auto x: kek) {
        if (kek1.empty()) {
            kek1.pb(x);
        } else {
            if (sz(kek1) >= 2 && kek1.back().first == x.first && kek1[sz(kek1) - 2].first == x.first) {
                auto y = kek1.back();
                kek1.pop_back();
                kek1.pop_back();
                kek1.pb(y);
                kek1.pb(x);
            }  else {
                kek1.pb(x);
            }
        }
    }
    for (int i = 0; i < sz(kek1); i++) {
        for (int j = i + 1; j < sz(kek1); j++) {
       //     cout << kek1[i].first << ' ' << kek1[j].first << endl;
            chkmin(res, get(n - kek1[i].first - kek1[j].first) + kek1[i].second + kek1[j].second);
        }
    }
}

 
int main() {
    fast_io();
  //  read("input");
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    calc(1);
    long long ans = 1LL * n * (n - 1) - res;
    cout << ans << endl;
    return 0; 
}