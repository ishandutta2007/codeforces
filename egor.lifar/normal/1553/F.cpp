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



const int MAXN = 300228;

int n;
int a[MAXN];
ll ans[MAXN];


struct fenw
{
    vector<ll> f;
    void init(int n) {
        f.resize(n + 1);
    }
    void inc(int i, ll val) {
        for (; i < sz(f); i|= (i + 1)) {
            f[i] += val;
        }
    }
    ll get(int i) {
        ll ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            ans += f[i];
        }
        return ans;
    }
} kek, kek1, kek2, kek3;



void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    kek.init(MAXN);
    kek1.init(MAXN);
    kek2.init(MAXN);
    kek3.init(MAXN);
    for (int i = 0; i < n; i++) {
        ans[i] += kek.get(a[i]) * a[i] - kek1.get(a[i]);
        for (int t = 0; t <= 300000; t += a[i]) {
            int l = t;
            int r = min(t + a[i], 300001);
            ll val = kek3.get(r - 1) - kek3.get(l);
            ans[i] += val - (kek2.get(r - 1) - kek2.get(l)) * t;
        }
        for (int t = 0; t <= 300000; t += a[i]) {
            //t, t + a[i] - 1
            int l = t;
            int r = min(t + a[i], 300001);
            kek.inc(l, 1);
            kek.inc(r, -1);
            kek1.inc(l, t);
            kek1.inc(r, -t);
        }
        kek2.inc(a[i], 1);
        kek3.inc(a[i], a[i]);
    }
    for (int i = 0; i < n; i++) {
        ans[i + 1] += ans[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
 //   cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}