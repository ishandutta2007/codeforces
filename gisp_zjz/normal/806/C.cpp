#include<bits/stdc++.h>
#define maxn 230403

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],c[maxn],e[maxn],cnt[60],h[60],d[60],n,l,r,mid,k;

int f(ll x)
{
    int j=0;
    while (d[j+1]<=x) j++;
    return j;
}

bool check(int x)
{
    h[0]=x; k=0;
    for (int i=1;i<60;i++) h[i]=min(h[i-1],cnt[i]);
    for (int i=0;i<n;i++) if (d[b[i]]==a[i]&&h[b[i]]) e[--h[b[i]]]=a[i]; else c[++k]=a[i];
    if (k>x) return false;
    for (int i=k;i;i--) if (c[i]>=e[k-i]*2) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    d[0]=1; for (int i=1;i<60;i++) d[i]=d[i-1]*2;
    for (int i=0;i<n;i++)
    {
        b[i]=f(a[i]);
        if (d[b[i]]==a[i]) cnt[b[i]]++;
    }
    if (!check(cnt[0])) {cout << -1 << endl; return 0;}
    l=0; r=cnt[0];
    while (r-l>1){
        mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid;
    }
    for (int i=r;i<=cnt[0];i++) cout << i <<' ' ; cout << endl;
    return 0;
}