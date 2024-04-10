#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int lpf[200005];

void seive(){
    memset(lpf, 0, sizeof(lpf));
    for(int i = 2; i < 200005; i++){
        if(lpf[i] == 0){
            for(int j = i; j < 200005; j += i){
                if(lpf[j] == 0){
                    lpf[j] = i;
                }
            }
        }
    }
}

vector<int> factor(int n){
    vector<int> a;
    if(n == 1)return vector<int>();
    while(n > 1){
        int t = lpf[n];
        while(n%t == 0){
            n /= t;
        }
        a.push_back(t);
    }
    return a;
}

int a[200005], md[200005], dist[200005], vis[200005];
vector<int> g[200005], edge[200005];
pair<int,int> arr[200005];
queue<int> myq;

void dfs(int v, int p){
    vis[v] = 1;
    dist[v] = 1;
    md[v] = 1;
    vector<int> tmp;
    for(int i = 0; i < g[v].size(); i++){
        if(g[v][i] == p)continue;
        dfs(g[v][i], v);
        tmp.push_back(dist[g[v][i]]);
        md[v] = max(md[v], md[g[v][i]]);
    }
    if(tmp.size() == 0){
        return;
    }
    if(tmp.size() == 1){
        dist[v] = tmp[0] + 1;
        md[v] = max(md[v], dist[v]);
    }else{
        sort(tmp.rbegin(), tmp.rend());
        dist[v] = tmp[0] + 1;
        md[v] = max(md[v], tmp[0] + tmp[1] + 1);
    }
    md[v] = max(md[v], dist[v]);
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();
    int n;
    cin>>n;
    bool tt = false;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] != 1)tt = true;
    }
    int u,v;
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        arr[i] = make_pair(u, v);
        int g = __gcd(a[u], a[v]);
        vector<int> tmp = factor(g);
        for(int j = 0; j < tmp.size(); j++){
            edge[tmp[j]].push_back(i);
        }
    }
    if(!tt){
        cout<<0<<endl;
        return 0;
    }
    int ans = 1;
    for(int i = 2; i < 200005; i++){
        if(edge[i].size() > 0){
            for(int j = 0; j < edge[i].size(); j++){
                int ind = edge[i][j];
                u = arr[ind].first, v = arr[ind].second;
                g[u].clear();
                g[v].clear();
                vis[v] = 0, vis[u] = 0;
            }
            for(int j = 0; j < edge[i].size(); j++){
                int ind = edge[i][j];
                u = arr[ind].first, v = arr[ind].second;
                g[u].push_back(v);
                g[v].push_back(u);
                myq.push(v);
                myq.push(u);
            }
            while(!myq.empty()){
                u = myq.front();
                myq.pop();
                if(vis[u] == 1)continue;
                dfs(u, u);
                ans = max(ans, md[u]);
            }
        }
    }
    cout<<ans<<endl;
}