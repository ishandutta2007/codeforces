#include<iostream>
#include<cstdio>
#define MN 200000
#define INF 1000000000000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k,a[MN+5],ans=0;
long long s[MN+5];
inline long long R(long long x)
{
    if(x>INF) x=INF;if(x<-INF) x=-INF;
    return x;
}
int main()
{
    n=read();k=read();
    for(int i=0;i<=n;++i) a[i]=read();
    for(int i=n;i>=0;--i) s[i]=R(s[i+1]*2+a[i]);
    long long p=0;
    for(int i=0;i<=n;++i)
    {
        if(p&1) break;p>>=1;
        long long res=R(s[i+1]*2+p);
        if(max(res,-res)<=k && !(i==n&&res==0)) ++ans;
        p+=a[i];
    }
    printf("%d\n",ans);
    return 0;
}