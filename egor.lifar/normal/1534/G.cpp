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
const int Mod =  998244353;


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


void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll> > st;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        st.pb(mp(x + y, x - y));
    } 
    sort(all(st));
    priority_queue<ll, vector<ll>, less<ll>>  pa;
    priority_queue<ll, vector<ll>, greater<ll>>pb;
    ll ans = 0;
    pa.push(0); 
    pb.push(0);
    for (auto q: st) {
        auto y = q.first, x = q.second;
        ans += max(max(pa.top() - y - x, x - pb.top() - y), 0LL);
        if (!sz(pa) || pb.top() + y > x) {
            pa.push(x + y); 
            pa.push(x + y); 
            pb.push(pa.top() - 2 * y); 
            pa.pop();
        } else {
            pb.push(x - y); 
            pb.push(x - y); 
            pa.push(pb.top() + 2 * y); 
            pb.pop();
        }
    }
    ans /= 2;
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
   // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}