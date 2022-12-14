#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<cmath>
#include<set>
#include<map>
#define eps 1e-6
#define MN 100000
#define ll long long
#define ld __float128
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

int n;
ld a[MN+5],b[MN+5],p,tot;

int main()
{
    n=read();p=read();
    for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),tot+=a[i];
 //   if(tot<=p)return 0*puts("-1");
    ld l=0,r=1e18,mid,sum=0;
    for(int j=1;j<=100;j++)
    {
        mid=(l+r)/2.0;sum=0;
        for(int i=1;i<=n;i++)
            sum+=max((ld)0,a[i]*mid-b[i]);
        if(sum<=mid*p) l=mid;
        else r=mid;
    }
    if(r+eps>=(ld)1e18) return 0*puts("-1");
    printf("%0.6lf\n",(double)(l+r)/2.0);
    return 0;
}