#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m, ans = 0;
        cin >> n >> m;
        vector<int> p(n + 1), vis(n + 1);
        for(int i = 0, x, y; i < m; i += 1){
            cin >> x >> y;
            p[x] = y;
        }
        for(int i = 1; i <= n; i += 1){
            if(p[i] == 0 or p[i] == i) continue;
            else{
                ans += 1;
                if(not vis[i]){
                    int x = i;
                    while(not vis[x] and x){
                        vis[x] = 1;
                        x = p[x];
                    }
                    ans += x == i;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}