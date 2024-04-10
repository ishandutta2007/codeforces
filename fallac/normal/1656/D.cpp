/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

unsigned long int rho(unsigned long int n)
{
    if (n == 1) return n;
    if (n % 2 == 0) return 2;

    unsigned long int y = rand() % n;
    unsigned long int x;
    unsigned long long int ys = y;
    unsigned long int c;
    do
        c = rand() % n;
    while (c == 0 || c == n - 2);
    unsigned long int m = 1000;
    unsigned long int d = 1;
    unsigned long int q = 1;
    unsigned long int r = 1;
    while (d == 1)
    {
        x = y;
        for (int i = 0; i < r; i++)
        {
            y = y * y % n;
            y += c;
            if (y < c)
                y += (std::numeric_limits<unsigned long>::max() - n) + 1;
            y %= n;
        }
        int j = 0;
        while (j < r && d == 1)
        {
            ys = y;
            for (int i = 0; i < m && i < (r - j); i++)
            {
                y = y * y % n;
                y += c;
                if (y < c)
                    y += (std::numeric_limits<unsigned long>::max() - n) + 1;
                y %= n;
                q *= ((x > y) ? x - y : y - x) % n;
            }
            d = gcd(q, n);
            j += m;
        }
        r *= 2;
    }
    if (d == n)
    {
        do
        {
            ys = ys * ys % n;
            ys += c;
            if (ys < c)
                ys += (std::numeric_limits<unsigned long>::max() - n) + 1;
            ys %= n;
            d = gcd(((x > ys) ? x - ys : ys - x), n);
        } while (d == 1);
    }
    return d;
}

void solve() {
	ll N;
	cin >> N;
	ll cnt = 0;
	ll M = N;
	ll mul = 2;
	while (M % 2 == 0) M /= 2, cnt++, mul *= 2;
	if (M < mul + 1) {
		ll i;
        ll mn = M;
        if (mn == 1) {
            cout << -1 << ln;
            return;
        }
		if (N / mn >= (mn - 1) / 2 + 1) cout << mn << ln;
		else cout << -1 << ln;
	}
	else cout << mul << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}