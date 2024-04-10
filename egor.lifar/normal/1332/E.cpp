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
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int Mod = 998244353;



int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}

int mul(int a, int b) {
    return (ll)a * b % Mod;
}


ll powm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


struct kek
{
    ll cnt[2] = {0, 0};
};


kek operator *(kek a, kek b) {
    kek c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.cnt[(i + j) % 2] = sum(c.cnt[(i + j) % 2], mul(a.cnt[i], b.cnt[j]));
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    if (l == r) {
        cout << 1 << '\n';
        return 0;
    }
    if (n > m) {
        swap(n, m);
    }
    r -= l;
    r++;
    if (n % 2 == 0 || m % 2 == 0) {
        kek res;
        res.cnt[0] = 1;
        ll b = n * m;
        kek as;
        as.cnt[0] = r / 2;
        as.cnt[1] = (r + 1) / 2;
        while (b) {
            if (b & 1) {
                res = res * as;
            }
            as = as * as;
            b >>= 1;
        }
        cout << res.cnt[0] << '\n';
        return 0;
    }
    cout << powm(r, (ll)n * m) << '\n';
    return 0;
}