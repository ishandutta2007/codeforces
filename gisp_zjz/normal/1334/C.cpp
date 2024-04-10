#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
ll x,n,a[maxn],b[maxn];
int _;
int main(){
    scanf("%d",&_);
    while (_--){
        ll ans=1e18; scanf("%lld",&n);
        for (int i=0;i<n;i++) scanf("%lld%lld",&a[i],&b[i]);
        a[n]=a[0]; b[n]=b[0];
        ll sum=0;
        for (int i=0;i<n;i++) sum+=max(0ll,a[i]-b[(i-1+n)%n]);
        //cout<<sum<<endl;
        for (int i=0;i<n;i++) ans=min(ans,sum-max(0ll,a[i]-b[(i-1+n)%n])+a[i]);
        printf("%lld\n",ans);
    }
    return 0;
}