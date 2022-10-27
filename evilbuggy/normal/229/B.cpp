#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = (1LL<<52);

vector<pair<int,int> > g[100005];
ll d[100005];
bool vis[100005];
map<int, int> nxt[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, u, v, w;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>u>>v>>w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for(int i = 1; i <= n; i++){
        d[i] = inf;
        vis[i] = false;
        int k, x;
        cin>>k;
        while(k--){
            cin>>x;
            nxt[i][x] = x;
        }
        for(map<int,int>::reverse_iterator it = nxt[i].rbegin(); it != nxt[i].rend(); it++){
            x = it->first;
            if(nxt[i].find(x+1) != nxt[i].end()){
                nxt[i][x] = nxt[i][x+1];
            }else{
                nxt[i][x] = x+1;
            }
        }
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > myq;
    if(nxt[1].find(0) != nxt[1].end()){
        myq.push({nxt[1][0], 1});
        d[1] = nxt[1][0];
    }else{
        myq.push({0, 1});
        d[1] = 0;
    }
    while(!myq.empty()){
        v = myq.top().second;
        myq.pop();
        if(vis[v])continue;
        vis[v] = true;
        for(auto x : g[v]){
            u = x.first, w = x.second;
            if(vis[u])continue;
            ll tmp = d[v] + w;
            if(nxt[u].find(tmp) != nxt[u].end()){
                tmp = nxt[u][tmp];
            }
            if(tmp < d[u]){
                d[u] = tmp;
                myq.push({tmp, u});
            }
        }
    }
    if(!vis[n]){
        cout<<-1<<endl;
        return 0;
    }
    ll ans = inf;
    for(auto x : g[n]){
        ans = min(ans, d[x.first] + x.second);
    }
    cout<<ans<<endl;
}