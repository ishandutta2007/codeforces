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
#define index Index
int cnt[5005][5005];
int rcnt[5005][5005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n+2;i++){
        for(int j=0;j<=n+2;j++)cnt[i][j]=0,rcnt[i][j]=0;
    }
    int a[5005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j = 1;j<=n;j++){
            cnt[i][j]=cnt[i-1][j];
            if(j>=a[i])cnt[i][j]++;
        }
    }
    for(int i = n;i>=1;i--){
        for(int j = 1;j<=n;j++){
            rcnt[i][j]=rcnt[i+1][j];
            if(j>=a[i])rcnt[i][j]++;
        }
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            ans+=cnt[i-1][a[j]]*rcnt[j+1][a[i]];
          //  printf("%d %d %lld\n",i,j,ans);
        }
    }
    printf("%lld\n",ans);
}  
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}