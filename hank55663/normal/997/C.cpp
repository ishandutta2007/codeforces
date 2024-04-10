#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
#define N 6000005
#define rank Rank
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL fra[1000005];
LL inv[1000005];
int C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    fra[0]=1;
    for(int i = 1;i<1000005;i++)
        fra[i]=fra[i-1]*i%mod;
    inv[1000004]=f_pow(fra[1000004],mod-2);
    for(int i = 1000003;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    LL n;
    scanf("%lld",&n);
    LL ans=f_pow(3,n*n);
    for(int i = 1;i<=n;i++){
        if(i&1)ans-=f_pow(3,n*n-n*i)*f_pow(3,i)%mod*2%mod*C(n,i)%mod;
        else ans+=f_pow(3,n*n-n*i)*f_pow(3,i)%mod*2%mod*C(n,i)%mod;
    }
  //  printf("%lld\n",ans);
    for(int i = 1;i<=n;i++){
        LL x=n-i;
        LL tmp=(f_pow(f_pow(3,x)-1,n)-f_pow(3,n*x))%mod;
        /*for(int j=1;j<=n;j++){
            if(j&1)tmp-=f_pow(3,n*x-x*j)*C(n,j);
            else tmp+=f_pow(3,n*x-x*j)*C(n,j);
        }*/       // printf("%lld\n",tmp+f_pow(3,n*x));
        if(i&1)
        ans-=tmp*C(n,i)%mod*3%mod;
        else
        ans+=tmp*C(n,i)%mod*3%mod;
    }
    printf("%lld\n",((f_pow(3,n*n)-ans)%mod+mod)%mod);
    
}