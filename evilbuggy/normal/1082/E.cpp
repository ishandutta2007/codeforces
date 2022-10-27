#include <bits/stdc++.h>

using namespace std;

int a[500005], f[500005], dp[500005];
vector<int> g[500005];

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(f, 0, sizeof(f));

    int n, c;
    cin>>n>>c;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        g[a[i]].push_back(i);
        f[i] = f[i-1] + ((a[i] == c)?1:0);
    }

    int ans = f[n];

    for(int ind = 0; ind < 500005; ind++){
        if(ind == c)continue;
        for(int i = 0; i < g[ind].size(); i++){
            if(i == 0)dp[0] = f[n] + 1;
            else{
                dp[i] = max(f[n] + 1, dp[i-1] + 1 - f[g[ind][i] - 1] + f[g[ind][i-1]]);
            }
            ans = max(ans, dp[i]);
        }
    }
    cout<<ans<<endl;

}