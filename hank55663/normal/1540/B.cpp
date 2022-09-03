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
int dp[205][205];
LL mod=1e9+7;
LL inv=(mod+1)/2;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL ans[205][205];
int dis[205][205];
void solve(){
    dp[0][0]=1;
    for(int i = 0;i<200;i++){
        for(int j = 0;j<200;j++){
            dp[i+1][j]+=dp[i][j]*inv%mod;
            dp[i][j+1]+=dp[i][j]*inv%mod;
            dp[i+1][j]%=mod;
            dp[i][j+1]%=mod;
        }
    }
    for(int i = 1;i<=200;i++){
        for(int j  =1;j<=200;j++){
            for(int k = 0;k<j;k++)ans[i][j]+=dp[i-1][k]*inv%mod,ans[i][j]%=mod;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=n;j++){
            dis[i][j]=1e9+7;
        }
        dis[i][i]=0;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        dis[x][y]=dis[y][x]=1;
    }
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    LL res=0;
    LL invn=f_pow(n,mod-2);
    for(int i = 1;i<=n;i++){
        for(int j =1;j<i;j++){
            for(int k = 1;k<=n;k++){
                if(dis[k][i]+dis[i][j]==dis[k][j])res+=invn;
                else if(dis[k][j]+dis[i][j]==dis[k][i]);
                else {
                  //  printf("!\n");
                    LL tot=(dis[k][i]+dis[k][j]-dis[i][j])/2;
                    LL a=dis[k][i]-tot,b=dis[k][j]-tot;
                    res+=invn*ans[a][b]%mod;
                }
                res%=mod;
              //  printf("%d %d %d %lld %d %d %d\n",i,j,k,res,dis[i][j],dis[i][k],dis[j][k]);
            }
        }
    }
    printf("%lld\n",res);
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