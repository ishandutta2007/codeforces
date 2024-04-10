#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define MN (ll)1e18
using namespace std;
ll s[10005],s2[10005],mx=0,a[10005];int top1=0,top2=0,top=0;
int main()
{
    ll x,y,l,r;
    scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
    s[++top1]=1;s2[++top2]=1;
    for(ll i=x;;i*=x)
    {
        s[++top1]=i;
        if(i>MN/x)break;
    }
    for(ll i=y;;i*=y)
    {
        s2[++top2]=i;
        if(i>MN/y)break;
    }
    for(int i=1;i<=top1;++i)
        for(int j=1;j<=top2;++j)
            if(s[i]+s2[j]>=l&&s[i]+s2[j]<=r)
                a[++top]=s[i]+s2[j];
    if(!top) return 0*printf("%lld",r-l+1);
    sort(a+1,a+top+1);
    mx=max(mx,a[1]-l);
    mx=max(mx,r-a[top]);
    for(int i=2;i<=top;++i)
        mx=max(mx,a[i]-a[i-1]-1);
    cout<<mx;
    return 0;
}