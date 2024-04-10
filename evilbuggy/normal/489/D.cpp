#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

vector<int> g[3005];
int cnt[3005][3005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cnt, 0, sizeof(cnt));
    int n, m, u, v;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        for(auto u : g[i]){
            for(auto v : g[u]){
                if(v != i)cnt[i][v]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j) ans += 1LL*cnt[i][j]*(cnt[i][j] - 1)/2;
        }
    }
    cout<<ans<<endl;
}