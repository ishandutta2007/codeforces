#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> g[MAXN];
int dead[MAXN], ans[MAXN], sz[MAXN];

void dfs(int v, int p){
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != p){
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
}

void cd(int v, int cnt, int ch){
    int bg = -1;
    for(int i = 0; i < g[v].size(); i++){
        if(dead[g[v][i]] == 0){
            if(bg == -1 || sz[bg] < sz[g[v][i]]){
                bg = g[v][i];
            }
        }
    }
    if(bg == -1){
        ans[v] = ch;
    }else if(sz[bg] <= cnt/2){
        ans[v] = ch;
        dead[v] = 1;
        for(int i = 0; i < g[v].size(); i++){
            if(dead[g[v][i]] == 0){
                cd(g[v][i], sz[g[v][i]], ch+1);
            }
        }
    }else{
        sz[v] = cnt - sz[bg];
        sz[bg] = cnt;
        cd(bg, cnt, ch);
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
    int n,u,v;
    cin>>n;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    memset(dead,0,sizeof(dead));
    cd(1,n,0);
    for(int i = 1; i <= n; i++){
        cout<<char(ans[i]+'A')<<" ";
    }

}