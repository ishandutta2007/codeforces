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
const int Mod = 998244353;
const int MAXN = 200229;


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
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}


string s;
int n, q;
int b[2], w[2], f[2];
int st[MAXN];
int rst[MAXN];
int ans[4]; 
int fact[MAXN], rfact[MAXN];


int cnk(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    if (n == k || k == 0) {
        return 1;
    }
    return mul(fact[n], mul(rfact[n - k], rfact[k]));
}


void solve() {
    fact[0] = 1;
    st[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
        st[i] = mul(st[i - 1], 2);
    }
    rfact[MAXN - 1] = powm(fact[MAXN - 1], Mod - 2);
    rst[MAXN - 1] = powm(st[MAXN - 1], Mod - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        rfact[i] = mul(rfact[i + 1], i + 1);
        rst[i] = mul(rst[i + 1], 2);
    }
    cin >> n >> q >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w') {
            w[i & 1]++;
        } else if (s[i] == 'b') {
            b[i & 1]++;
        } else {
            f[i & 1]++;
        }
    }
    int have = f[0] + f[1];
    int bal = n / 2 - b[1] - w[0];
    int t = abs(bal) & 1;
    for (int i = t; i <= min(bal - 2, have); i += 2) {
        ans[0] = sum(ans[0], cnk(have, i));
    }
    for (int i = t; i <= min(bal - 2, have); i += 2) {
        ans[1] = sum(ans[1], cnk(have - 1, i - 1));
    }
    for (int i = bal + 2; i <= have; i += 2) {
        ans[3] = sum(ans[3], cnk(have - 1, i - 1));
    }
    for (int i = bal + 2; i <= have; i += 2) {
        ans[2] = sum(ans[2], cnk(have, i));
    }
    int res = sum(mul(ans[1], have), mul(ans[2], bal));
    res = sum(sum(mul(ans[0], bal), mul(ans[3], have)), Mod - res);
    res = mul(res, rst[have]);
    cout << res << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}