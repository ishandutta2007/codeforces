#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 1000200

using namespace std;
typedef long long ll;
ll n,a[maxn],b[maxn],r,k,ans,p,m;

ll pow_(ll x,ll y)
{
    ll tmp=1;
    while (y){
        if (y&1) tmp=tmp*x%mod;
        x=x*x%mod; y>>=1;
    }
    return tmp;
}

int main()
{
    scanf("%d",&n); m=n; ans=0;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n); r=1; b[1]=0;
    for (int i=1;i<n;i++) if (a[i]==a[i-1]) b[i]=b[i-1],r++; else b[i]=b[i-1]+r,r=1;
    p=1; for (int i=1;i<=n;i++) p=p*i%mod;
    while (n>1&&a[n-2]==a[n-1]) n--;
    for (int i=0;i<n-1;i++) ans=(ans+p*pow_(m-b[i],mod-2)%mod*a[i]%mod)%mod;
    cout << ans << endl;
}