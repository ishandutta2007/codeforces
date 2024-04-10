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
#define index Index
#define MXN 300000
const int mod=998244353;
vector<int> v[105];
int ok[105][105];
vector<int> stk;
int dp[205];
int vis[105];
void dfs(int x,int f){
    vis[x]=1;
    stk.pb(x);
    for(auto it:v[x]){
        if(!vis[it])
        dfs(it,x);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    pii p[105];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int i = 0;i<n;i++){
        vector<pii> v;
        for(int j = 0;j<n;j++){
            if(i!=j){
                v.pb(mp(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y),j));
            }
        }
        sort(v.begin(),v.end());
        ok[i][v[0].y]=1;
        for(int j = 1;j<v.size();j++){
            if(v[j].x==v[j-1].x){
                ok[i][v[j].y]=1;
            }
            else{
                break;
            }
        }
    }
    for(int t=0;t<n;t++)
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(ok[i][j]&&!ok[j][i]){
                for(int k=0;k<n;k++){
                    ok[i][k]=0;
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(ok[i][j]&&ok[j][i])v[i].pb(j),v[j].pb(i);
        }
    }
    dp[0]=1;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs(i,0);
            int ok=1;
            for(auto it:stk){
                if(v[it].size()!=stk.size()-1)ok=0;//printf("%d %d\n",it,v[it].size());
               // printf("%d ",it);
            }
           // printf("?%d %d %d\n",i,stk.size(),ok);
          //  stk.clear();
            if(stk.size()==1)ok=0;
            if(ok){
                for(int j = n;j>=0;j--){
                    dp[j+1]+=dp[j];
                    dp[j+1]%=mod;
                    dp[j+stk.size()]+=dp[j];
                    dp[j+stk.size()]%=mod;
                    dp[j]=0;
                }
            }
            else{
                for(int j = n;j>=0;j--){
                    dp[j+stk.size()]=dp[j];
                    dp[j]=0;
                }
            }
            stk.clear();
        }
    }
    LL ans=0;
    LL fra=1;
    for(int i = 1;i<=n;i++){
        fra=fra*(n-i+1)%mod;
        ans+=dp[i]*fra%mod;
        ans%=mod;
     //  printf("%d ",dp[i]);
    }
  //  printf("\n");
    printf("%lld\n",ans);
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}