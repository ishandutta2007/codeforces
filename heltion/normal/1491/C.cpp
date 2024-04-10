#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000 + 2;
int S[maxn], nxt[maxn];
int gnxt(int u){
    return u == nxt[u] ? u : nxt[u] = gnxt(nxt[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> S[i];
        for(int i = 1; i <= n + 1; i += 1){
            nxt[i] = i + (S[i] == 1);
        }
        LL ans = 0;
        for(int i = 1; i <= n; i += 1){
            if(S[i] > n - i + 1){
                ans += S[i] - (n - i + 1);
                S[i] = (n - i + 1);
            }
            while(S[i] > 1){
                int j = i;
                while(j <= n){
                    if(S[j] == 1) j = gnxt(j);
                    else{
                        int k = j;
                        j += S[j];
                        S[k] -= 1;
                        if(S[k] == 1) nxt[k] = k + 1;
                    }
                }
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}