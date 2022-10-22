#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2001;
const int INF = 2e9 + 7;
int n, k;
int a[N];
int dp[N];
bool check(int l, int r, int m) {
    if (a[l] <= a[r]) {
        return a[r] <= a[l] + m * (r - l);
    }   
    else {
        return a[r] >= a[l] - m * (r - l);
    }
}   
bool check(int m) {
    for (int i = 0; i < N; ++i) dp[i] = -INF;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (check(j, i, m)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }   
        }   
        if (dp[i] >= n - k) return 1;
    }   
    return 0;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    if (k == n) {
        cout << "0\n";
        exit(0);
    }   
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }   
    cout << r << '\n';
}