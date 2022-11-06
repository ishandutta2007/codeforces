#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 200010
#pragma GCC optimize(2)
#define ll long long
using namespace std;
ll a[N],b[N];
struct node{
    ll a,b,c;
    node(ll A=0,ll B=0):a(A),b(B),c(A/B){}
    bool operator <(const node d)const
    {
        if(c!=d.c) return c>d.c;
        if(b!=d.b) return b<d.b;
        return a>d.a;
    }
};
int n,k;
priority_queue<node>q;
bool check(ll x)
{
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++)
    if(a[i]/b[i]<k) q.push(node(a[i],b[i]));
    for(int i=0;i<k && !q.empty();i++)
    {
        node u=q.top();q.pop();
        if(u.a/u.b<i) return false;
        if((u.a+x)/u.b<k) q.push(node(u.a+x,u.b));
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    ll l=0,r=2e12,ans=-1;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}