#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 1000000000
#define MN 100000000
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

ll n;int q,d=0,dep;
char s[100005];

ll pd(ll x)
{
    x+=(1LL<<(d-dep));
    x/=(1LL<<(d-dep+1));
    return (x&1LL)?-1:1;
}

int main()
{
    n=read();q=read();
    for(ll i=n;i;i>>=1)d++;
    for(int i=1;i<=q;i++)
    {
        ll x=read();scanf("%s",s+1);dep=d;
        for(ll i=x;!(i&1);i>>=1) --dep;
        for(int i=1;s[i];i++)
        {
            if((s[i]=='L'||s[i]=='R')&&dep==d)continue;
            if(s[i]=='U'&&dep==1)continue;
            if(s[i]=='L')x-=(1LL<<(d-dep-1));
            if(s[i]=='R')x+=(1LL<<(d-dep-1));
            if(s[i]=='U')x-=pd(x)*(1LL<<(d-dep));
            dep+=(s[i]!='U')?1:-1;
           // cout<<x<<" "<<dep<<" "<<d<<endl;
        }
        printf("%lld\n",x);
    }
}