#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=3e5+5;
int n,a[N],dp1[N],dp2[N],ans,s1,s2;
vector<int> g[N];
bool ok(int x,int y)
{
    if(x&&y) return 0;
    return 1;
}
void dfs(int x,int p)
{
    if(a[x]==1) dp1[x]++;
    if(a[x]==2) dp2[x]++;
    for(auto &it : g[x]){
        if(it==p) continue;
        dfs(it,x);
        dp1[x]+=dp1[it];
        dp2[x]+=dp2[it];
    }
    if(x!=1&&ok(dp1[x],dp2[x])&&ok(s1-dp1[x],s2-dp2[x])) ans++;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==1) s1++;
        if(a[i]==2) s2++;
    }
    for(int u,v,i=1;i<=n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}