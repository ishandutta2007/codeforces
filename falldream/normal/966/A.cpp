#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,n1,n2,a[MN+5],b[MN+5],v;
inline int Abs(int x){return x<0?-x:x;}
int main()
{
    n=read();m=read();n1=read(),n2=read();v=read();
    for(int i=1;i<=n1;++i) a[i]=read();sort(a+1,a+n1+1);
    for(int i=1;i<=n2;++i) b[i]=read();sort(b+1,b+n2+1);
    int Q=read();
    while(Q--)
    {
        int x1=read(),y1=read(),x2=read(),y2=read();ll ans=(x1==x2)?Abs(y1-y2):1e18;
        if(n1)
        {
            int pos=lower_bound(a+1,a+n1+1,y1)-a;
            if(pos<=n1) ans=min(ans,0LL+a[pos]-y1+Abs(y2-a[pos])+Abs(x1-x2));
            if(pos>1) ans=min(ans,0LL+y1-a[pos-1]+Abs(y2-a[pos-1])+Abs(x1-x2));
        }
        if(n2)
        {
            int pos=lower_bound(b+1,b+n2+1,y1)-b;
            if(pos<=n2) ans=min(ans,0LL+b[pos]-y1+Abs(y2-b[pos])+(Abs(x1-x2)+v-1)/v);
            if(pos>1) ans=min(ans,0LL+y1-b[pos-1]+Abs(y2-b[pos-1])+(Abs(x1-x2)+v-1)/v);
        }
        printf("%lld\n",ans);
    }
    return 0;
}