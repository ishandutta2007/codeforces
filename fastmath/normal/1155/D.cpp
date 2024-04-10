#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
int n, x;
int a[N];
int solve1() {
    int mn = 0;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        mn = min(mn, sum);
        ans = max(ans, sum - mn);
    }   
    return ans * x;
}   
int solve2(int l, int r) {
    if (l == r) {
        return max(a[l], a[l] * -x);
    }   
    int m = (l + r) >> 1;
    vector <pair <int, int> > vl, vr;
    int sum, mn;

    sum = 0; mn = 0;
    for (int i = m; i >= l; --i) {
        sum += a[i];
        mn = min(mn, sum);
        vl.push_back({sum, mn});
    }   

    sum = 0; mn = 0;
    for (int i = m + 1; i <= r; ++i) {
        sum += a[i];
        mn = min(mn, sum);
        vr.push_back({sum, mn});
    }   

    int ans = max(solve2(l, m), solve2(m + 1, r));

    int maxl, maxr;

    maxl = 0;
    for (auto e : vl) maxl = max(maxl, e.first - e.second * (x + 1));
    maxr = 0;
    for (auto e : vr) maxr = max(maxr, e.first - e.second * (x + 1));

    ans = max(ans, maxl + maxr);

    maxl = 0;
    for (auto e : vl) maxl = max(maxl, e.first);
    maxr = 0;
    for (auto e : vr) maxr = max(maxr, e.first);    
    
    int mx, minsum;
    sum = 0; mx = 0, minsum = 0;
    for (int i = m; i >= l; --i) {
        sum += a[i];
        mx = max(mx, sum);
        minsum = min(minsum, sum - mx);
        ans = max(ans, sum - minsum * (x + 1) + maxr);
    }   

    sum = 0; mx = 0, minsum = 0;
    for (int i = m + 1; i <= r; ++i) {
        sum += a[i];
        mx = max(mx, sum);
        minsum = min(minsum, sum - mx);
        ans = max(ans, sum - minsum * (x + 1) + maxl);
    }   

    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (x > 0) {
        cout << solve1() << '\n';
    }   
    else {
        x = -x;
        cout << solve2(0, n - 1) << '\n';
    }   
}