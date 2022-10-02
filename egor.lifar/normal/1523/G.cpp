/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

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
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}




struct fenw
{
    vector<int> f;
    int lim;
    void init(int n) {
        lim = n;
        f.resize(n + 1);
        for (auto &x: f) {
            x = 1e9;
        }
    }
    void inc(int i, int val) {
        for (; i <= lim; i |= (i + 1)) {
            chkmin(f[i], val);
        }
    }
    int get(int i) {
        int ans = 1e9;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            chkmin(ans, f[i]);
        }
        return ans;
    }
};

const int MAXN = 100228;

int n, m;
int l[MAXN], r[MAXN];
int res[MAXN];
int ss = 1;
vector<pair<int, int> > z[MAXN * 4];
fenw k[MAXN * 4];


void add(int v, int vl, int vr, int l, int r, int val, int id) {
    if (vl > r || vr < l) {
        return;
    }
    if (l <= vl && vr <= r) {
        z[v].pb(mp(val, id));
        return;
    }
    z[v].pb(mp(val, id));
    add(v * 2, vl, (vl + vr) / 2, l, r, val, id);
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, val, id);
}


void add1(int id) {
    int ll = l[id];
    int rr = r[id];
    add(1, 1, ss, ll, ll, rr, id);
}


void add1(int v, int vl, int vr, int l, int r, int val, int id) {
    if (vl > r || vr < l) {
        return;
    }
    if (l <= vl && vr <= r) {
        int pos = lower_bound(all(z[v]), mp(val, id)) - z[v].begin();
        k[v].inc(pos, id);
        return;
    }
     int pos = lower_bound(all(z[v]), mp(val, id)) - z[v].begin();
        k[v].inc(pos, id);
    add1(v * 2, vl, (vl + vr) / 2, l, r, val, id);
    add1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, val, id);
}


void add(int id) {
    int ll = l[id];
    int rr = r[id];
    add1(1, 1, ss, ll, ll, rr, id);
}


int get(int v, int vl, int vr, int l, int r, int r1) {
    if (vl > r || vr < l) {
        return 1e9;
    }
    if (l <= vl && vr <= r) {
         int pos = lower_bound(all(z[v]), mp(r1 + 1, 0)) - z[v].begin();
        return k[v].get(pos - 1);
    }
    return min(get(v * 2, vl, (vl + vr) / 2, l, r, r1), get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, r1));
}   


int find(int l, int r) {
    return get(1, 1, ss, l, n, r);
}   


int ans = 0;


void rofl(int curl, int curr) {
    if (curl > curr) {
        return;
    }
    int t = find(curl, curr);

    if (t > m) {
        return;
    }
    assert(curl <= l[t] &&  r[t] <= curr);
    ans+= r[t] - l[t] + 1;
    rofl(curl, l[t] - 1);
    rofl(r[t] + 1, curr);
}   

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
    }
    while (ss < n) {
        ss <<= 1;
    }
    vector<pair<int, int> > st;
    for (int i = 0; i < m; i++) {
        st.pb(mp(r[i] - l[i] + 1, i));
    }
    sort(all(st));
    reverse(all(st));
    vector<int> order;
    for (int i = 0; i < m; i++) {
        order.pb(st[i].second);
    }
    for (int i = 0; i < m; i++) {
        add1(order[i]);
    }
    for (int i = 1; i < 2 * ss; i++) {
        sort(all(z[i]));
        k[i].init(sz(z[i]));
    }
    int uk = 0;
    for (int len = n; len >= 1; len--) {
        while (uk < m && r[order[uk]] - l[order[uk]] + 1 >= len) {
            add(order[uk]);
            uk++;
        }
        ans = 0;
        rofl(1, n);
        res[len] = ans;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}