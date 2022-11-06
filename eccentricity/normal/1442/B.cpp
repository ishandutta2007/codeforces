#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
constexpr int mod = 998244353;
int a[maxn], b[maxn], p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i += 1){
            cin >> a[i];
            p[i] = 0;
        }
        for(int i = 1; i <= k; i += 1){
            cin >> b[i];
            p[b[i]] = i;
        }
        int ans = 1;
        for(int i = 1; i <= n; i += 1) if(p[a[i]]){
            int pans = 0;
            if(i > 1 and p[a[i]] > p[a[i - 1]]) pans += 1;
            if(i < n and p[a[i]] > p[a[i + 1]]) pans += 1;
            ans = ans * pans % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}