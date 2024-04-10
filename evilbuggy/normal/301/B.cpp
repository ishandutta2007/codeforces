#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = 1e16;

int x[105], y[105], a[105][105], c[105];
ll dist[105];
bool vis[105];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, d;
    cin>>n>>d;
    for(int i = 2; i < n; i++){
        cin>>c[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                a[i][j] = 0;
                continue;
            }
            a[i][j] = d*(abs(x[i] - x[j]) + abs(y[i] - y[j]));
            if(i >= 2 && i < n)a[i][j] -= c[i];
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i = 2; i <= n; i++){
        dist[i] = inf;
    }
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
    q.push({0, 1});
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(vis[v])continue;
        vis[v] = true;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && dist[i] > dist[v] + a[v][i]){
                dist[i] = dist[v] + a[v][i];
                q.push({dist[i],i});
            }
        }
    }
    cout<<dist[n]<<endl;
}