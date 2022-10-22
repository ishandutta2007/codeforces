#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int a[N];
int r[N], pref[N];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    sort(a, a + n);
    for (int i = 0; i < n - 1; ++i) {
        r[i] = a[i + 1] - a[i] - 1;
    }   
    sort(r, r + n - 1);
    for (int i = 0; i < n - 1; ++i) {
        pref[i + 1] = pref[i] + r[i];
    }   
    if (n <= k) {
        cout << n << '\n';
    }   
    else {
        cout << n + pref[n - k] << '\n';
    }   
}