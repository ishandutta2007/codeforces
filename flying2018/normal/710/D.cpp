#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll a1,b1,a2,b2,x1,x2,t,l,r;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){x=1,y=0;return a;}
    ll g=exgcd(b,a%b,y,x);
    y=y-a/b*x;
    return g;
}
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld",&a1,&b1,&a2,&b2,&l,&r);
    ll g=exgcd(a1,a2,x1,x2),m=a1*a2/g;
    if((b2-b1)%g){puts("0");return 0;}
    x1*=(b2-b1)/g;ll xx=m/a1;
    x2*=(b1-b2)/g;ll yy=m/a2;
    ll l1=max(0ll,(l-b1)/a1+(l>b1 &&(l-b1)%a1!=0));
    ll l2=max(0ll,(l-b2)/a2+(l>b2 &&(l-b2)%a2!=0));
    ll r1=(r-b1)/a1-(r<b1 && (r-b1)%a1!=0);
    ll r2=(r-b2)/a2-(r<b2 && (r-b2)%a2!=0);
    t=max((l1-x1)/xx,(l2-x2)/yy);
    x1+=t*xx,x2+=t*yy;
    if(x1<l1 || x2<l2) x1+=xx,x2+=yy;
    printf("%lld",r1<x1 || r2<x2?0:min((r1-x1)/xx,(r2-x2)/yy)+1);
    return 0;
}