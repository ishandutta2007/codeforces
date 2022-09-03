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
#define ld long double
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    LL m;
    scanf("%lld",&m);
    LL mom=m%mod;
    LL tot=(mom*mom%mod*mom%mod*2+mom*mom%mod*6%mod+4*mom)%mod;
    tot=tot*f_pow(12,mod-2)%mod;
    LL n3=0,n2=0,n1=0;
    LL last=0;
    for(LL i = 1;i*i<=m;i++){
        LL x=((i)*(i)-1)%mod;
        n3+=x*x%mod*x%mod;
        n2+=x*x%mod;
        n1+=x;
        n3%=mod;
        n2%=mod;
        n1%=mod;
        last++;
    }
    LL ans=tot*last%mod-(2*n3+6*n2+4*n1)%mod*f_pow(12,mod-2)%mod;
    ans-=(mom*n2%mod+mom*n1-n3-n2)%mod*f_pow(2,mod-2)%mod;
    ans=(ans%mod+mod)%mod;
   // printf("%lld %lld %lld %lld %lld\n",ans,last,n3,n2,n1);
    //printf("%lld %lld\n",ans,tot);
    for(LL i=1;i*i<=m;i++){
        while(1){
            if(last*last+i*i>m){
                LL x=((last)*(last)+(i-1)*(i-1)-1)%mod;
             //   printf("%lld %lld\n",last,x);
                n3-=x*x%mod*x%mod;
                n2-=x*x%mod;
                n1-=x;
                n3=(n3%mod+mod)%mod;
                n2=(n2%mod+mod)%mod;
                n1=(n1%mod+mod)%mod;
                last--;
            }
            else break;
        }
        LL add=((i*i)-(i-1)*(i-1))%mod;
        n3=(n3+3*n2%mod*add%mod+3*n1%mod*add%mod*add%mod+last*add%mod*add%mod*add%mod)%mod;
        n2=(n2+2*add%mod*n1+last*add%mod*add%mod)%mod;
        n1=(n1+(last*add)%mod)%mod;
        ans+=tot*last;
        ans-=(2*n3+6*n2+4*n1)%mod*f_pow(12,mod-2)%mod;
        ans-=(mom*n2%mod+mom*n1-n3-n2)%mod*f_pow(2,mod-2)%mod;
        ans=(ans%mod+mod)%mod;
        
      //  printf("%lld %lld %lld %lld %lld\n",ans,last,n3,n2,n1);
    }
    printf("%lld\n",(ans*4+tot)%mod);
}