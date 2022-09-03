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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int mobi[100005];
int p[100005];
int dp[50][100005];
const int mod=998244353;
int cal(pii *p,int n,int m){
    dp[0][0]=1;
    for(int i = 1;i<=m;i++)dp[0][i]=1;
    for(int i = 1;i<=n;i++){
        if(p[i].x>p[i].y)return 0;
        for(int j = 1;j<=m;j++){
            if(j-p[i].y>0)
            dp[i][j]=((dp[i-1][j-p[i].x]-dp[i-1][j-p[i].y-1])%mod+mod)%mod;
            else if(j-p[i].x<0){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j-p[i].x];
            }
           // printf("%d ",dp[i][j]);
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
      //  printf("\n");
    }
    return dp[n][m];
}
void solve(){
    fill(mobi,mobi+100000,1);
    for(int i = 2;i<=100000;i++){
        if(p[i]==0){
            for(int j = i;j<=100000;j+=i){
                p[j]=1;
                mobi[j]*=-1;
                if(j/i%i==0)mobi[j]=0;
            }
        }
    }
    int n,m;
    scanf("%d %d",&n,&m);
    pii p[55];
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    LL ans=0;
    for(int i = 1;i<=m;i++){
        pii p2[55];
        for(int j = 1;j<=n;j++)p2[j]=mp((p[j].x+i-1)/i,p[j].y/i);
        if(mobi[i]){
            
            ans+=mobi[i]*cal(p2,n,m/i);
         //   printf("%d %d\n",i,ans);
            ans=(ans%mod+mod)%mod;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;//00;//00;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/