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
        vector<int> a(n), p(n); for (auto& x : a) cin >> x;
        bool v = 0, u = 0, w = 1;
        for (int i = 0; i < n; i++) {
            v = v || a[i] == k;
            w = w && a[i] == k;
            p[i] = (a[i] >= k ? 1 : -1) + (i == 0 ? 0 : p[i-1]);
        }
        int m = inf;
        for (int i = 0; i < n; i++) {
            u |= p[i]-m > 0;
            m = min(m, i == 0 ? 0 : p[i-1]);
        }
        cout << (v && (u || w) ? "yes" : "no") << "\n";
    }
}