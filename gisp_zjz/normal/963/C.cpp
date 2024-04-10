#include<bits/stdc++.h>
#define N 203040
#define F first
#define S second
#define M1 1000000007
#define M2 1000000009
#define M3 998244353

using namespace std;
typedef long long ll;
struct node{
    ll x,y,z;
}a[N];
ll n,k,d,r,h,p,ans,b[N],c[N];

bool cmp(node u,node v)
{
    if (u.x!=v.x) return u.x<v.x;
    else return u.y<v.y;
}

bool comp(ll u,ll v,ll w,ll z)
{
    if ((u%M1)*(v%M1)%M1!=(w%M1)*(z%M1)%M1) return 1;
    if ((u%M2)*(v%M2)%M2!=(w%M2)*(z%M2)%M2) return 1;
    if ((u%M3)*(v%M3)%M3!=(w%M3)*(z%M3)%M3) return 1;
    return 0;
}

ll gcd(ll x,ll y)
{
    if (x%y==0) return y; else return gcd(y,x%y);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
    sort(a,a+n,cmp); r=1;
    while (r<n&&a[r].x==a[r-1].x) r++;
    for (int i=0;i<r;i++) b[i]=a[i].y,c[i]=a[i].z;
    if (n%r!=0) {printf("0\n");return 0;} h=n/r;
    for (int i=1;i<h;i++)
        for (int j=0;j<r;j++)
            if (a[i*r+j].y!=b[j]) {printf("0\n");return 0;}
    for (int i=1;i<h;i++)
        for (int j=1;j<r;j++)
            if (a[i*r+j].x!=a[i*r+j-1].x) {printf("0\n");return 0;}
    for (int i=1;i<h;i++)
        for (int j=1;j<r;j++)
            if (comp(a[i*r+j].z,c[0],a[i*r].z,c[j])) {printf("0\n");return 0;}
    p=a[0].z; for (int i=1;i<n;i++) p=gcd(p,a[i].z);
    for (ll j=1;j*j<=p;j++)
    {
        if (p%j==0) {
            ans++;
            if (j*j<p) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}