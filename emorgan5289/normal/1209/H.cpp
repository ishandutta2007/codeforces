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

const int N = 5e5+5;
ld a[N], s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, L; cin >> k >> L;
    int p = 0, n = 0;
    while (k--) {
        int x, y; cin >> x >> y;
        ld z; cin >> z;
        if (x != p)
            a[n] = x-p, s[n++] = 0;
        a[n] = y-x, s[n++] = z;
        p = y;
    }
    a[n] = L-p, s[n++] = 0;
    ld ans = 0;
    multimap<ld, ld> f;
    for (int i = n-1; i >= 0; i--) {
        ans += a[i]/(s[i]+2);
        if (s[i] == 0) {
            f.insert({-1, a[i]/2});
        } else {
            ld w = a[i]/(s[i]+2)+a[i]/s[i];
            ld m = -1/(s[i]+1);
            f.insert({m, w});
            ld g = max(ld(0), a[i]/s[i]);
            while (g >= f.begin()->second) {
                g -= f.begin()->second;
                f.erase(f.begin());
            }
            f.begin()->second -= g;
        }
    }
    for (auto& [m, w] : f)
        ans -= m*w;
    cout << setprecision(25) << ans << "\n";
}