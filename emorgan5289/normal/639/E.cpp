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

const int N = 2e5+5;
array<ll, 4> a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ld T = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i][0];
    for (int i = 0; i < n; i++)
        cin >> a[i][1], T += a[i][1];
    sort(a, a+n, [](auto x, auto y){return x[0]*y[1] > y[0]*x[1];});
    for (int i = 0; i < n; i++)
        a[i][2] = (i == 0 ? 0 : a[i-1][2])+a[i][1];
    a[n-1][3] = a[n-1][2];
    for (int i = n-2; i >= 0; i--)
        a[i][3] = a[i][0]*a[i+1][1] == a[i+1][0]*a[i][1] ? a[i+1][3] : a[i][2];
    for (int i = 0; i < n; i++) a[i][2] -= a[i][1];
    for (int i = 1; i < n; i++)
        a[i][2] = a[i][0]*a[i-1][1] == a[i-1][0]*a[i][1] ? a[i-1][2] : a[i][2];
    for (int i = 0; i < n; i++) a[i][2] += a[i][1];
    sort(a, a+n, [](auto x, auto y){return x[0] > y[0];});
    ld l = 0, r = 1;
    while (r-l > 1e-9) {
        ld m = inf_ll, c = (l+r)/2;
        int i = 0;
        bool v = 1;
        for (int j = 0; j < n; j++) {
            while (i < n && a[i][0] != a[j][0])
                m = min(m, a[i][0]*(1-c*a[i][3]/T)), i++;
            v = v && m > a[j][0]*(1-c*a[j][2]/T);
        }
        if (v) l = c;
        else r = c;
    }
    cout << setprecision(18) << l << "\n";
}