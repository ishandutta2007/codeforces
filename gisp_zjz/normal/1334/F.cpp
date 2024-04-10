#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const ll inf=4e18;
const int maxn=1e6+3;
int a[maxn],b[maxn],n,m,c[maxn];
ll p[maxn],s[maxn],dp[maxn],sum;
ll qry(int x){
    ll ret=0;
    while (x) ret+=s[x],x-=x&(-x);
    return ret;
}
void add(int x,ll y){
    while (x<maxn) s[x]+=y,x+=x&(-x);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
    scanf("%d",&m);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    b[m+1]=1e9+3;
    for (int i=1;i<=n;i++){
        int x=lower_bound(b+1,b+m+1,a[i])-b;
        if (b[x]==a[i]) c[i]=x*2; else c[i]=x*2-1;
        sum+=p[i];
    }
    for (int i=1;i<=m;i++) dp[i]=-inf;
    for (int i=n;i;i--){
        if (p[i]>0) add(c[i],p[i]);
        if (c[i]%2==0){
            int x=c[i]/2;
            if (dp[x+1]>-inf) dp[x]=max(dp[x],dp[x+1]+qry(x*2)-qry(x*2-2)+min(0ll,p[i]));
            //cout<<i<<' '<<x<<' '<<dp[x]<<endl;
        }
    }
    //cout<<sum<<" "<<dp[1]<<endl;
    if (dp[1]>-inf) printf("YES\n%lld\n",sum-dp[1]); else puts("NO");
    return 0;
}