#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
LL a[maxn], s1[maxn], s2[maxn], s[maxn];
int dg = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        if(n == 1){
            cout << "1\n";
            continue;
        }
        for(int i = 1; i <= n; i += 1){
            s[i] = s[i - 1];
            s1[i] = s1[i - 1];
            s2[i] = s2[i - 1];
            s[i] += a[i];
            if(i & 1) s1[i] += a[i];
            else s2[i] += a[i];
        }
        LL ans = 0;
        for(int i = 2; i <= n; i += 1)
            if(s[i] > s[n] - s[i]) ans += 1;
        if(dg) cout << ans << "!\n";
        for(int i = 2; i <= n; i += 1){
            int L = i, R = n;
            if(R < L) continue;
            LL tmp = s[n] - s[i] + a[1] - (s[i] - s[1]);
            if(tmp <= 0) continue;
            if((R - L) & 1) R -= 1; 
            while(L < R){
                int M = L + ((R - L) / 2 + 1) / 2 * 2;
                LL sum = tmp - 2 * (i & 1 ? s1[M] - s1[i] : s2[M] - s2[i]);
                if(sum > 0) L = M;
                else R = M - 2;
            }
            ans += (L - i) / 2 + 1;
        }
        if(dg) cout << ans << "!\n";
        for(int i = 2; i <= n; i += 1){
            int L = i, R = n - 3;
            if(R < L) continue;
            LL tmp = s[n - 1] - s[i] + a[1] - (s[i] - s[1]) - a[n];
            if(tmp <= 0) continue;
            if((R - L) & 1) R -= 1;
            while(L < R){
                int M = L + ((R - L) / 2 + 1) / 2 * 2;
                LL sum = tmp - 2 * (i & 1 ? s1[M] - s1[i] : s2[M] - s2[i]);
                if(sum > 0) L = M;
                else R = M - 2;
            }
            ans += (L - i) / 2 + 1;
        }

        if(dg) cout << ans << "!\n";
        
        for(int i = 1; i <= n; i += 1){
            int L = i, R = n;
            if(R < L) continue;
            LL tmp = s[n] - s[i] - s[i];
            if(tmp <= 0) continue;
            if((R - L) & 1) R -= 1;
            while(L < R){
                int M = L + ((R - L) / 2 + 1) / 2 * 2;
                LL sum = tmp - 2 * (i & 1 ? s1[M] - s1[i] : s2[M] - s2[i]);
                if(sum > 0) L = M;
                else R = M - 2;
            }
            ans += (L - i) / 2 + 1;
        }

        if(dg) cout << ans << "!\n";
        
        for(int i = 1; i <= n; i += 1){
            int L = i, R = n - 3;
            if(R < L) continue;
            LL tmp = s[n - 1] - s[i] - s[i] - a[n];
            if(tmp <= 0) continue;
            if((R - L) & 1) R -= 1;
            while(L < R){
                int M = L + ((R - L) / 2 + 1) / 2 * 2;
                LL sum = tmp - 2 * (i & 1 ? s1[M] - s1[i] : s2[M] - s2[i]);
                if(sum > 0) L = M;
                else R = M - 2;
            }
            ans += (L - i) / 2 + 1;
        }
        
        if(dg) cout << ans << "!\n";

        cout << ans % 998244353 << "\n";
    }
    return 0;
}