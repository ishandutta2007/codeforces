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
static const double INF = 2147483647;
int dp[21][1<<21];
int a[21][21];
int inv[21][21];
const int mod=31607;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int aa[21];
int sum[21];
int tott;
int dfs(int i,int n,int cnt,int val){
    if(i==n){
        int sum[2]={1,0};
        for(int i = 0;i<n;i++){
            sum[0]=sum[0]*(1-aa[i]+mod)%mod;
           // printf("%d ",aa[i]*1000%mod);
        }
      //  printf("\n");
        if(cnt&1){
           // printf("?\n");
            return (mod-sum[0])*val%mod;
        }
        
        else{
         //   printf("!\n");
         return (sum[0])*val%mod;
        }
    }
    else{
        int res=dfs(i+1,n,cnt,val);
        for(int j = 0;j<n;j++){
            aa[j]=aa[j]*inv[i][j]%mod;
        }
        res+=dfs(i+1,n,cnt+1,val*sum[i]%mod);
        for(int j = 0;j<n;j++){
            aa[j]=aa[j]*a[i][j]%mod;
        }
        return res%mod;
    }
}
int cal(int n){
    fill(aa,aa+n,1);
    fill(sum,sum+n,1);
    tott=1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
          //  printf("%d ",a[i][j]);
            aa[j]=aa[j]*a[i][j]%mod;
            sum[i]=sum[i]*a[i][j]%mod;
            tott*=a[i][j];
            tott%=mod;
        }
      //  printf("\n");
    }
    return dfs(0,n,0,1);
}
void solve(){
    int n;
    scanf("%d",&n);
    int ori[21][21],oriv[21][21];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&a[i][j]);
        
          //  a[i][j]=rand()%9999+1;
            a[i][j]=a[i][j]*f_pow(10000,mod-2)%mod;
            inv[i][j]=f_pow(a[i][j],mod-2);
            ori[i][j]=a[i][j];
            oriv[i][j]=inv[i][j];
        }
    }
    int ans=cal(n);
    //  printf("!!!%lld\n",ans);
    int tot=1;
    for(int i = 0;i<n;i++){
        tot=tot*a[i][i]%mod;
        a[i][i]=1;
        inv[i][i]=1;
    }
   // printf("!!!%d\n",cal(n));
    ans=((ans-tot*cal(n))%mod+mod)%mod;
    tot=1;
   //  printf("%lld\n",ans);
    for(int i = 0;i<n;i++){
        a[i][i]=ori[i][i];
        inv[i][i]=oriv[i][i];
        tot=tot*a[i][n-i-1]%mod;
        a[i][n-i-1]=1;
        inv[i][n-i-1]=1;
    }
    // printf("!!!%d\n",cal(n));
    ans=((ans-tot*cal(n))%mod+mod)%mod;
   // printf("???%lld\n",ans);
    for(int i = 0;i<n;i++){
        tot=tot*a[i][i]%mod;
        a[i][i]=1;
        inv[i][i]=1;
    }
    // printf("!!!%d\n",cal(n));
    ans=(ans+tot*cal(n))%mod;
    printf("%d\n",(1-ans+mod)%mod);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}