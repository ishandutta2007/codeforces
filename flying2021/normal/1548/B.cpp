#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
using namespace std;
ll a[N],b[N],q[N];
int ans;
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
void answer(int l,int r)
{
    if(l>r) return;
    if(l==r){ans=max(ans,(int)(b[l]>1));return;}
    int mid=(l+r)>>1;
    for(int i=l;i<=r;i++) q[i]=0;
    q[mid]=b[mid];q[mid+1]=b[mid+1];
    for(int i=mid+2;i<=r;i++) q[i]=gcd(q[i-1],b[i]);
    for(int i=mid-1;i>=l;i--) q[i]=gcd(q[i+1],b[i]);
    for(int i=l,j=mid+1;j<=r;j++)
    {
        if(q[j]==1) break;
        while(i<=mid && gcd(q[i],q[j])==1) i++;
        if(i>mid) break;
        ans=max(ans,j-i+1);
    }
    answer(l,mid);answer(mid+1,r);
}
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<n;i++) b[i]=abs(a[i+1]-a[i]);
        answer(1,n-1);
        printf("%d\n",ans+1);
        for(int i=1;i<=n;i++) a[i]=b[i]=q[i]=0;ans=0;
    }
    return 0;
}