#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> g[205];
pair<int,int> edge[205];
int d[205], md[205];

void dfs(int v, int p){
    vector<int> arr;
    md[v] = 1;
    d[v] = 1;
    for(auto u : g[v]){
        if(u == p)continue;
        dfs(u, v);
        arr.push_back(d[u]);
        md[v] = max(md[v], md[u]);
    }
    sort(arr.rbegin(), arr.rend());
    if(arr.size() == 0)return;
    d[v] = arr[0] + 1;
    md[v] = max(md[v], d[v]);
    if(arr.size() > 1){
        md[v] = max(md[v], arr[0] + arr[1] + 1);
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
    cout<<setprecision(30);

    int n;
    cin>>n;
    for(int i = 1; i <= n-1; i++){
        cin>>edge[i].first>>edge[i].second;
    }
    int ans = 0;
    for(int i = 1; i <= n-1; i++){
        for(int j = 1; j <= n; j++){
            g[j].clear();
            d[j] = 0;
            md[j] = 0;

        }
        for(int j = 1; j <= n-1; j++){
            if(i == j)continue;
            g[edge[j].first].push_back(edge[j].second);
            g[edge[j].second].push_back(edge[j].first);
        }
        dfs(edge[i].first, 0);
        dfs(edge[i].second, 0);
        ans = max(ans, (md[edge[i].first] - 1)*(md[edge[i].second] -1));
    }
    cout<<ans<<endl;

}