#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 200005;
const ll mod = 998244353;
int a[maxn], b[maxn], p[maxn];
map<int, int> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]] = max(f[a[i]], i);
    }
    for (int i = n-1; i >= 0; i--)
        p[i] = min(i == n-1 ? inf : p[i+1], a[i]);
    ll out = 1;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        int l = lower_bound(p, p+n, b[i])-p;
        int r = f.count(b[i]) ? (i == 0 ? 0 : f[b[i]]) : -1;
        out = out*(r-l+1)%mod;
        if (l > r) out = 0;
    }
    cout << out << "\n";
}