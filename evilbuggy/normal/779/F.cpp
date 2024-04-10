#include <bits/stdc++.h>

using namespace std;

vector<pair<int,char> >grr[300005];
int n, g[300005][26], sz[300005], dep[300005],depth = 0;

void dfs1(int v, int p){
    sz[v] = 1;
    dep[v] = dep[p] + 1;
    depth = max(depth, dep[v]);
    for(int i = 0; i < grr[v].size(); i++){
        int u = grr[v][i].first;
        char c = grr[v][i].second;
        if(u != p){
            g[v][c-'a'] = u;
            dfs1(u, v);
            sz[v] += sz[u];
        }
    }
}

int t[300005][26], ptr;

void add(int u, int v){
    for(int i = 0; i < 26; i++){
        if(g[u][i] != -1){
            if(t[v][i] == -1){
                t[v][i] = ptr++;
            }
            add(g[u][i], t[v][i]);
        }
    }
}

void check(int u, int v, int &ans){
    ans -= 1;
    for(int i = 0; i < 26; i++){
        if(g[u][i] != -1 && t[v][i] != -1){
            check(g[u][i], t[v][i], ans);
        }
    }
}

int size[300005];

void dfs(int v){
    int bg = -1;
    int totsz = 1;
    for(int i = 0; i < 26; i++){
        if(g[v][i] != -1){
            dfs(g[v][i]);
            if(bg == -1)bg = i;
            else if(sz[g[v][bg]] < sz[g[v][i]])bg = i;
        }
    }
    if(bg == -1){
        return;
    }
    for(int i = 0; i < 26; i++){
        if(g[v][i] != -1 && i != bg){
            totsz += sz[g[v][i]];
        }
    }
    for(int i = 0; i <= totsz + 10; i++){
        for(int j = 0; j < 26; j++){
            t[i][j] = -1;
        }
    }
    ptr = 1;
    for(int i = 0; i < 26; i++){
        if(g[v][i] != -1 && i != bg){
            add(g[v][i], 0);
        }
    }
    int ans = ptr + sz[g[v][bg]];
    check(g[v][bg], 0, ans);
    size[dep[v]] += sz[v] - ans;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int u, v;
    char c;
    cin>>n;

    for(int i = 1; i < n; i++){
        cin>>u>>v>>c;
        grr[u].push_back(make_pair(v,c));
        grr[v].push_back(make_pair(u,c));
    }

    memset(g, -1, sizeof(g));
    dep[0] = 0;
    dfs1(1, 0);
    dfs(1);
    int index = -1, maxi = 0;
    for(int i = 1; i <= depth; i++){
        if(maxi < size[i]){
            maxi = size[i];
            index = i;
        }
    }
    cout<<n - size[index]<<endl;
    cout<<index<<endl;
}