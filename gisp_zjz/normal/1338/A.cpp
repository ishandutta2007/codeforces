#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+6;
typedef long long ll;
int _,n,a[maxn];
ll mx;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        mx=-1000000001;
        ll res=0;
        for (int i=1;i<=n;i++){
            ll x; scanf("%lld",&x);
            res=max(res,mx-x);
            mx=max(mx,x);
        }
        int ans=0;
        if (res>0){
            while ((1ll<<ans)-1<res) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}