#include <bits/stdc++.h>

using namespace std;

int n;
long long int a[300005];
long long int sum[300005], maxsum;
vector<int> g[300005];
int cnt;

void dfs(int v, int p, bool flag){
    sum[v] = a[v];
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != p){
            dfs(u, v, flag);
            sum[v] += (sum[u] > 0)?sum[u]:0;
        }
    }
    if(flag){
        maxsum = max(sum[v], maxsum);
    }else if(sum[v] == maxsum){
        sum[v] = 0;
        cnt++;
    }
}

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    long long int maxi = -1e9 - 5;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        maxi = max(a[i], maxi);
    }
    int u, v;
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(maxi <= 0){
        long long int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(maxi == a[i])cnt++;
        }
        cout<<maxi*cnt<<" "<<cnt<<endl;
        exit(0);
    }

    dfs(1, 0, 1);
    cnt = 0;
    dfs(1, 0, 0);
    cout<<maxsum*cnt<<" "<<cnt<<endl;

}