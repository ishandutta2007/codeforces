#include <bits/stdc++.h>

using namespace std;

vector<int> g[500005];
vector<pair<int,int> > query[500005];
int arr[500005], st[500005], en[500005], vert[1000005], dep[500005], cnt[500005], sz[500005];
bool ans[500005];
string str;
int n, ptr;

int count(int x){
    int tmp = 0;
    while(x > 0){
        tmp += (x&1);
        x >>= 1;
    }
    return tmp;
}

void dfs1(int v){
    st[v] = ptr;
    vert[ptr++] = v;
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        dep[u] = dep[v] + 1;
        dfs1(u);
        sz[v] += sz[u];
    }
    en[v] = ptr;
    vert[ptr++] = v;
}

void dfs2(int v, bool flag){
    int bg = -1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(bg == -1 || sz[bg] < sz[u]){
            bg = u;
        }
    }
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != bg)dfs2(u, false);
    }
    if(bg != -1)dfs2(bg, true);
    cnt[dep[v]] ^= arr[v];
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != bg){
            for(int j = st[u]; j < en[u]; j++){
                int w = vert[j];
                if(st[w] == j){
                    cnt[dep[w]] ^= arr[w];
                }
            }
        }
    }
    for(int i = 0; i < query[v].size(); i++){
        int d = query[v][i].first;
        if(count(cnt[d]) > 1){
            ans[query[v][i].second] = false;
        }else{
            ans[query[v][i].second] = true;
        }
    }
    if(!flag){
        for(int i = st[v]; i < en[v]; i++){
            int w = vert[i];
            if(st[w] == i){
                cnt[dep[w]] ^= arr[w];
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

    int m, x, y;
    cin>>n>>m;
    for(int i = 2; i <= n; i++){
        cin>>x;
        g[x].push_back(i);
    }
    cin>>str;
    for(int i = 0; i < n; i++){
        cnt[i+1] = 0;
        arr[i+1] = (1<<(str[i]-'a'));
    }
    dep[1] = 1;
    ptr = 1;
    dfs1(1);
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        query[x].push_back(make_pair(y, i));
    }
    dfs2(1,true);
    for(int i = 0; i < m; i++){
        if(ans[i]){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }
}