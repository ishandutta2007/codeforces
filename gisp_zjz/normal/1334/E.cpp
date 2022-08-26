#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int maxn=5e5+3;
int f[maxn],nf[maxn],inv[maxn],cc;
ll D,x,y,p[maxn];
int calc(ll x,ll y){
    int ans=1,tot=0;
    for (int i=1;i<=cc;i++){
        int s=0;
        while (x%p[i]==0) x/=p[i],s++;
        while (y%p[i]==0) y/=p[i],s--;
        tot+=s; ans=1ll*ans*nf[s]%M;
    }
    ans=1ll*ans*f[tot]%M;
    return ans;
}
int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    scanf("%lld",&D);
    ll j=2;
    while (j*j<=D){
        if (D%j==0){
            p[++cc]=j;
            while (D%j==0) D/=j;
        }
        ++j;
    }
    if (D>1) p[++cc]=D;
    int _; scanf("%d",&_);
    while (_--){
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",1ll*calc(x,__gcd(x,y))*calc(y,__gcd(x,y))%M);
    }
    return 0;
}