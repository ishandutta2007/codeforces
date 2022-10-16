#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const ll mod = 1e9 + 7;

ll modpow(ll x, ll y) {
    ll ans = 1;
    x %= mod;
    while (y > 0) {
        if (y % 2 == 1) ans = (ans * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    if (k == -1 && (n % 2 != m % 2)) {
        puts("0");
        return 0;
    }
    cout << modpow(modpow(2, n-1), m-1);
    return 0;
}