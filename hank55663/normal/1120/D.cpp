#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
LL dp[200005][2];//1 buy,0 no buy
vector<int> from[200005][2];
vector<int> v[200005];
LL cost[200005];
void dfs(int x,int f){
    LL Max=0;
    vector<int> Maxi;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            dp[x][1]+=dp[it][1];
            if(dp[it][1]-dp[it][0]>Max){
                Max=dp[it][1]-dp[it][0];
                Maxi.clear();//it;
            }
            if(dp[it][1]-dp[it][0]==Max){
                Maxi.pb(it);
            }
        }
    }
    for(auto it:Maxi)
    from[x][0].pb(it);
    dp[x][0]=dp[x][1]-Max;
    if(v[x].size()==1&&f!=0){
        dp[x][1]=cost[x];
        Max=cost[x];
        from[x][1].pb(-1);
    }
    else if(Max>cost[x]){
        dp[x][1]-=Max;
        dp[x][1]+=cost[x];
        for(auto it:Maxi)
        from[x][1].pb(it);
    }
    else{
        if(Max==cost[x])
            for(auto it:Maxi)
                from[x][1].pb(it);
        from[x][1].pb(0);
    }
  //  printf("%d %d %d\n",x,dp[x][0],dp[x][1]);
}
vector<int> ans;
int vis[200005][2];
void ask(int a,int b,int f){
    if(vis[a][b])return ;
    vis[a][b]=1;
    int ok=0;
    for(auto xxx:from[a][b]){
        if(ok==2&&xxx!=0){
            ask(xxx,0,a);
            continue;
        }
        if(b==1){
        //   printf("%d %d\n",a,from[a][b]);
            if(xxx!=0){
                if(!ok)
                ans.pb(a);
                for(auto it:v[a]){
                    if(it!=f){
                        if(it==xxx)
                            ask(it,0,a);
                        else
                            ask(it,1,a);
                    }
                }
                ok++;
            }
            else{
                for(auto it:v[a]){
                    if(it!=f){
                        ask(it,b,a);
                    }
                }
            }
        }
        else{
            for(auto it:v[a]){
                if(it!=f){
                    if(it==xxx)
                        ask(it,0,a);
                    else   
                        ask(it,1,a);
                }
            }
            ok++;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%lld",&cost[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    ask(1,1,0);
    printf("%lld %d\n",dp[1][1],ans.size());
    sort(ans.begin(),ans.end());
    for(auto it:ans)
    printf("%d ",it);
}