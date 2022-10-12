#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
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
        int n, k; cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(all(a), greater<int>());
        sort(all(b), greater<int>());
        debug(a, b);
        ll out = 0;
        for (int i = 0; i <= k; i++) {
            ll r = 0;
            for (int j = 0; j < n-i; j++)
                r += a[j];
            for (int j = 0; j < i; j++)
                r += b[j];
            out = max(out, r);
        }
        cout << out << "\n";
    }
}