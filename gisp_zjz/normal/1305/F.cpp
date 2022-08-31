#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=200005;
const int E=80;
vector <ll> pr,f;
mt19937_64 gen(time(0));
ll a[maxn];
map<ll,ll> val;
int n;
ll solve(ll p){
    if (val.find(p)!=val.end()) return val[p];
    ll ret=0;
    for (int i=0;i<n;i++){
        if (a[i]<p) ret+=p-a[i];
        else {
            ll h=a[i]%p;
            ret+=min(h,p-h);
        }
    }
    val[p]=ret;
    return ret;
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    for (int i=0;i<n;i++){
        f.pb(a[i]+1);
        if (a[i]>1) f.pb(a[i]);
        if (a[i]>2) f.pb(a[i]-1);
    }
    int m=f.size();
    ll ans=n;
    for (int _=0;_<E;_++){
        ll x=f[gen()%m],j=2;
        f.clear();
        while (j*j<=x){
            if (x%j==0){
                while (x%j==0) x/=j;
                pr.pb(j);
            }
            ++j;
        }
        if (x>1) pr.pb(x);
        for (auto p:pr) ans=min(ans,solve(p));
    }
    printf("%lld\n",ans);
    return 0;
}