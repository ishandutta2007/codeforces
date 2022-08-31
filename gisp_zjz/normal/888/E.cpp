#include<bits/stdc++.h>
#define maxn 1048576

using namespace std;
typedef long long ll;
ll n,m,a[maxn],b[maxn],c[maxn],d[maxn],p,q,t,l,r,ans;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        if (i&1) scanf("%d",&b[q++]);
        else scanf("%d",&a[p++]);
    }
    for (int i=0;i<(1<<p);i++)
    {
        t=0;
        for (int j=0;j<p;j++) if (i&(1<<j)) t+=a[j];
        t%=m; c[i]=t;
    }
    for (int i=0;i<(1<<q);i++)
    {
        t=0;
        for (int j=0;j<q;j++) if (i&(1<<j)) t+=b[j];
        t%=m; d[i]=t;
    }
    sort(c,c+(1<<p)); sort(d,d+(1<<q));
    ans=(c[(1<<p)-1]+d[(1<<q)-1])%m;
    l=0; r=(1<<q)-1;
    while (l<(1<<p)&&r>=0){
        if (c[l]+d[r]<m) ans=max(ans,c[l]+d[r]),l++;
        else r--;
    }
    cout << ans << endl;
}