#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int mod=1000000007;
int n,m,tot,ch[500001][11],fail[500001],dep[500001],dp[2][2][2][500001],now;
string s,a,b;
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
inline void insert(int x)
{
    int node=0;
    for(int i=x;i<=n;++i)
    {
        if(!ch[node][s[i]-'0'])
        {
            ch[node][s[i]-'0']=++tot;
            dep[tot]=dep[node]+1;
        }
        node=ch[node][s[i]-'0'];
    }
}
inline void getfail()
{
    queue<int> q;
    for(int i=0;i<10;++i)
        if(ch[0][i])
            q.emplace(ch[0][i]);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0;i<10;++i)
            if(ch[k][i])
            {
                fail[ch[k][i]]=ch[fail[k]][i];
                q.emplace(ch[k][i]);
            }
            else
                ch[k][i]=ch[fail[k]][i];
    }
}
inline int solve(string str)
{
    memset(dp,0,sizeof dp);
    now=0;
    dp[0][1][0][0]=1;
    for(int i=1;i<=m;++i)
    {
        int lim=str[i]-'0';
        now^=1;
        memset(dp[now],0,sizeof dp[now]);
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                for(int p=0;p<=tot;++p)
                    if(dp[now^1][j][k][p])
                        for(int g=0;g<=(j? lim:9);++g)
                            dp[now][j&&g==lim][k||dep[ch[p][g]]>=(m>>1)][ch[p][g]]=Mod(dp[now][j&&g==lim][k||dep[ch[p][g]]>=(m>>1)][ch[p][g]]+dp[now^1][j][k][p]);
    }
    int res=0;
    for(int i=0;i<2;++i)
        for(int j=0;j<=tot;++j)
            res=Mod(res+dp[now][i][1][j]);
    return res;
}
int main()
{
    cin>>s>>a>>b;
    n=s.length();
    m=a.length();
    s=" "+s;
    a=" "+a;
    b=" "+b;
    --a[m];
    for(int i=m;i>=1&a[i]<'0';--i)
    {
        a[i]='9';
        --a[i-1];
    }
    for(int i=1;i<=n;++i)
        insert(i);
    getfail();
    cout<<Mod(solve(b)-solve(a)+mod)<<'\n';
    return 0;
}