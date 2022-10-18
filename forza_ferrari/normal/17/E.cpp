#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=51123987;
int n,s[2000001<<1],p[2000001<<1],l[2000001],r[2000001],ans,cnt,sum;
inline int fac(int x)
{
    int res=1;
    for(register int i=1;i<=x;++i)
        res=res*x%mod;
    return res;
}
inline void read()
{
    char c=getchar();
    while(c<'a'||c>'z')
        c=getchar();
    s[0]='~';
    s[cnt=1]='|';
    while(c>='a'&&c<='z')
    {
        s[++cnt]=c;
        s[++cnt]='|';
        c=getchar();
    }
}
signed main()
{
    scanf("%lld",&n);
    read();
    for(register int rr=0,mid=0,t=1;t<=cnt;++t)
	{
		if(t<=rr)
			p[t]=min(p[(mid<<1)-t],rr-t+1);
		while(s[t-p[t]]==s[t+p[t]])
			++p[t];
		if(p[t]+t>rr)
			mid=t,rr=p[t]+t-1;
        if(s[t]=='|'&&p[t]==1)
            continue;
        int len=(p[t]-1)>>1,pos=t>>1;
        if(t&1)
            --len;
        if(pos<1||pos>n)
            continue;
        ++l[pos-len];
        --l[pos+1];
        if(t&1)
            ++pos;
        ++r[pos];
        --r[pos+len+1];
	}
    for(register int i=1;i<=n;++i)
    {
        l[i]=(l[i]+l[i-1]+mod)%mod;
        r[i]=(r[i]+r[i-1]+mod)%mod;
        ans=(ans+l[i])%mod;
    }
    ans=ans*(ans-1)%mod*((mod+1)>>1)%mod;
    for(register int i=1;i<=n;++i)
    {
        ans=(ans-sum*l[i]%mod+mod)%mod;
        sum=(sum+r[i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}