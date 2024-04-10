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
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n); for (auto& x : a) cin >> x;
        vector<ll> f(2*k+10, 0), p(2*k+10, 0);
        for (int i = 0; i < n/2; i++) {
            f[a[i]+a[n-i-1]]++;
            int l = min(a[i], a[n-i-1])+1;
            int r = max(a[i], a[n-i-1])+k;
            p[l]++; p[r+1]--;
        }
        for (int i = 1; i < 2*k+10; i++)
            p[i] += p[i-1];
        ll m = inf_ll;
        // debug(p, f);
        for (int i = 0; i < 2*k+10; i++) {
            ll c = p[i]-f[i] + 2*(n/2-(p[i]));
            // debug(i, c);
            m = min(m, c);
        }
        // debug(f, p);
        cout << m << "\n";
    }
}