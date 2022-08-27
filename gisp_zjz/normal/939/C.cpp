#include<bits/stdc++.h>
#define maxn 304030

using namespace std;
typedef long long ll;
ll a[maxn],cnt[maxn],n,r,s,f,m;

int b(int x)
{
    ll ans=n-x+s;
    while (ans>n) ans-=n;
    return ans;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    cin >> s >> f;
    for (int i=n+1;i<=n+n;i++) a[i]=a[i-n];
    cnt[0]=0;
    for (int i=1;i<=n+n;i++) cnt[i]=cnt[i-1]+a[i];
    r=0; m=f-s;
    for (int i=1;i<n;i++)
    {
        if (cnt[i+m]-cnt[i]>cnt[r+m]-cnt[r]) r=i;
        if (cnt[i+m]-cnt[i]==cnt[r+m]-cnt[r]&&b(i)<b(r)) r=i;
    }
    printf("%d\n",b(r));
    return 0;
}