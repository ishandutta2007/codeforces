#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define MAXN 400001
int N,M,K,tot,dfn[MAXN],low[MAXN],top,sta[MAXN],cnt,col[MAXN],deg[MAXN],ans;bool in[MAXN];vector<int>a[MAXN],id[MAXN],E[MAXN];
void dfs(int u)
{
    dfn[u]=low[u]=++tot;sta[++top]=u;in[u]=1;for(auto v:E[u]){if(!dfn[v])dfs(v);if(in[v])low[u]=min(low[u],low[v]);}
    if(dfn[u]==low[u]){cnt++;while(top){int x=sta[top--];in[x]=0;col[x]=cnt;if(x==u)break;}}
}
int main()
{
    cin>>N>>M;a[0].resize(M+1);For(i,1,N){a[i].resize(M+1);id[i].resize(M+1);For(j,1,M){char c;cin>>c;a[i][j]=c=='#';if(a[i][j])id[i][j]=++K;}}
    For(j,1,M){int pre=0;For(i,1,N)if(a[i][j]){if(a[i-1][j])E[id[i][j]].pb(id[i-1][j]);if(pre)E[id[pre][j]].pb(id[i][j]);pre=i;}}
    vector<int>tmp;For(i,1,N)if(a[i][1])tmp.pb(i);For(j,2,M){if(!tmp.empty())For(i,1,N)if(a[i][j]&&i<=tmp.back())E[id[i][j]].pb(id[*lower_bound(tmp.begin(),tmp.end(),i)][j-1]);tmp.clear();For(i,1,N)if(a[i][j])tmp.pb(i);}
    tmp.clear();For(i,1,N)if(a[i][M])tmp.pb(i);FOR(j,M-1,1){if(!tmp.empty())For(i,1,N)if(a[i][j]&&i<=tmp.back())E[id[i][j]].pb(id[*lower_bound(tmp.begin(),tmp.end(),i)][j+1]);tmp.clear();For(i,1,N)if(a[i][j])tmp.pb(i);}
    For(i,1,K)if(!dfn[i])dfs(i);For(i,1,K)for(auto v:E[i])if(col[i]!=col[v])deg[col[v]]++;For(i,1,cnt)ans+=!deg[i];cout<<ans<<endl;return 0;
}