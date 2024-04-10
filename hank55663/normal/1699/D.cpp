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
#define double long double
using namespace std;
int Max[5005][5005];
int a[5005];
int dp[5005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("1\n");
        return;
    }
    for(int i = 1;i<=n;i++){
        int cnt[5005];
        MEM(cnt);
        int x=0;
        for(int j = i;j<=n;j++){
            cnt[a[j]]++;
            x=max(x,cnt[a[j]]);
            Max[i][j]=x;
         //   printf("%d ",Max[i][j]);
        }
      //  printf("\n");
    }    
    dp[1]=1;
    int ans=0;
    if(n%2==1){
        int tot=n-1;
        if(Max[2][n]*2<=tot){
            ans=max(ans,dp[1]);
        }
    }
    //int ans=0;
    for(int i = 2;i<=n;i++){
        dp[i]=-1e9;
        for(int j = i-1;j>=1;j--){
            if(a[i]==a[j]&&i%2!=j%2){
                int tot=i-j-1;
                if(Max[j+1][i-1]*2<=tot){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        if(i%2&&Max[1][i-1]*2<=i-1)dp[i]=max(dp[i],1);
       // printf("%d ",dp[i]);
        if(n%2==i%2){
            int tot=n-i;
            if(Max[i+1][n]*2<=tot){
                ans=max(ans,dp[i]);
            }
        }
    }
    printf("%d\n",ans);
    
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/