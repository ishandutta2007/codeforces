#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e7;

vector<int> g[100005];
bool inset[100005];
int fars[100005], fara[100005];

void dfs1(int v, int p){
    fars[v] = (inset[v]?0:-inf);
    for(auto u : g[v]){
        if(u != p){
            dfs1(u, v);
            if(fars[u] >= 0)fars[v] = max(fars[v], fars[u] + 1);
        }
    }
}

void dfs2(int v, int p, int fa){
    fara[v] = fa;
    vector<int> arr;
    for(auto u : g[v]){
        if(u != p && fars[u] >= 0)arr.push_back(fars[u]);
    }
    if(inset[v])fa = max(fa, 0);
    sort(arr.rbegin(), arr.rend());
    for(auto u : g[v]){
        if(u != p){
            if(arr.size() == 0)dfs2(u, v, fa + 1);
            else if(fars[u] != arr[0])dfs2(u, v, max(fa + 1, arr[0] + 2));
            else if(arr.size() > 1)dfs2(u, v, max(fa + 1, arr[1] + 2));
            else dfs2(u, v, fa + 1);
        }
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

    int n, m, d, x, y;
    cin>>n>>m>>d;
    memset(inset, false, sizeof(inset));
    for(int i = 1; i <= m; i++){
        cin>>x;
        inset[x] = true;
    }
    for(int i = 1; i < n; i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0, -inf);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        // cout<<fars[i]<<" "<<fara[i]<<endl;
        if(max(fars[i], fara[i]) <= d)cnt++;
    }
    cout<<cnt<<endl;
}