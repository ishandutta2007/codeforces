#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
int st[100005], en[100005], vert[200005], c[100005], sz[100005];
long long int ans[100005];
int n, ptr;
map<int, int> cnt;
map<int, long long int> sum;

void dfs1(int v, int p){
    st[v] = ptr;
    vert[ptr++] = v;
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != p){
            dfs1(u, v);
            sz[v] += sz[u];
        }
    }
    en[v] = ptr;
    vert[ptr++] = v;
}

void inc(int col){
    sum[cnt[col]] -= col;
    if(sum[cnt[col]] == 0)sum.erase(cnt[col]);
    cnt[col]++;
    sum[cnt[col]] += col;
}

void dec(int col){
    sum[cnt[col]] -= col;
    if(sum[cnt[col]] == 0)sum.erase(cnt[col]);
    cnt[col]--;
    sum[cnt[col]] += col;
}

void dfs2(int v, int p, bool flag){
    int bg = -1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != p && (bg == -1 || sz[bg] < sz[u])){
            bg = u;
        }
    }
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != p && u != bg)dfs2(u, v, false);
    }
    if(bg != -1)dfs2(bg, v, true);
    inc(c[v]);
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u == p || u == bg)continue;
        for(int j = st[u]; j < en[u]; j++){
            int w = vert[j];
            if(st[w] == j){
                //cout<<w<<endl;
                inc(c[w]);
            }
        }
    }
    // cout<<v<<":"<<endl;
    // for(map<int,int>::iterator it = sum.begin(); it != sum.end(); it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    ans[v] = sum.rbegin()->second;
    if(!flag){
        for(int i = st[v]; i < en[v]; i++){
            int w = vert[i];
            if(st[w] == i){
                dec(c[w]);
            }
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

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>c[i];
    }
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ptr = 1;
    dfs1(1,0);
    dfs2(1,0,false);
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
    // for(int i = 1; i <= 2*n; i++){
    //     cout<<vert[i]<<" ";
    // }
}