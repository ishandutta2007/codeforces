#include<bits/stdc++.h>
#define MN 1000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define mod 1000000007
char s[55][MN+5];
map<long long,int> mp;
int S[MN+5][MN+5],n,m,f[MN+5],ans=1;
int main()
{
    m=read();n=read();
    for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
    S[0][0]=1;
    for(int i=1;i<=m;++i) for(int j=1;j<=i;++j)
        S[i][j]=(1LL*j*S[i-1][j]+S[i-1][j-1])%mod,f[i]=(f[i]+S[i][j])%mod;
    for(int i=1;i<=m;++i)
    {
        long long x=0;
        for(int j=1;j<=n;++j) if(s[j][i]=='1') x|=1LL<<j;
        ++mp[x];
    }
    for(map<long long,int>::iterator it=mp.begin();it!=mp.end();++it)
        ans=1LL*ans*f[it->second]%mod;
    cout<<ans;
    return 0;
}