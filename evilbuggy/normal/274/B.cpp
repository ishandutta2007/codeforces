#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> g[100005];
int val[100005];
ll pos[100005], neg[100005];

void dfs(int v, int p){
    bool leaf = true;
    for(auto u : g[v]){
        if(u == p)continue;
        dfs(u, v);
        leaf = false;
    }
    if(leaf){
        if(val[v] > 0){
            neg[v] = val[v];
            pos[v] = 0;
        }else{
            neg[v] = 0;
            pos[v] = -val[v];
        }
        return;
    }
    ll mpos = 0, mneg = 0;
    for(auto u : g[v]){
        if(u == p)continue;
        mpos = max(mpos, pos[u]);
        mneg = max(mneg, neg[u]);
    }
    ll dif = mpos - mneg;
    if(val[v] + dif > 0){
        mneg += val[v] + dif;
    }else{
        mpos -= val[v] + dif;
    }
    pos[v] = mpos;
    neg[v] = mneg;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, u, v;
    cin>>n;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        cin>>val[i];
    }
    dfs(1, 0);
    cout<<pos[1] + neg[1]<<endl;
}