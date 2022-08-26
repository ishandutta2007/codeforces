#include<bits/stdc++.h>
#define maxn 230400

using namespace std;
typedef long long ll;

ll a,n,b,ans,w,r;
struct node{
    ll x,y;
}p[maxn];
bool cmp(node u,node v)
{
    if (u.x*a-u.y==v.x*a-v.y) return u.x<v.x;
    else return u.x*a-u.y<v.x*a-v.y;
}

int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    for (int i=0;i<n;i++) scanf("%lld%lld%lld",&w,&p[i].x,&p[i].y);
    sort(p,p+n,cmp); r=1;
    for (int i=1;i<n;i++) if (p[i].x*a-p[i].y!=p[i-1].x*a-p[i-1].y) ans+=r*(r-1),r=1; else r++;
    ans+=r*(r-1); r=1;
    for (int i=1;i<n;i++) if (p[i].x!=p[i-1].x||p[i].y!=p[i-1].y) ans-=r*(r-1),r=1; else r++;
    ans-=r*(r-1); cout << ans << endl;
}