#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

vector<int> g[100005];
bool vis[100005];
int ans[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, u, v;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(1);
    int ptr = 1;
    while(!pq.empty()){
        int y = pq.top();
        pq.pop();
        if(vis[y])continue;
        vis[y] = true;
        ans[ptr] = y; ptr++;
        for(auto u : g[y]){
            if(!vis[u]){
                pq.push(u);
            }
        }
    }
    for(int i = 1; i < ptr; i++){
        cout<<ans[i]<<" ";
    }
}