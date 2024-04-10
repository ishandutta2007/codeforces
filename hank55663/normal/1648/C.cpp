#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
#define MXN 2005
LL fra[200005];
LL inv[200005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL S[200005];
int cnt[200005];
void add(int x,LL k){
 //   printf("%d %lld\n",x,k);
    for(int i = x;i<200005;i+=i&-i){
        S[i]+=k;
        S[i]%=mod;
    }
}
LL query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res%mod;
}
int t[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    fra[0]=1;
    for(int i = 1;i<=n;i++)fra[i]=fra[i-1]*i%mod;
    inv[n]=f_pow(fra[n],mod-2);
    for(int i = n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    LL tot=fra[n];
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        tot=tot*fra[cnt[x]]%mod;
        if(cnt[x]){
            add(x,mod-fra[cnt[x]]*inv[cnt[x]-1]%mod);
        }
        cnt[x]++;
        tot=tot*inv[cnt[x]]%mod;
        add(x,fra[cnt[x]]*inv[cnt[x]-1]%mod);
    }
    for(int i = 0;i<m;i++)scanf("%d",&t[i]);
    LL ans=0;
    for(int i = 0;i<m;i++){
        if(n==i){
            ans++;
            break;
        }
        ans+=query(t[i]-1)*tot%mod*inv[n-i]%mod*fra[n-i-1]%mod;
        ans%=mod;
        if(cnt[t[i]]==0)break;
        int x=t[i];
        add(x,mod-fra[cnt[x]]*inv[cnt[x]-1]%mod);
        tot=tot*fra[cnt[x]]%mod;
        cnt[x]--;
        tot=tot*inv[cnt[x]]%mod;
        if(cnt[x]){
            add(x,fra[cnt[x]]*inv[cnt[x]-1]%mod);
        }
        tot=tot*inv[n-i]%mod;
        tot=tot*fra[n-i-1]%mod;
       // printf("%lld\n",ans);
    }
    printf("%lld\n",ans%mod);
}
int main(){
    int t=1;0000;
      //scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}