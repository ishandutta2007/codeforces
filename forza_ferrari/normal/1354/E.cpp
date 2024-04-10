#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,a,b,c,bin[10001],cnt,s[5001][2],pre[5001][5001];
bool dp[5001][5001],vis[5001],col[5001];
vector<int> node[5001][2],v[5001];
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
        bin[y]=x;
}
inline void dfs(int k,bool tag)
{
    if(vis[k])
        return;
    vis[k]=1;
    ++s[cnt][tag];
    node[cnt][tag].emplace_back(k);
    for(int i:v[k])
        dfs(i,tag^1);
}
int main()
{
    n=read(),m=read(),a=read(),b=read(),c=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        if(anc(x)==anc(y)||anc(x+n)==anc(y+n))
        {
            cout<<"NO\n";
            return 0;
        }
        link(x,y+n);
        link(y,x+n);
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            ++cnt;
            dfs(i,0);
        }
    dp[0][0]=1;
    for(int i=0;i<=cnt;++i)
        for(int j=0;j<=n;++j)
            pre[i][j]=-1;
    for(int i=1;i<=cnt;++i)
    {
        for(int j=s[i][0];j<=n;++j)
            if(!dp[i][j]&&dp[i-1][j-s[i][0]])
            {
                dp[i][j]=1;
                pre[i][j]=0;
            }
        for(int j=s[i][1];j<=n;++j)
            if(!dp[i][j]&&dp[i-1][j-s[i][1]])
            {
                dp[i][j]=1;
                pre[i][j]=1;
            }
    }
    if(dp[cnt][b])
    {
        cout<<"YES\n";
        int p=b;
        for(int i=cnt;i>=1;--i)
        {
            for(auto j:node[i][pre[i][p]])
                col[j]=1;
            p-=s[i][pre[i][p]];
        }
        for(int i=1;i<=n;++i)
            if(col[i])
                cout<<2;
            else
                if(a>0)
                {
                    --a;
                    cout<<1;
                }
                else
                    cout<<3;
        cout<<'\n';
    }
    else
        cout<<"NO\n";
    return 0;
}