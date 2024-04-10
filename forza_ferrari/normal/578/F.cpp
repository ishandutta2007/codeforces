#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,mod,bin[20001],num[20001],cnt,a[401][401],ans;
char mp[101][101];
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
inline int id(int x,int y)
{
    return (x-1)*(m+1)+y;
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
    else
    {
        cout<<"0\n";
        exit(0);
    }
}
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int gauss()
{
    int res=1;
    bool tag=0;
    for(int i=2;i<=cnt;++i)
    {
        if(!a[i][i])
            for(int j=i+1;j<=cnt;++j)
                if(a[j][i])
                {
                    swap(a[i],a[j]);
                    tag^=1;
                    break;
                }
        res=1ll*res*a[i][i]%mod;
        int d=pw(a[i][i],mod-2);
        for(int j=i;j<=cnt;++j)
            a[i][j]=1ll*a[i][j]*d%mod;
        for(int j=i+1;j<=cnt;++j)
        {
            d=a[j][i];
            for(int k=i;k<=cnt;++k)
                a[j][k]=(a[j][k]-1ll*d*a[i][k]%mod+mod)%mod;
        }
    }
    return tag? (mod-res)%mod:res;
}
int main()
{
    n=read(),m=read(),mod=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            mp[i][j]=getchar();
            while(mp[i][j]!='*'&&mp[i][j]!='/'&&mp[i][j]!='\\')
                mp[i][j]=getchar();
            if(mp[i][j]=='/')
                link(id(i,j+1),id(i+1,j));
            if(mp[i][j]=='\\')
                link(id(i,j),id(i+1,j+1));
        }
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=m+1;++j)
            if(((i+j)&1)&&anc(id(i,j))==id(i,j))
                num[id(i,j)]=++cnt;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(mp[i][j]=='*')
                if((i+j)&1)
                {
                    int x=num[anc(id(i,j))],y=num[anc(id(i+1,j+1))];
                    a[x][x]=(a[x][x]+1)%mod;
                    a[y][y]=(a[y][y]+1)%mod;
                    a[x][y]=(a[x][y]+mod-1)%mod;
                    a[y][x]=(a[y][x]+mod-1)%mod;
                }
                else
                {
                    int x=num[anc(id(i,j+1))],y=num[anc(id(i+1,j))];
                    a[x][x]=(a[x][x]+1)%mod;
                    a[y][y]=(a[y][y]+1)%mod;
                    a[x][y]=(a[x][y]+mod-1)%mod;
                    a[y][x]=(a[y][x]+mod-1)%mod;
                }
    ans=(ans+gauss())%mod;
    for(int i=1;i<=cnt;++i)
        for(int j=1;j<=cnt;++j)
            a[i][j]=0;
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=m+1;++j)
            num[id(i,j)]=0;
    cnt=0;
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=m+1;++j)
            if(((i+j)&1^1)&&anc(id(i,j))==id(i,j))
                num[id(i,j)]=++cnt;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(mp[i][j]=='*')
                if((i+j)&1^1)
                {
                    int x=num[anc(id(i,j))],y=num[anc(id(i+1,j+1))];
                    a[x][x]=(a[x][x]+1)%mod;
                    a[y][y]=(a[y][y]+1)%mod;
                    a[x][y]=(a[x][y]+mod-1)%mod;
                    a[y][x]=(a[y][x]+mod-1)%mod;
                }
                else
                {
                    int x=num[anc(id(i,j+1))],y=num[anc(id(i+1,j))];
                    a[x][x]=(a[x][x]+1)%mod;
                    a[y][y]=(a[y][y]+1)%mod;
                    a[x][y]=(a[x][y]+mod-1)%mod;
                    a[y][x]=(a[y][x]+mod-1)%mod;
                }
    ans=(ans+gauss())%mod;
    cout<<ans<<'\n';
    return 0;
}