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
#define MXN 200005
LL sum[200005];
LL sum2[200005];
LL sum3[200005];
LL p[200005];
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
LL getval(int l,int r){
        LL inv=f_pow(sum[l-1],mod-2);
       // printf("%lld %lld\n",((sum2[r]-sum2[l-1])),((sum[r]*inv%mod)*(l-1))%mod);
       // printf("%lld\n",(((sum2[r]-sum2[l-1])-(sum[r]*inv%mod)*(l-1))%mod+mod)%mod*inv);
    //printf("%lld %d %d %lld\n",sum[r]*inv%mod,r,l,((((sum2[r]-sum2[l-1])-(sum[r]*inv%mod)*(l-1))%mod+mod)%mod*inv+sum[r]*inv%mod*(r-l+1)%mod));
  //  printf("%lld %lld\n",(((sum2[r]-sum2[l-1])-(sum[r]*inv%mod)*(l-1))%mod+mod)%mod*inv,sum[r]*inv%mod*(r-l+1)%mod);
  //  printf("%lld\n",sum[r]*inv%mod);
   // printf("%lld %lld\n",sum2[r]-sum2[l-1],(sum[r]*inv%mod)*(l-1));
    return ((((sum2[r]-sum2[l-1])-((sum3[r]-sum3[l-1]+mod)%mod)*(l-1))%mod+mod)%mod*inv+sum[r]*inv%mod*(r-l+1)%mod)%mod*
    f_pow((sum[r]*inv%mod),mod-2)%mod;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
        scanf("%lld",&p[i]);
    sum[0]=1;
    for(int i = 1;i<=n;i++){
        sum[i]=sum[i-1]*p[i]%mod*f_pow(100,mod-2)%mod;
    }
    sum2[0]=0;
    for(int i = 1;i<=n;i++){
        sum2[i]=(sum2[i-1]+sum[i-1]*(100-p[i])%mod*f_pow(100,mod-2)%mod*i)%mod;
        sum3[i]=(sum3[i-1]+sum[i-1]*(100-p[i])%mod*f_pow(100,mod-2)%mod)%mod;
    }
    set<int> s;
    s.insert(n+1);
    s.insert(1);
    LL now=getval(1,n);
    //printf("%lld %lld %lld %lld\n",now,sum2[n],(sum2[n]+sum[n]*n),f_pow(sum[n],mod-2)%mod);
    while(m--){
        int x;
        scanf("%d",&x);
        if(s.find(x)!=s.end()){
            auto it=s.upper_bound(x);
            auto it2=prev(prev(it));
            now+=getval(*it2,*it-1);
            s.erase(x);
            now-=getval(*it2,x-1);
            now-=getval(x,*it-1);
        }
        else{
            auto it=s.upper_bound(x);
            auto it2=prev(it);
            now-=getval(*it2,*it-1);
            s.insert(x);
            now+=getval(*it2,x-1);
           // printf("%d %d\n",getval(*it2,x-1),getval(x,*it-1));
            now+=getval(x,*it-1);
            now%=mod;
        }
        now=(now%mod+mod)%mod;
        printf("%lld\n",now);
    }
}
/*
x = 20*(1+x)+6*
x = 1/2(1+x)+1/4(2+x)+2/4
(1*a+2*a*b+3*a*b*c+4*a*b*c*d+5*a*b*c*d*e)
1/4x=6/4
*/