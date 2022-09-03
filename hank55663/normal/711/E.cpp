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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 2000005
const int mod=1e6+3;
LL f_pow(LL a,LL b){
    b=(b%(mod-1)+mod-1)%(mod-1);
    LL res=1,temp=a%mod;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    if(n<=60){
        LL tot=1ll<<n;
        if(k>tot){
            printf("1 1\n");
        return 0;
        }
        
    }
    LL mon=(n%(mod-1)*(k%(mod-1))%(mod-1));
    LL sub=n;
    LL tmp=k-1;
    while(tmp){
        sub+=tmp/2;
        tmp/=2;
    }
   // printf("?\n");
    mon-=sub;
    LL son=1;
    tmp=f_pow(2,n);
    for(LL i = 0;i<k;i++){
      //  if(i%100==0)
       // printf("%lld %lld %lld\n",i,tmp,son);
        son = son *tmp%mod;
        tmp--;
        if(son==0)break;
    }
  //  printf("%lld\n",sub);
    son*=f_pow(f_pow(2,sub),mod-2);
    son%=mod;
    //printf("%lld\n",mon);
    printf("%lld %lld\n",(f_pow(2,mon)-son+mod)%mod,f_pow(2,mon));
    return 0;
}