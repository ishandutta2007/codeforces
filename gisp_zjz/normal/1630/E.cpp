#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=998244353;
const int inf=1000000009;
const int maxn=1000006;
int inv[maxn],a[maxn],phi[maxn],cnt[maxn],f[maxn],nf[maxn],n,_;
vector<int> b;
int pow_(int x,int y){
    int ret=1;
    while (y){
        if (y&1) ret=1ll*ret*x%M;
        x=1ll*x*x%M; y>>=1;
    }
    return ret;
}
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    for (int i=1;i<maxn;i++) phi[i]=i;
    for (int i=1;i<maxn;i++) for (int j=2;j*i<maxn;j++) phi[i*j]-=phi[i];
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) cnt[i]=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int g=0; b.clear();
        for (int i=1;i<=n;i++) {
            if (!cnt[i]) continue;
            b.pb(cnt[i]); g=__gcd(g,cnt[i]);
        }
        if (g==n){puts("1");continue;}
        int tot=0,sum=0;
        for (int i=1;i<=g;i++) if (g%i==0){
            int m=n/i,cnt=f[m],val=m;
            for (auto x:b){
                int y=x/i;
                cnt=1ll*cnt*nf[y]%M;
                sub(val,1ll*y*(y-1)%M*inv[m-1]%M);
            }
            val=1ll*val*i%M;
            cnt=1ll*cnt*phi[i]%M;
            add(sum,1ll*val*cnt%M);
            add(tot,cnt);
        }
        int ans=1ll*sum*pow_(tot,M-2)%M;
        printf("%d\n",ans);
    }
    return 0;
}