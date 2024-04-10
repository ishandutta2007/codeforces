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
LL cnt[20000005];
int f[20000005];
LL dp[20000005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    cnt[1]=n;
    for(int i = 2;i<=20000000;i++){
        if(!f[i]){
            for(int j = 20000000/i*i;j>=i;j-=i){
                cnt[j/i]+=cnt[j];
                f[j]=i;
            }
        }
    }
    dp[1]=n;
    LL ans=0;
    for(int i = 2;i<=20000000;i++){
        int now=i;
        while(now!=1){
            int ff=f[now];
            dp[i]=max(dp[i/ff]+cnt[i]*(i/ff*(ff-1)),dp[i]);
            now/=ff;
        }
        ans=max(ans,dp[i]);
    }
    printf("%lld\n",ans);
}

int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/