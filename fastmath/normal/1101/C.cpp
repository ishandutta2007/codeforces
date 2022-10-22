#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
pair <int, int> a[N];
int per[N];
int ans[N];
bool comp(int i, int j) {
    return a[i] < a[j];
}   
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }   
    for (int i = 0; i < n; ++i) per[i] = i;
    sort(per, per + n, comp);
    int mx = -1;
    for (int ii = 0; ii < n - 1; ++ii) {
        mx = max(mx, a[per[ii]].second);
        if (mx < a[per[ii + 1]].first) {
            for (int i = 0; i <= ii; ++i) {
                ans[per[i]] = 1;
            }   
            for (int i = ii + 1; i < n; ++i) {
                ans[per[i]] = 2;
            }   
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << ' ';
            }   
            cout << '\n';
            return;
        }   
    }   
    cout << "-1\n";
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int q; cin >> q; for (int i = 0; i < q; ++i) solve();
}