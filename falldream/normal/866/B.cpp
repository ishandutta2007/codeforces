#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct data{int s,a,b;}s[MN+5],S[MN+5];
int n,SS;long long tot=0,T=0,num;
bool cmp(const data&x,const data&y){return x.a-x.b>y.a-y.b;}

long long Calc(long long x)
{
    //cout<<"Calc"<<x<<endl;
    if(x<0||(x-1)*SS>=tot) return 0;
    long long res=0,y=(num-x)*SS;x*=SS;
    long long left=num*SS-tot;x-=left;y-=left;
    for(int i=1;i<=n;++i) S[i]=s[i];
    for(int i=1;i<=n;++i)
    {
        long long d=min(x,(long long)S[i].s);
        d=max(d,0LL);
        res+=d*S[i].a;x-=d;S[i].s-=d;
    }
    for(int i=n;i;--i)
    {
        long long d=min(y,(long long)S[i].s);
        d=max(d,0LL);
        res+=d*S[i].b;y-=d;S[i].s-=d;
    }
    x+=left;y+=left;
    for(int i=1;i<=n;++i) if(S[i].s>0)
    {
        if(S[i].a<S[i].b)
        {
            long long d=min(y,(long long)S[i].s);
            res+=d*S[i].b;y-=d;S[i].s-=d;
            d=min(x,(long long)S[i].s);
            res+=d*S[i].a;x-=d;S[i].s-=d;
        }
        else
        {
            long long d=min(x,(long long)S[i].s);
            res+=d*S[i].a;x-=d;S[i].s-=d;
            d=min(y,(long long)S[i].s);
            res+=d*S[i].b;y-=d;S[i].s-=d;
        }
    }
    // cout<<"res="<<res<<endl;
    return res;
}

int main()
{
    n=read();SS=read();
    for(int i=1;i<=n;++i) tot+=(s[i].s=read()),s[i].a=read(),s[i].b=read();
    sort(s+1,s+n+1,cmp);num=(tot+SS-1)/SS;
    for(int i=1;i<=n;++i) if(s[i].a<=s[i].b||i==n)
    {
        long long ans=max(Calc(T/SS),Calc(T/SS+1));
        ans=max(ans,Calc(T/SS-1));
        T+=s[i].s;
        ans=max(ans,max(Calc(T/SS),Calc(T/SS+1)));
        ans=max(ans,Calc(T/SS-1));
        return 0*printf("%lld\n",ans);
    }
    else T+=s[i].s;
    return 0;
}