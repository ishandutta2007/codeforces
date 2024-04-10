#include<bits/stdc++.h>
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
#define last Last
#define MAXK 2500
const int mod = 1000000007;
int b[MAXK]; // bernoulli number
int inv[MAXK+1]; // inverse
int cm[MAXK+1][MAXK+1]; // combinactories
int co[MAXK][MAXK+2]; // coeeficient of x^j when p=i
int add(int x,int y){
    return (x+y)%mod;
}
int mul(LL x,LL y){
    return x*y%mod;
}
int sub(int x,int y){
    return (x-y+mod)%mod;
}
inline int getinv(int x) {
  int a=x,b=mod,a0=1,a1=0,b0=0,b1=1;
  while(b) {
    int q,t;
    q=a/b; t=b; b=a-b*q; a=t;
    t=b0; b0=a0-b0*q; a0=t;
    t=b1; b1=a1-b1*q; a1=t;
  }
  return a0<0?a0+mod:a0;
}
inline void pre() {
  /* combinational */
  for(int i=0;i<=MAXK;i++) {
    cm[i][0]=cm[i][i]=1;
    for(int j=1;j<i;j++)
      cm[i][j]=(cm[i-1][j-1]+cm[i-1][j])%mod;
  }
  /* inverse */
  for(int i=1;i<=MAXK;i++) inv[i]=getinv(i);
  /* bernoulli */
  b[0]=1; b[1]=getinv(2); // with b[1] = 1/2
  for(int i=2;i<MAXK;i++) {
    if(i&1) { b[i]=0; continue; }
    b[i]=1;
    for(int j=0;j<i;j++)
      b[i]=sub(b[i],
               mul(cm[i][j],mul(b[j], inv[i-j+1])));
  }
  /* faulhaber */
  // sigma_x=1~n {x^p} =
  //   1/(p+1) * sigma_j=0~p {C(p+1,j)*Bj*n^(p-j+1)}
  for(int i=1;i<MAXK;i++) {
    co[i][0]=0;
    for(int j=0;j<=i;j++)
      co[i][i-j+1]=mul(inv[i+1], mul(cm[i+1][j], b[j]));
  }
}
void solve(){
   LL n,k;
   scanf("%lld %lld",&n,&k);
   LL myco[505];
   pre();
   MEM(myco);
   myco[1]=1;
  // MEM(myco);
   LL ans[205];
   ans[0]=1;
   for(int i = 1;i<=k;i++){
       LL tmpmyco[505];
       MEM(tmpmyco);
       for(int j=0;j<=500;j++){
           if(myco[j])
           for(int a = 0;a<=500;a++){
               tmpmyco[a]+=mul(myco[j],co[j][a]);
               tmpmyco[a]%=mod;
           }
       }
        for(int j = 0;j<=500;j++){
            tmpmyco[j]=sub(tmpmyco[j],myco[j]);
        }
       LL sum=0,m=n;
       for(int j = 1;j<=500;j++){
           sum=add(sum,mul(tmpmyco[j],m));
        //   printf("%lld %lld\n",tmpmyco[j],m);
           m=mul(m,n);
           
       }
      // printf("%lld\n",sum);
       MEM(myco);
       for(int j = 1;j<=500;j++)myco[j+1]=tmpmyco[j];
        ans[i]=sum;
        //  printf("%lld ",ans[i]);
        if(i>1)
        ans[i]+=ans[i-2];
        if(i>=n)ans[i]=ans[i-2];
        ans[i]%=mod;
        printf("%lld ",ans[i]);
   }
   printf("\n");

}
int main(){
    int t=1;00000;
 //   scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/