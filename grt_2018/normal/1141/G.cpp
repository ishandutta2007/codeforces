#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 200*1000+10;
int n,k;
vector<pi>V[MAXN];
int deg[MAXN];
int ans;
int color[MAXN];
bool visited[MAXN];

void dfs(int x, int forbidden) {
    visited[x]=1;
    int c=1;
    for(auto nbh:V[x]) {
        if(!visited[nbh.ST]) {
            if(V[x].size()>ans) {
                color[nbh.ND] = 1;
                dfs(nbh.ST,1);
            }
            else {
                if(c==forbidden) c++;
                color[nbh.ND] = c;
                dfs(nbh.ST,c);
            }
            c++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int a,b,i=0; i<n-1;i++) {
        cin>>a>>b;
        V[a].PB({b,i});
        V[b].PB({a,i});
        deg[a]++;
        deg[b]++;
    }
    sort(deg+1,deg+n+1);
    ans = deg[n-k];
    dfs(1,0);
    cout<<ans<<"\n";
    for(int i=0; i<n-1;i++) cout<<color[i]<<" ";
    return 0;
}