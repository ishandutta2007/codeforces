#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
int st[100005], en[100005], vert[200005], p[100005][18], dep[100005], ans[100005], sz[100005], cnt[100005];
vector<pair<int,int> > query[100005];
int ptr;

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
        if(u != bg){
            dfs2(u, false);
        }
    }
    if(bg != -1)dfs2(bg, true);

    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u == bg)continue;
        for(int j = st[u]; j < en[u]; j++){
            int w = vert[j];
            if(st[w] == j){
                cnt[dep[w]]++;
            }
        }
    }
    cnt[dep[v]]++;
    for(int i = 0; i < query[v].size(); i++){
        int d = query[v][i].first + dep[v];
        ans[query[v][i].second] = cnt[d] - 1;
    }
    if(!flag){
        for(int j = st[v]; j < en[v]; j++){
            int w = vert[j];
            if(st[w] == j){
                cnt[dep[w]]--;
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

    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>p[i][0];
        g[p[i][0]].push_back(i);
    }

    for(int i = 0; i < g[0].size(); i++){
        int u = g[0][i];
        dep[u] = 1;
        dfs1(u);
    }

    for(int i = 1; i < 18; i++){
        for(int j = 1; j <= n; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < 3; j++){
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int m, x, y;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        for(int j = 17; j >= 0; j--){
            if(y&(1<<j))x = p[x][j];
        }
        //cout<<x<<" "<<y<<endl;
        if(x != 0){
            query[x].push_back(make_pair(y, i));
            ans[i] = 0;
        }
    }

    for(int i = 0; i < g[0].size(); i++){
        int u = g[0][i];
        dfs2(u, false);
    }

    for(int i = 0; i < m; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}