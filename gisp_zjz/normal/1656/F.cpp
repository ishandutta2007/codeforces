#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const ll inf=4e18;
ll t,a[maxn],s[maxn];
int n,_;
ll calc(ll t,int k){
    if (k==n) k=n-1;
    ll res=0;
    res+=a[1]*(s[n]-s[k])+t*(a[1]*(n-k)+s[n]-s[k]);
    res+=a[n]*s[k]+t*(a[n]*k+s[k]);
    res-=a[1]*a[n]+t*(a[1]+a[n]);
    return res;
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        if (calc(-a[1],1)<calc(-a[1]+1,1)) {puts("INF");continue;}
        if (calc(-a[n],n)<calc(-a[n]-1,n)) {puts("INF");continue;}
        ll ans=max(calc(-a[1],1),calc(-a[n],n));
        for (int k=2;k<n;k++) ans=max(ans,calc(-a[k],k));
        printf("%lld\n",ans);
    }
    return 0;
}