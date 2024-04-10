#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=1000000007;
const int inf=1000000009;
const int maxn=1000006;
ll a[maxn],sum[maxn],b[2],mn[maxn];
int _,n,m,f[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&m);
        int g=0;
        for (int i=0;i<n;i++) scanf("%lld",&a[i]);
        for (int i=1;i<=m;i++){
            int x;scanf("%d",&x);
            g=__gcd(g,x);
        }
        for (int i=0;i<g;i++) mn[i]=inf,f[i]=0,sum[i]=0;
        for (int i=0;i<n;i++){
            if (a[i]<0) f[i%g]^=1;
            sum[i%g]+=a[i];
            mn[i%g]=min(mn[i%g],abs(a[i]));
        }
        b[0]=b[1]=0;
        for (int i=0;i<g;i++) b[f[i]]+=mn[i];
        ll ans=0;
        for (int i=0;i<n;i++) ans+=abs(a[i]);
        ans-=min(b[0],b[1])*2;
        printf("%lld\n",ans);
    }
    return 0;
}