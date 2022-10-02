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



const int MAXN = 200228;


int n, k;
int fact[MAXN];
int rfact[MAXN];


int getc(int a, int b) {
    return mul(fact[a], mul(rfact[b], rfact[a - b]));
}


int getgood(int x) {
    if (x > n) {
        return 0;
    }
    ll f = n - x - (ll)(x - 1) * (k - 1);
    if (f < 0) {
        return 0;
    }
    int need = x + 1;
    return mul(fact[x], getc(f + need - 1, need - 1));
}


void solve() {
    cin >> n >> k;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int t = getgood(i - 1);
        int t1 = getgood(i);
        t = mul(t, n - i + 1);
        t = sum(t, Mod - t1);
        int p = mul(rfact[n], fact[n - i]);
        ans = sum(ans, mul(i, mul(t, p)));
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    rfact[MAXN - 1] = powm(fact[MAXN - 1], Mod - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        rfact[i] = mul(rfact[i + 1], i + 1);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}