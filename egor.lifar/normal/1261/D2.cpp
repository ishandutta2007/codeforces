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
const int MAXN = 400228;
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) {
            c = mul(c, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return c;
}

int n, k;
int a[MAXN];
int cnt0[MAXN], cnt1[MAXN], cnt2[MAXN];
int fact[MAXN];
//0, 1, -1


int getc(int a, int b) {
    return mul(fact[a], powm(mul(fact[b], fact[a - b]), Mod - 2));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
  	cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    int res = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[(i + 1) % n]) {
            res = mul(res, k);
        } else {
            cnt++;
        }
    }   
    if (cnt == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int cur = 1;
    int ans = 0;
    for (int g = 0; g < cnt; g++) {
        int d = cnt - g;
        int kek = powm(2, d - 1);
        if (d % 2 == 0) {
            kek = sum(kek, Mod - mul(getc(d, d / 2), powm(2, Mod - 2)));
        }
        ans = sum(ans, mul(mul(cur, kek), getc(cnt, d)));
        cur = mul(cur, k - 2);
    }
    cout << mul(ans, res) << '\n';
}