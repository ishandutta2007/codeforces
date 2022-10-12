#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

// returns (b^r)%m, runs in O(logr) time.
template<typename T>
T powmod(T b, T r, T m) {
    T out = 1;
    for (T t = 1; t <= r; t <<= 1) {
        if (r&t) out = (out*b)%m;
        b = (b*b)%m;
    }
    return out;
}

// returns a unique number b s.t. ab = 1 mod m
template<typename T>
T modinv(T a, T m) {
    T r = 1, k = m-2;
    while (k) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
        k >>= 1;
    }
    return r%m;
}

const ll mod = 998244353;
ll choose[5005][5005], powk[5001], nchoose[5001], inv[5001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, m, k; fin >> n >> m >> k;
    for (ll i = 0; i <= k; i++)
        for (ll j = 0; j <= i; j++)
            choose[i][j] = (j == 0 ? 1 : choose[i-1][j-1]+choose[i-1][j])%mod;
    for (ll i = 0; i <= k; i++)
        powk[i] = powmod(i, k, mod);
    for (ll i = 0; i <= k; i++)
        inv[i] = modinv(i, mod);
    for (ll i = 0; i <= k; i++) {
        nchoose[i] = 1;
        for (ll j = 0; j < i; j++) {
            nchoose[i] = nchoose[i]*(n-j)%mod;
            nchoose[i] = nchoose[i]*inv[j+1]%mod;
        }
    }
    ll d = modinv(m, mod);
    ll out = 0;
    for (ll x = 1; x <= k; x++) {
        ll row = 0;
        for (ll i = 0; i <= k; i++) {
            assert(x <= 5000 && i <= 5000);
            ll c = choose[x][i]*powk[x-i]%mod;
            if (i&1)
                row = (row+mod-c)%mod;
            else
                row = (row+c)%mod;
        }
        row = row*nchoose[x]%mod;
        row = row*powmod(d, x, mod)%mod;
        out = (out+row)%mod;
    }
    cout << out << "\n";
}