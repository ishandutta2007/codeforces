#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define int long long
int n,m,dp[100001][3],val[100001],ans,bin[100001],s[100001];
multiset<int> st[100001];
vector<pair<int,int> > v[100001];
vector<int> son[100001];
pair<int,int> a[100001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
    {
        bin[y]=x;
        s[x]+=s[y];
    }
}
inline void dfs1(int k,int f)
{
    dp[k][0]=0;
    dp[k][1]=dp[k][2]=-1e18;
    for(auto i:v[k])
    {
        if(i.first==f)
            continue;
        dfs1(i.first,k);
        if(dp[i.first][0]+i.second>dp[k][0])
        {
            dp[k][1]=dp[k][0];
            dp[k][0]=dp[i.first][0]+i.second;
        }
        else
            dp[k][1]=max(dp[k][1],dp[i.first][0]+i.second);
    }
}
inline void dfs2(int k,int f,int dis)
{
    if(f)
        dp[k][2]=dis;
    val[k]=max({dp[k][0],dp[k][1],dp[k][2]});
    a[k]={val[k],k};
    for(auto i:v[k])
    {
        if(i.first==f)
            continue;
        if(dp[i.first][0]+i.second==dp[k][0])
            dfs2(i.first,k,max(dp[k][1],dis)+i.second);
        else
            dfs2(i.first,k,max(dp[k][0],dis)+i.second);
    }
}
inline void dfs3(int k,int f)
{
    for(auto i:v[k])
    {
        if(i.first==f)
            continue;
        dfs3(i.first,k);
        son[k].emplace_back(i.first);
    }
}
signed main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read(),len=read();
        v[x].emplace_back(y,len);
        v[y].emplace_back(x,len);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    sort(a+1,a+n+1,greater<pair<int,int> >());
    dfs3(a[n].second,0);
    m=read();
    for(int i=1;i<=m;++i)
    {
        ans=0;
        int x=read();
        for(int j=1;j<=n;++j)
        {
            bin[j]=0;
            s[j]=1;
        }
        for(int l=1,r=1;l<=n;++l)
        {
            while(r<=n&&a[l].first-a[r].first<=x)
            {
                for(auto j:son[a[r].second])
                    link(a[r].second,j);
                ++r;
            }
            ans=max(ans,s[anc(a[l].second)]);
            --s[anc(a[l].second)];
        }
        cout<<ans<<'\n';
    }
    return 0;
}