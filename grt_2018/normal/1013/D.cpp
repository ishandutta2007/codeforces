#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 200*1000+1;
int n,m,q,ans=-1;
vector<int>V[2*MAXN];
bool visited[2*MAXN];

void dfs(int x) {
    visited[x]=1;
    for(auto nbh:V[x]) if(!visited[nbh]) dfs(nbh);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int a,b,i=0; i<q;i++) {
        cin>>a>>b;
        V[a].PB(b+MAXN);
        V[b+MAXN].PB(a);
    }
    for(int i=1; i<=n;i++) {
        if(!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    for(int j=1; j<=m;j++) {
        if(!visited[j+MAXN]) {
            ans++;
            dfs(j+MAXN);
        }
    }
    cout<<ans;
}