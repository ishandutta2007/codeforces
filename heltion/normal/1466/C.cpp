#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 10;
char s[maxn];
int vis[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        cin >> (s + 1);
        int n = strlen(s + 1);
        for(int i = 1; i <= n; i += 1) vis[i] = 0;
        int ans = 0;
        for(int i = 1; i <= n; i += 1){
            if(i >= 2 and s[i] == s[i - 1] and not vis[i - 1]){
                vis[i] = 1;
                ans += 1;
            }
            if(i >= 3 and s[i] == s[i - 2] and not vis[i - 2] and not vis[i]){
                vis[i] = 1;
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}