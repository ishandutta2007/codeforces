#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int> > G[10001];
char s[10001];
int tag[10001], pw[10001];
int n;

int dfs(int u, int c)
{
    tag[u]=c;
    for(auto &e : G[u])
	{
        int v=e.second, w=e.first;
        if(tag[v]!=-1&&(tag[v]^tag[u]^w)) return 0;
        if(tag[v]==-1&&!dfs(v,c^w)) return 0;
    }
    return 1;
}

void add(int u, int v, int w)
{
    G[u].push_back({w, v}), G[v].push_back({w, u});
}

int solve(int m)
{

    int tot=n+m+1;
    for(int i=1;i<=tot;++i) G[i].clear();
    for(int i=1;i<=n/2;++i) add(i,n-i+1,0);
    for(int i=1;i<=m/2;++i) add(n+i,n+m-i+1,0);
    add(n,tot,1), add(n+m,tot,1);
    for(int i=1;i<=m;++i)
	{

        if(s[i]!='?') add(i,n+i,s[i]-'0');
    }
    for(int i=m+1;i<=n;++i)
	{

        if(s[i]!='?') add(i,tot,s[i]-'0');
    }
    int ret=0;
    for(int i=1;i<=tot;++i) tag[i]=-1;
    for(int i=tot;i>=1;--i)
	{

        if(~tag[i]) continue;
        if(!dfs(i,0)) return 0;
        ++ret;
    }
    return pw[ret-1];
}
int main()
{
    cin>>s+1;
    n=strlen(s+1);
    reverse(s+1,s+1+n);
    pw[0]=1;
    for(int i=1;i<10001;++i) pw[i]=pw[i-1]*2%998244353;
    int ret=0;
    for(int i=1;i<n;++i)
	{
        ret=(ret+solve(i))%998244353;
    }
    cout<<ret<<endl;
    return 0;
}