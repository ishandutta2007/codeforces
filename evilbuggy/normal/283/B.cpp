#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int a[200005];
ll dist[200005];
vector<pair<int, ll> > g[200005];

void dfs(int v){
    for(auto x : g[v]){
        dist[x.first] = dist[v] + x.second;
        dfs(x.first);
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

    int n;
    cin>>n;
    for(int i = 2; i <= n; i++){
        dist[i] = -1;
        cin>>a[i];
    }
    for(int i = 2; i <= n; i++){
        int ni = i + a[i];
        int y = a[i];
        if(ni > n){
            g[n + 1].push_back({i, y});
            continue;
        }
        y += a[ni];
        ni = ni - a[ni];
        if(ni <= 0){
            g[n + 1].push_back({i, y});
        }else if(ni > 1){
            g[ni].push_back({i, y});
        }
    }
    dist[n+1] = 0;
    dfs(n + 1);
    for(int i = 1; i < n; i++){
        int ni = i + 1;
        ll y = i;
        if(ni > n){
            cout<<y<<endl;
            continue;
        }
        y += a[ni];
        ni = ni - a[ni];
        if(ni <= 0){
            cout<<y<<endl;
        }else if(ni > 1 && dist[ni] != -1){
            cout<<(y + dist[ni])<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}