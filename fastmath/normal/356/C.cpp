#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }   
    if (sum < 3 || sum == 5) {
        cout << "-1\n";
        exit(0);
    }   

    sort(a, a + n);
    int w = 0, h = 0, add = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 3) {
            w += 3 - a[i];
        }   
        else {
            add += a[i] - 3;
        }   
    }   
    int ans = INF;
    for (int i = 0; i < n && sum <= 4 * (n - i); ++i) {
        if (w <= h + add) {
            ans = min(ans, max(w, h));
        }   
        if (a[i] < 3) {
            w -= 3 - a[i];
        }   
        else {
            add -= a[i] - 3;
        }   
        h += a[i];
    }   
    cout << ans << '\n';
}