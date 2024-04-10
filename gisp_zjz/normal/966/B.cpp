#include<bits/stdc++.h>
#define maxn 510300
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll a[maxn],b[maxn],n,k,s1,s2,l,r,mid,u0,v0;
pi c[maxn];
bool flag;
bool cmp(pi u,pi v)
{
    return u.F>v.F;
}

int f(ll x)
{
    l=-1; r=n;
    while (r-l>1){
        mid=(l+r)/2;
        if (c[mid].F>=x) l=mid; else r=mid;
    }
    return r;
}

int main()
{
    cin >> n >> s1 >> s2;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&c[i].F);
        c[i].S=i+1;
    }
    sort(c,c+n,cmp);
    for (int i=1;i<=n;i++) a[i]=f((s1+i-1)/i),b[i]=f((s2+i-1)/i);
    u0=-1; for (int i=n;i;i--) if (a[i]-i>=0) u0=i;
    v0=-1; for (int i=n;i;i--) if (b[i]-i>=0) v0=i;
    //for (int i=1;i<=n;i++) cout << a[i] << ' '; cout << endl;
    //for (int i=1;i<=n;i++) cout << b[i] << ' '; cout << endl;
    if (u0==-1||v0==-1) {puts("No");return 0;}
    for (int i=1;i<=n;i++) if (a[i]-i-v0>=0){
        puts("Yes");
        cout << i << ' ' << v0 << endl;
        for (int j=a[i]-i;j<a[i];j++) printf("%d ",c[j].S); printf("\n");
        for (int j=0;j<v0;j++) printf("%d ",c[j].S); printf("\n");
        return 0;
    }
    for (int i=1;i<=n;i++) if (b[i]-i-u0>=0){
        puts("Yes");
        cout << u0 << ' ' << i << endl;
        for (int j=0;j<u0;j++) printf("%d ",c[j].S); printf("\n");
        for (int j=b[i]-i;j<b[i];j++) printf("%d ",c[j].S); printf("\n");
        return 0;
    }
    puts("No");return 0;
}