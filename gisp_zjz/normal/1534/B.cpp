#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005;
ll a[maxn],ans;
int n,m,_;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n); a[0]=a[n+1]=0; ans=0;
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (int i=1;i<=n;i++){
            if (a[i]>max(a[i-1],a[i+1])){
                ans+=a[i]-max(a[i-1],a[i+1]);
                a[i]=max(a[i-1],a[i+1]);
            }
        }
        for (int i=1;i<=n+1;i++) ans+=abs(a[i]-a[i-1]);
        printf("%lld\n",ans);
    }
    return 0;
}