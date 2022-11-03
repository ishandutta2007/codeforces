#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

li s[N];

void solve() {
    int n, m;
    cin >> m >> n;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    sort(a.begin(), a.end());

    s[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        s[i] = s[i + 1] + a[i].f;
    }

    li ans = s[max(0, n - m)];

    for(int i = 0; i < n; i++) {
        li res = a[i].f;

        int j = (lower_bound(a.begin(), a.end(), make_pair(a[i].s, 0)) - a.begin());

        if(m <= n - j)
            continue;

        res += s[j];
        if(i >= j)
            res -= a[i].f;

        res += a[i].s * 1ll * (m - (n - j) - (i < j));

        ans = max(ans, res);
    }

    cout << ans << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}