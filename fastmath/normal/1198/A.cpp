#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
const int N = 5e5 + 7;
int a[N], cnt[N], pref[N], post[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    vector <int> c;
    int n, I; cin >> n >> I; I *= 8; for (int i = 0; i < n; ++i) { cin >> a[i]; c.app(a[i]); }
    sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());
    int len = 1 << min(30ll, I / n);
    if (c.size() <= len) {
        cout << "0\n";
        exit(0);
    }   
    for (int i = 0; i < n; ++i) {
        int p = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        ++cnt[p];
    }   
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + cnt[i];
    }   
    for (int i = n - 1; i >= 0; --i) {
        post[i] = post[i + 1] + cnt[i];
    }   
    int ans = N;
    for (int i = 0; i + len - 1 < (int)c.size(); ++i) {
        ans = min(ans, pref[i] + post[i + len]);
    }   
    cout << ans << '\n';
}