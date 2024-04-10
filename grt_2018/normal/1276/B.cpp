#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000+10;
int t,n,m,A,B;
vi V[nax];
int cnt;
bool visited[nax];

void dfs(int x) {
    visited[x]=1;
    cnt++;
    for(int nbh:V[x]) if(!visited[nbh]) dfs(nbh);
}

int main() {
    scanf("%d",&t);
    while(t--) {
        int l,r;
        scanf("%d%d%d%d",&n,&m,&A,&B);
        for(int i=1; i<=n; i++) V[i].clear();
        for(int a,b,i=0; i<m; i++) {
            scanf("%d%d",&a,&b);
            V[a].PB(b);
            V[b].PB(a);
        }
        for(int i=1; i<=n; i++) visited[i]=0;
        visited[B]=1;
        cnt=0;
        dfs(A);
        l = n-cnt-1;
        cnt=0;
        for(int i=1; i<=n; i++) visited[i]=0;
        visited[A]=1;
        dfs(B);
        r = n-cnt-1;
        cout<<(ll)l*r<<"\n";
    }



}