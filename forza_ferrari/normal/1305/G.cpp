#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,maxn,bin[400005],cnt[400005],ans;
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
        cnt[x]=cnt[y]=1;
    }
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        int x=read();
        ans-=x;
        ++cnt[x+1];
    }
    ++cnt[1];
    for(int s=(1<<18)-1;s>=1;--s)
        for(int t=s;t>(s^t);t=s&(t-1))
        {
            int x=t+1,y=(s^t)+1;
            if(cnt[x]&&cnt[y]&&anc(x)!=anc(y))
            {
                ans+=(cnt[anc(x)]+cnt[anc(y)]-1)*s;
                link(x,y);
            }
        }
    cout<<ans<<'\n';
    return 0;
}