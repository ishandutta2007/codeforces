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
        vector<string> s(k);
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            s[i%k] += c;
        }
        vector<ll> a(k, 0), b(k, 0);
        ll x = 0;
        for (int i = 0; i < k; i++) {
            int m = s[i].size();
            for (int j = 0; j < m; j++)
                if (s[i][j] == '1') a[i]++;
            x += a[i];
            ll r = 0, q = 0, o = 0;
            for (int j = 0; j < m; j++) {
                r += (s[i][j] == '1' ? 1 : -1);
                q = min(q, r);
                o = max(o, r-q);
            }
            b[i] = a[i]-o;
        }
        // debug(s, a, b);
        ll out = inf_ll;
        for (int i = 0; i < k; i++)
            out = min(out, x-a[i]+b[i]);
        cout << out << "\n";
    }
}