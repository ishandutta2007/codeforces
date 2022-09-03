#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
const int mod=1e9+7;
#define MXN 2005
vector<pair<pii,int> > v[100005];
vector<int> ans[100005];
LL tot[100005];
LL dp[100005][105],from[100005][105];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v[i].clear();
        ans[i].clear();
    }
    for(int i = 1;i<=m;i++){
        int e,t,p;
        scanf("%d %d %d",&e,&t,&p);
        v[e].pb(mp(mp(t,p),i));
    }
    for(int i = 1;i<=n;i++){
        for(int k=0;k<=v[i].size();k++)
        for(int j=0;j<105;j++){
            dp[k][j]=1e18;//.resize(v[i].size()+1,1e18);
            from[k][j]=0;//.resize(v[i].size()+1,0);
        }
        dp[0][0]=0;
        for(int j=0;j<v[i].size();j++){
            for(int k = 0;k<=100;k++){
                int ta=v[i][j].x.y+k;
                if(k+v[i][j].x.y>=100){
                    ta=100;
                }
                if(dp[j+1][ta]>dp[j][k]+v[i][j].x.x){
                    dp[j+1][ta]=dp[j][k]+v[i][j].x.x;
                    from[j+1][ta]=k;
                }
                if(dp[j+1][k]>dp[j][k]){
                    dp[j+1][k]=dp[j][k];
                    from[j+1][k]=k;
                }
            }

        }
        tot[i]=dp[v[i].size()][100];
     //   printf("%lld ",tot[i]);
        int now=100;
        for(int j = v[i].size();j>0;j--){
            if(from[j][now]!=now){
                ans[i].pb(v[i][j-1].y);
            }
            now=from[j][now];
        }
    }
    LL aans=0;
        vector<int> res;
    for(int i = 1;i<=n;i++){
        aans+=tot[i];
        if(aans>a[i]){
            printf("-1\n");
            return;
        }
        for(auto it:ans[i])res.pb(it);
    }
    printf("%d\n",res.size());
    for(auto it:res)printf("%d ",it);
    printf("\n");

}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
342475
784728
394591
622354
489948
37187.5
586271
70934.1
463806
235009
528719
786392
717050
936731
250005
382783
953168
610086
*/