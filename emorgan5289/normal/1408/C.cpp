#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ld> a(n+2);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0, a[n+1] = k;
        n += 2;
        ld l = 0, r = k;
        while (r-l > 1e-6) {
            ld m = (l+r)/2;
            ld p = 0, t0 = 0, t1 = 0;
            for (int i = 1; i < n; i++) {
                if (a[i] > m) {
                    t0 += (m-p)/i;
                    break;
                } else
                    t0 += (a[i]-p)/i;
                p = a[i];
            }
            p = k;
            for (int i = 1; i < n; i++) {
                if (a[n-1-i] < m) {
                    t1 += (p-m)/i;
                    break;
                } else
                    t1 += (p-a[n-1-i])/i;
                p = a[n-1-i];
            }
            if (t0 > t1) {
                r = m;
            } else l = m;
            if (r-l < 1e-6) {
                cout << setprecision(25) << fixed << t0 << "\n";
                break;
            }
        }
    }
}