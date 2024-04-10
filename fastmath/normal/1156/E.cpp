#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 7;
int n;
int a[N];
int l_link[N], r_link[N];

vector <int> pl[N], pr[N];

int solve(int l, int r) {
    if (l == r) {
        return 0;
    }   

    int m = (l + r) >> 1;
    int ans = solve(l, m) + solve(m + 1, r);

    for (int i = l; i <= m; ++i) pl[a[i]].push_back(i);
    for (int i = m + 1; i <= r; ++i) pr[a[i]].push_back(i);

    int c = m;
    for (int i = m; i >= l; --i) {
        if (a[i] >= a[c]) c = i;
        auto &v = pr[a[c] - a[i]];
        ans += lower_bound(v.begin(), v.end(), r_link[c]) - v.begin();
    }   


    c = m + 1;
    for (int i = m + 1; i <= r; ++i) {
        if (a[i] > a[c]) c = i;
        auto &v = pl[a[c] - a[i]];
        ans += v.size() - (upper_bound(v.begin(), v.end(), l_link[c]) - v.begin());
    }

    for (int i = l; i <= m; ++i) pl[a[i]].clear();
    for (int i = m + 1; i <= r; ++i) pr[a[i]].clear();

    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n; ++i) {
        l_link[i] = -1;
        r_link[i] = n;
    }   

    vector <int> s;
    for (int i = 0; i < n; ++i) {
        while (s.size() && a[s.back()] < a[i]) s.pop_back();
        if (s.size()) l_link[i] = s.back();
        s.push_back(i);
    }   
    s.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (s.size() && a[s.back()] < a[i]) s.pop_back();
        if (s.size()) r_link[i] = s.back();
        s.push_back(i);
    }   

    cout << solve(0, n - 1) << '\n';

}