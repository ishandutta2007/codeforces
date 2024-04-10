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
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,N[65];
ll a[MN+5],Ans[65][MN+5];
int main()
{
    n=m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1);
    for(int j=59;~j;--j)
    {
        int beg=m+1,bb=m+1;
        for(int i=1;i<=m;++i) if(a[i]>=(1LL<<j)) {beg=bb=i;break;}
        //cout<<j<<" "<<beg<<" "<<m<<endl;
        ll val=0;
        for(int i=0;i<=N[j+1];++i)
        {
            if(i) val^=Ans[j+1][i],Ans[j][++N[j]]=Ans[j+1][i];
            if(beg<=m&&!(val&(1LL<<j))) Ans[j][++N[j]]=a[beg],val^=a[beg],++beg;
        }
        if(beg<=m) return 0*puts("No");
        m=bb-1;
    }
    puts("Yes");
    for(int i=1;i<=n;++i) printf("%lld ",Ans[0][i]);
    return 0;
}