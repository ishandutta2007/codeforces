#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

ll b[1000005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, x; fin >> n;
    for (ll i = 0; i < n; i++) {
        fin >> x;
        b[i] = x + (i == 0 ? 0 : b[i-1]);
    }
    ll s = b[n-1], out = inf_ull;
    for (ll i = 2; i <= s; i++) {
        if (i*i > s) i = s;
        if (s%i == 0) {
            ll r = 0;
            for (ll j = 0; j < n; j++)
                r += min(b[j]%i, i-(b[j]%i));
            out = min(out, r);
            while (s%i == 0) s /= i;
        }
    }
    cout << (out == inf_ull ? -1 : out) << "\n";
}