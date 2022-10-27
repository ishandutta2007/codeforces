#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct Edge{
    int u, v, w;
};

int n, m, pos[100005], vis[100005];
Edge arr[100005];
vector<int> g[100005], tlsrt;
stack<int> st;
vector<int> ung;

void dfs(int v){
    if(vis[v])return;
    vis[v] = true;
    for(auto u : g[v]){
        dfs(u);
    }
    st.push(v);
}

bool check(int x){
    for(int i = 1; i <= n; i++){
        g[i].clear();
        vis[i] = false;
    }
    ung.clear();
    for(int i = 1; i <= m; i++){
        if(arr[i].w > x){
            g[arr[i].u].push_back(arr[i].v);
        }else{
            ung.push_back(i);
        }
    }
    while(!st.empty())st.pop();
    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i);
    }
    tlsrt.clear();
    while(!st.empty()){
        tlsrt.push_back(st.top());
        st.pop();
    }
    for(int i = 0; i < tlsrt.size(); i++){
        pos[tlsrt[i]] = i;
    }
    for(int u = 1; u <= n; u++){
        for(auto v : g[u]){
            if(pos[u] > pos[v])return false;
        }
    }
    return true;
}

void search(int &ans, vector<int> &ansarr){
    int l = 0, r = 1e9;
    while(l < r){
        int m = l + (r - l)/2;
        if(check(m)){
            r = m;
        }else{
            l = m + 1;
        }
    }
    ans = l;
    check(l);
    for(auto x : ung){
        if(pos[arr[x].u] > pos[arr[x].v])ansarr.push_back(x);
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

    cin>>n>>m;
    int u, v, w;
    for(int i = 1; i <= m; i++){
        cin>>u>>v>>w;
        arr[i] = {u, v, w};
    }
    int ans;
    vector<int> ansarr;
    search(ans, ansarr);
    cout<<ans<<" "<<ansarr.size()<<endl;
    for(auto x : ansarr){
        cout<<x<<" ";
    }
}