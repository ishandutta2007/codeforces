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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
 int a[1000005];
 int dp[1000005];
        int pre[1000005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
       
        a[0]=0;

        for(int i = 1;i<=n;i++){
            char c;
            scanf(" %c",&c);
            a[i]=c-'0';
            pre[i]=pre[i-1]+a[i];
        }
        
        dp[0]=0;
        int ans=pre[n];
        for(int i = 1;i<=n;i++){
            if(a[i]==0){
                dp[i]=pre[i-1]+1;
            }
            else{
                dp[i]=pre[i-1];
            }
            if(i<=k){
            }
            else{
                if(a[i]==0){
                    dp[i]=min(dp[i],dp[i-k]+pre[i-1]-pre[i-k]+1);
                }  
                else{
                    dp[i]=min(dp[i],dp[i-k]+pre[i-1]-pre[i-k]);
                }
            }
            ans=min(ans,dp[i]+pre[n]-pre[i]);
        }
        printf("%d\n",ans);
    }

}

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/