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
int pool[105][10005];
int *dp[105];
const int mod=1e9+7;
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
        r[i]=100;
        scanf("%d",&r[i]);
         ans=ans*(r[i]+1)%mod;
    }
    int b[105];
    b[1]=0;
    for(int i = 2;i<=n;i++){
        scanf("%d",&b[i]);
        //b[i]=100;
    }
    int q;
    scanf("%d",&q);
    map<int,LL> cache;
    for(int i = 0 ;i<q;i++){
        int x=i;
        scanf("%d",&x);
        int ll=0,rr=0;
        int add=0;
        int ok=0,ok2=1;
        for(int j = 1;j<=n;j++){
            ll+=l[j];
            rr+=r[j];
            add+=b[j];
            ll-=add;
            rr-=add;
            ll-=x;
            rr-=x;
           // printf("%d %d\n",ll,rr);
            if(rr<0){
                ok=1;
                printf("0\n");
                break;
            }
            if(ll<0)ok2=0;
        }
        if(ok)continue;
        if(ok2){
            printf("%lld\n",ans);
            continue;
        }
        if(cache.find(x)!=cache.end())printf("%lld\n",cache[x]);
        else if(x>=101)printf("0\n");
        else if(x<=-5050){
            printf("%lld\n",ans);
        }
        else{
           // for(int i = 1;i<=n;i++)l[i]-=x,r[i]-=x;//printf("%d %d\n",l[i],r[i]);
            int sum=0;
            dp[0][0]=1;
            int Max=0;
            LL ans=0;
            LL add=0;
            for(int i = 1;i<=n;i++){
                Max+=r[i];
                for(int j = 0;j<=Max+r[i];j++){
                    dp[i-1][j]+=dp[i-1][j-1];
                    if(dp[i-1][j]>=mod)
                      dp[i-1][j]-=mod;
                }
                
                sum+=x;
                add+=b[i];
                sum+=add;
               // printf("%d\n",sum);
                for(int j = 0;j<=Max;j++)dp[i][j]=0;
                for(int j = max(sum,0);j<=Max;j++){
                    dp[i][j]=dp[i-1][max(j-l[i],-1)]-dp[i-1][max(j-r[i]-1,-1)];
                    if(dp[i][j]<0)dp[i][j]+=mod;
                    if(i==n)ans+=dp[i][j],ans%=mod;
                }
                for(int j = Max;j>=0;j--){
                    dp[i-1][j]=0;
                }
              //  printf("\n");
            }
            //for(int i = 1;i<=n;i++)l[i]+=x,r[i]+=x;
            printf("%lld\n",cache[x]=ans);
        }
    }
  //  printf("\n");
}
int main(){
    int t=1;//00;
   // scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
0 -2 -3
-1 1 0
*/