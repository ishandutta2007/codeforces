#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int t[200005];
int h[200005];
vector<int> v[200005];
int vis[200005];
LL dp[200005][2];
LL val;
void dfs(int x,int f){
    vis[x]=1;
    LL in=0,out=0;
    vector<LL> vv;
    LL sum=0;
    for(auto it:v[x]){
        if(it!=f){
            if(h[it]>h[x])out++;
            else if(h[it]<h[x])in++;
            else{
                dfs(it,x);
                sum+=dp[it][0];
                in++;
                vv.pb(dp[it][1]-dp[it][0]);
            }
        }
    }
    sort(vv.begin(),vv.end());
    val=sum+max(in,out)*t[x];
    dp[x][0]=sum+max(in,out+1)*t[x];
    dp[x][1]=sum+max(in+1,out)*t[x];
    for(auto it:vv){
        sum+=it;
        in--;
        out++;
        val=min(val,sum+max(in,out)*t[x]);
        dp[x][0]=min(dp[x][0],sum+max(in,out+1)*t[x]);
        dp[x][1]=min(dp[x][1],sum+max(in+1,out)*t[x]);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
           // printf("%d %lld\n",i,val);
            ans+=val;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/