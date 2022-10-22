#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+10;
int n,m;
vector<pair<int,int> >V[MAXN];
pair<int,int>edge[MAXN];
bool pr[MAXN];
bool visited[MAXN];
bool coll[MAXN];
bool ok=1;

void dfs(int x,bool c) {
    visited[x]=1;
    coll[x]=c;
    for(auto nbh:V[x]) if(!visited[nbh.first]) {
        dfs(nbh.first,1-c);
    }
    for(auto nbh:V[x]) if(coll[x]==coll[nbh.first]) ok=0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m;i++) {
        int a,b;
        cin>>a>>b;
        edge[i+1] = {a,b};
        V[a].push_back({b,i+1});
        V[b].push_back({a,i+1});
    }
    dfs(1,0);
    if(!ok) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1; i<=n;i++) {
        for(auto nbh:V[i]) {
            if(coll[i]==0&&coll[nbh.first]==1) {
                if(edge[nbh.second]==make_pair(i,nbh.first)) {
                    pr[nbh.second] = 0;
                }
                else {
                    pr[nbh.second] = 1;
                }
            }
        }
    }
    for(int i=1; i<=m;i++) cout<<pr[i];
    return 0;
}