#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int a[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, l, r;
    for(cin >> t; t; t -= 1){
        int n, k, z;
        cin >> n >> k >> z;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        int ans = 0;
        for(int j = 0; j <= z; j += 1){
            int r = k - j - j;
            if(r < 0 and r >= n) continue;
            int pans = 0, ma = 0;
            for(int i = 1; i <= 1 + r; i += 1){
                pans += a[i];
                if(i < n) ma = max(ma, a[i] + a[i + 1]);
            }
            ans = max(ans, pans + ma * j);
        }
        cout << ans << "\n";
    }
    return 0;
}