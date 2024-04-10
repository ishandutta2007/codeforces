#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
const int N = 2007;
int n, a[N], cnt[N];
bool check() {
    for (int i = 0; i < N; ++i) if (cnt[i] > 1) return 0;
    return 1;
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    vector <int> c;
    cin >> n; for (int i = 0; i < n; ++i) { cin >> a[i]; c.app(a[i]); }
    sort(all(c)); c.resize(unique(all(c)) - c.begin());
    for (int i = 0; i < n; ++i) { a[i] = lower_bound(all(c), a[i]) - c.begin(); ++cnt[a[i]]; }
    int l = n - 1;
    while (!check()) { --cnt[a[l]]; --l; }
    int ans = n;
    int r = n;
    for (int i = l; i >= -1; --i) {
        while (i < r - 1 && !cnt[a[r - 1]]) {
            cnt[a[r - 1]] = 1; --r;
        }
        ans = min(ans, r - i - 1);
        if (i >= 0) --cnt[a[i]];
    }
    cout << ans << '\n';
}