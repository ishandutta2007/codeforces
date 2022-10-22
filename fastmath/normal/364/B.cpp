#include<bits/stdc++.h>
using namespace std;
const int N = 51;
const int V = 10001;
const int C = N * V;
int a[N];
bool dp[C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = C - 1; j >= a[i]; --j) {
            dp[j] |= dp[j - a[i]];
        }   
    }   
    vector <int> can;
    for (int i = 0; i < C; ++i) {
        if (dp[i]) {
            can.push_back(i);
        }   
    }   
    int mx = 0;
    for (int i = 0; ; ++i) {
        auto t = upper_bound(can.begin(), can.end(), mx + d);
        --t;
        if (*t == mx) {
            cout << mx << ' ' << i << '\n';
            exit(0);
        }   
        else {
            mx = *t;
        }   
    }   
}