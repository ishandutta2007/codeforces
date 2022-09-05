#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL fra[300005];
LL inv[300005];
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    fra[0]=1;
    for(int i = 1;i<=300000;i++)fra[i]=fra[i-1]*i%mod;
    inv[300000]=f_pow(fra[300000],mod-2);
    for(int i = 300000;i>=1;i--)inv[i-1]=inv[i]*i%mod;
    int d[600005];
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&d[i]);
       // d[i]=1e9;
        sum+=d[i];
        d[n+i]=d[i];
    }
    LL tmp=0,r=0;
    LL tot=0;
    for(int i = 0;i<n;i++){
        while((tmp+d[r])*2<=sum){
            tmp+=d[r];
            r++;
        }
       // printf("%lld %lld\n",tmp,sum);
        if((tmp)*2==sum)tot++;
        if(tmp==0)r++;
        else tmp-=d[i];
    }
    tot/=2;
  //  printf("%d\n",tot);
    LL ans=0;
    for(int i = 0;i<m&&i<=tot;i++){
        ans+=f_pow(m-i,n-tot-i)*f_pow(m-i-1,tot-i)%mod*C(tot,i)%mod*fra[m]%mod*inv[m-i]%mod;
           // printf("%lld %lld\n",ans,f_pow(m-i,n-tot-i*2)*f_pow(m-i-1,tot-i)%mod);
    }
    if(tot==m&&n==tot*2)ans+=fra[m];
    ans%=mod;
    printf("%lld\n",ans);
    
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
*/