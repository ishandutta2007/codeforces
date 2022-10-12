#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T> inline T sum(vector<T> X)
{ T r = 0; for (const auto& x : X) r += x; return r; }

template<typename T> inline T min(vector<T> X)
{ T r = *X.begin(); for (const auto& x : X) r = min(r, x); return r; }

template<typename T> inline T max(vector<T> X)
{ T r = *X.begin(); for (const auto& x : X) r = max(r, x); return r; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n); for (auto& x : a) cin >> x;
        for (int i = 0; i < n; i++) {
            a[i] += i;
            a[i] = ((a[i]%n)+n)%n;
        }
        bool v = 1;
        sort(all(a));
        debug(a);
        for (int i = 1; i < n; i++)
            v &= a[i] == a[i-1]+1;
        cout << (v ? "YES" : "NO") << "\n";
    }
}