#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000 + 1;
int a[maxn], b[maxn], f[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        a[i] -= i;
    }
    for(int i = 1, j; i <= k; i += 1){
        cin >> j;
        b[j] = 1;
    }
    a[0] = -1E9;
    a[n + 1] = 2E9;
    b[0] = b[n + 1] = 1;
    int ans = 0;
    for(int L = 0, R; L <= n; L = R){
        R = L + 1;
        while(not b[R]) R += 1;
        if(a[R] < a[L]){
            cout << "-1";
            return 0;
        }
        int fn = 0;
        for(int i = L + 1; i <= R; i += 1){
            if(a[i] < a[L]) continue;
            int m = upper_bound(f + 1, f + fn + 1, a[i]) - f;
            if(m > fn)
                f[fn += 1] = a[i];
            else f[m] = min(f[m], a[i]);
            if(i == R) ans += R - L - m;
        }
    }
    cout << ans;
    return 0;
}