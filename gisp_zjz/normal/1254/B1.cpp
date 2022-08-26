#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
ll a[maxn],b[maxn],k,s,ans;
vector <ll> pr;
int n;
ll solve(ll x){
    for (int i=1;i<=n;i++) b[i]=a[i]%x;
    ll ret=0;
    ll tot=0;
    int pos=0;
    for (int i=1;i<=n;i++){
        if (tot<=x/2){
            ret+=tot;
            ll mn=min(x-tot,b[i]);
            tot+=mn; b[i]-=mn;
            if (tot==x) {
                tot=b[i];
                pos=i;
            } else {
                pos++;
            }
        } else {
            ll mn=min(x-tot,b[i]);
            ret+=mn*(i-pos);
            tot+=mn; b[i]-=mn;
            if (tot==x){
                tot=b[i];
                pos=i;
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    ll sum=0;
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if (sum==1){puts("-1");return 0;}
    ll tmp=sum;
    for (ll j=2;j*j<=tmp;j++){
        if (tmp%j==0){
            pr.pb(j);
            while (tmp%j==0) tmp/=j;
        }
    }
    if (tmp>1) pr.pb(tmp);
    ans=1e18;
    for (auto x:pr) ans=min(ans,solve(x));
    printf("%lld\n",ans);
    return 0;
}