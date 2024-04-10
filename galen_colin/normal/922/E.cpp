#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ll n, w, b, x; cin >> n >> w >> b >> x;
    ll cnt[n], c[n];
    
    for (int i = 0; i < n; i++) {
        cin >> cnt[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    ll dp[10005];
    for (int i = 0; i < 10005; i++) dp[i] = -1;
    dp[0] = w;
    
    int rcnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            for (int k = rcnt; k >= 0; k--) {
                ll v = dp[k] - c[i];
                if (v >= 0) {
                    dp[k + 1] = max(dp[k + 1], v);
                }
            }
            
            ++rcnt;
        }
        
        if (i != n - 1) {
            for (int j = 0; j <= rcnt; j++) {
                if (dp[j] > -1) {
                    dp[j] += x;
                    dp[j] = min(dp[j], w + b * j);
                }
            }
        }
    }
    
    for (int i = 10004; i >= 0; i--) {
        if (dp[i] > -1) {
            cout << i << '\n';
            return 0;
        }
    }
}