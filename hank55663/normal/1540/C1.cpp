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
#define MXN 200005
int pool[105][600005];
int *dp[105];
int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    for(int i= 0;i<=100;i++){
        dp[i]=pool[i]+1;
    }
    int l[105],r[105];
     LL ans=1;
    for(int i = 1;i<=n;i++){
        l[i]=0;
        scanf("%d",&r[i]);
         ans=ans*(r[i]+1)%mod;
    }
   
    for(int i = 2;i<=n;i++){
        int x;
        scanf("%d",&x);
       
        for(int k = i ;k<=n;k++){
            l[k]-=x;
            r[k]-=x;
        }
    }
   // for(int i =  1;i<=n;i++){
    // //   printf("%d %d\n",l[i],r[i]);
   // }
    int q;
    scanf("%d",&q);
    for(int i = 1 ;i<=q;i++){
        int x;
        scanf("%d",&x);
        if(x>=101)printf("0 ");
        else if(x<=-5050){
            printf("%lld ",ans);
        }
        else{
            for(int i = 1;i<=n;i++)l[i]-=x,r[i]-=x;//printf("%d %d\n",l[i],r[i]);
            dp[0][0]=1;
            int Max=0;
            LL sum=0;
            for(int i = 1;i<=n;i++){
                for(int j = 0;j<=600000;j++){
                    dp[i-1][j]+=dp[i-1][j-1];
                    dp[i-1][j]%=mod;
                }
                Max+=r[i];
                
                for(int j = 0;j<=Max;j++){
                    dp[i][j]=dp[i-1][max(min(j-l[i],600000),-1)]-dp[i-1][max(j-r[i]-1,-1)];
                    dp[i][j]=(dp[i][j]%mod+mod)%mod;
                 //   printf("%d ",dp[i][j]);
                    if(i==n)sum+=dp[i][j],sum%=mod;
                }
              //  printf("\n");
            }
            for(int i = 1;i<=n;i++)l[i]+=x,r[i]+=x;
            printf("%lld ",sum);
        }
    }
    printf("\n");
}
int main(){
    int t=1;//00;
   // scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/