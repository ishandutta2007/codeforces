//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
ll n;
ll m,w,a[100111],b[100111];
bool check(ll x)
{
    memset(b,0,sizeof(b));
    ll cnt=0,pre=0;
    for(int i=1;i<=n;i++)
    {
        if(x-a[i]>pre)
        {
            b[i]=x-a[i]-pre;
            cnt+=x-a[i]-pre;
            pre+=x-a[i]-pre;
        }
        if(i>=w)pre-=b[i-w+1];
    }
    return cnt<=m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>w;
    ll s=0,l=LINF,r,mid;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
        l=min(l,a[i]);
    }
    r=(s+m*w)/n;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))l=mid+1;else r=mid-1;
    }
    cout<<r<<endl;
    return 0;
}