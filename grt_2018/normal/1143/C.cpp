#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000*100+10;

int n,root;
bool c[MAXN];
vector<int>V[MAXN];
bool visited[MAXN];
vector<int>good;

void dfs(int x) {
    visited[x]=1;
    for(auto nbh:V[x]) if(!visited[nbh]) dfs(nbh);
    bool g=1;
    for(auto nbh:V[x]) if(!c[nbh]) g=0;
    if(c[x]&&g) good.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int p,i=1; i<=n;i++) {
        cin>>p>>c[i];
        if(p==-1) root=i;
        else {
            V[p].push_back(i);
        }
    }
    dfs(root);
    sort(good.begin(),good.end());
    if(good.size()==0) {
        cout<<"-1";
    }
    else
    for(auto it:good) cout<<it<<" ";
    return 0;
}