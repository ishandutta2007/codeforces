#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
pair <int, int> a[N];
bool comp(pair <int, int> a, pair <int, int> b) {
    return a.second - a.first < b.second - b.first;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);                                        
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + n, comp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i].first * i + a[i].second * (n - i - 1);
    }
    cout << ans << '\n';
}