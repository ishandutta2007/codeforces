#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
ll x,n,a[maxn];

int main(){
    int _;scanf("%d",&_);
    while (_--){
        scanf("%lld%lld",&n,&x);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1); reverse(a+1,a+n+1);
        for (int i=2;i<=n;i++) a[i]+=a[i-1];
        int ans=0;
        for (int i=1;i<=n;i++) if (x*i<=a[i]) ans=i;
        printf("%d\n",ans);
    }
    return 0;
}