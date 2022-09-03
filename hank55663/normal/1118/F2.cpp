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
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int val[300005];
vector<int> v[300005];
vector<int> color[300005];
int dep[300005];
int p[300005];
void dfs(int x,int f){
    p[x]=f;
    dep[x]=dep[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
}
int mod=998244353;
LL dp[300005][2];
int vis[300005];
void dfs2(int x,int f){
    vis[x]=1;
    if(val[x]){
        dp[x][1]=1;
        return ;
    }
    dp[x][0]=1;
    vector<LL> value1,value2;
    value1.pb(1);
    value2.pb(1);
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x);
            dp[x][0]*=(dp[it][0]+dp[it][1]);
            value1.pb(dp[it][0]+dp[it][1]);
            value2.pb(dp[it][1]);
            dp[x][0]%=mod;
        }
    }
    value1.pb(1);
    value2.pb(1);
    vector<LL> pre,suf(value1.size());
    pre.pb(1);
    for(int i=1;i<value1.size();i++){
        pre.pb(pre[i-1]*value1[i]%mod);
    }
    suf[suf.size()-1]=1;
    for(int i=suf.size()-2;i>=0;i--){
        suf[i]=suf[i+1]*value1[i]%mod;
    }
    dp[x][1]=0;
    for(int i=1;i<value1.size()-1;i++){
        dp[x][1]+=suf[i+1]*pre[i-1]%mod*value2[i]%mod;
        dp[x][1]%=mod;
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
        color[val[i]].pb(i);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    for(int i=1;i<=k;i++){
        priority_queue<pii > pq;
        for(auto it:color[i]){
            pq.push(mp(dep[it],it));
           // printf("%d %d\n",it,dep[it]);
        }
        while(pq.size()!=1){
            pii hi=pq.top();
          //  printf("%d %d %d\n",i,hi.x,hi.y);
            pq.pop();
            if(val[p[hi.y]]!=0&&val[p[hi.y]]!=i){
                printf("0\n");
                return 0;
            }
            if(val[p[hi.y]]==0){
                val[p[hi.y]]=i;
                assert(hi.x-1==dep[p[hi.y]]);
                pq.push(mp(hi.x-1,p[hi.y]));
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    printf("%d ",val[i]);
    printf("\n");*/
    LL ans=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&val[i]==0){
          //  printf("%d\n",i);
            dfs2(i,0);
            ans*=dp[i][1];
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
}