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

const int N = 1e5+5;
ll a[N], d[N], p[N];
array<ll, 2> b[N];
multiset<int, greater<>> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i][0];
    for (int i = 0; i < m; i++)
        cin >> b[i][1];
    sort(b, b+m);
    for (int i = 0; i < m; i++)
        p[i] = b[i][1];
    fill(d, d+m, -1);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b, b+m, array{a[i], inf_ll})-b;
        if (j > 0) d[j-1] = i;
    }
    for (int i = m-2; i >= 0; i--)
        d[i] = max(d[i], d[i+1]);
    int j = m-1;
    ll c = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        c += a[i];
        while (j >= 0 && d[j] < i) j--;
        while (j >= 0 && d[j] == i) {
            if (c < p[j] && !s.empty()) {
                auto it = s.begin();
                if (*it > p[j]) c += *it, s.erase(it), ans--;
            }
            if (c >= p[j])
                c -= p[j], ans++, s.insert(p[j]);
            debug(i, p[j], ans, c, s);
            j--;
        }
    }
    cout << ans << "\n";
}