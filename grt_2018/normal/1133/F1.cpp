#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+1;
int n,m;
vector<int>V[MAXN];
queue<int>Q;
bool visited[MAXN];

void bfs(int x) {
    Q.push(x);
    while(!Q.empty()) {
        x = Q.front();
        Q.pop();
        visited[x]=1;
        for(auto nbh:V[x]) if(!visited[nbh]) {
            Q.push(nbh);
            visited[nbh]=1;
            cout<<x<<" "<<nbh<<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int a,b,i=0; i<m;i++) {
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    int mdeg=0,v=-1;
    for(int i=1; i<=n;i++) {
        if(V[i].size()>mdeg) {
            mdeg = V[i].size();
            v = i;
        }
    }
    bfs(v);
    return 0;
}