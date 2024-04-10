#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

const int N = 4e5;
const int Inf = 1e9 + 7;
int mn[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < N; ++i) mn[i] = Inf;
    mn[0] = 0;
    int m, a, b;
    cin >> m >> a >> b;
    for (int i = 1; i < N; ++i) {
        if (i >= a && mn[i - a] != Inf) {
            mn[i] = i;
            vector <int> q;
            q.push_back(i);
            while (!q.empty()) {
                int x = q.back();
                q.pop_back();
                if (x >= b && mn[x - b] == Inf) {
                    mn[x - b] = i;
                    q.push_back(x - b);
                }
                if (x + a <= i && mn[x + a] == Inf) {
                    mn[x + a] = i;
                    q.push_back(x + a);
                }
            }
        }
    }
    ll ans = 0;
    int n = min(N, m + 1);
    for (int i = 0; i < n; ++i) {
        if (mn[i] <= m) ans += m - mn[i] + 1;
    }
    if (n != m) {
        int x = gcd(a, b);
        int low = ((n + x - 1) / x) * x;
        int up = (m / x) * x;
        int cnt = (up - low) / x + 1;
        if (low <= up) {
            ans += (ll)((m - low + 1) + (m - up + 1)) * cnt / 2;
        }
    }
    cout << ans << '\n';
}