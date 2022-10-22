#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 300*1000+10,INF=1e9;
int n,k;
string s;
vi e[nax];
vi V[nax],Vs[nax];
bool col[nax],visited[nax];
int p[nax],siz[nax],divv[nax][2];

void dfs(int x) {
    visited[x] = 1;
    for(int nbh:V[x]) if(!visited[nbh]) {
        col[nbh] = 1-col[x];
        dfs(nbh);
    }
    for(int nbh:Vs[x]) if(!visited[nbh]) {
        col[nbh] = col[x];
        dfs(nbh);
    }
}

int Fund(int x) {
    if(p[x]!=x) p[x] = Fund(p[x]);
    return p[x];
}

int Onion(int a,int b) {
    int pa = Fund(a), pb = Fund(b);
    if(pa==pb) return pa;
    if(siz[pa]<siz[pb]) swap(pa,pb);
    p[pb] = pa; siz[pa]+=siz[pb];
    divv[pa][0]=min(INF,divv[pa][0]+divv[pb][0]);
    divv[pa][1]=min(INF,divv[pa][1]+divv[pb][1]);
    return pa;
}

int main() {_
    cin>>n>>k>>s;
    for(int c,i=1; i<=k; i++) {
        cin>>c;
        for(int a,j=0; j<c; j++) {
            cin>>a;
            e[a].PB(i);
        }
    }
    for(int i=1; i<=n; i++) {
        if(e[i].size()==2) {
            if(s[i-1]=='0') {
                V[e[i][0]].PB(e[i][1]);
                V[e[i][1]].PB(e[i][0]);
            } else {
                Vs[e[i][0]].PB(e[i][1]);
                Vs[e[i][1]].PB(e[i][0]);
            }
        }
    }
    for(int i=1; i<=k; i++) {
        if(!visited[i]) dfs(i);
    }
    for(int i=1; i<=k; i++) {
        p[i] = i;
        siz[i] = 1;
        divv[i][col[i]] = 1;
        //cout<<col[i]<<" ";
    }
    //cout<<"\n";
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int pa,pb;
        if(e[i].size()==2) {
            pa = Fund(e[i][0]);pb = Fund(e[i][1]);
            if(pa!=pb) {
            ans-=min(divv[pa][0],divv[pa][1]);
            ans-=min(divv[pb][0],divv[pb][1]);
            //cout<<divv[pb][0]<<" "<<divv[pb][1]<<" "<<divv[pa][0]<<" "<<divv[pa][1]<<"\n";
            pa = Onion(pa,pb);
            //cout<<ans<<" "<<divv[pa][0]<<" "<<divv[pa][1]<<"\n";
            ans+=min(divv[pa][0],divv[pa][1]);
            }
        } else if(e[i].size()==1) {
            if(s[i-1]=='0') {
                pa = Fund(e[i][0]);
                ans-=min(divv[pa][0],divv[pa][1]);
                divv[pa][1-col[e[i][0]]] = INF;
                ans+=min(divv[pa][0],divv[pa][1]);
            } else {
                pa = Fund(e[i][0]);
                ans-=min(divv[pa][0],divv[pa][1]);
                divv[pa][col[e[i][0]]] = INF;
                ans+=min(divv[pa][0],divv[pa][1]);
            }
        }
        cout<<ans<<"\n";
    }

}