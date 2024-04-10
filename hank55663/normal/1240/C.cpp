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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
vector<pii> v[500005];
LL dp[500005][2];
int k;
void dfs(int x,int f){
    vector<int> vv;
    LL sum=0;
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x);
            sum+=dp[it.x][0];
            vv.pb(dp[it.x][1]+it.y-dp[it.x][0]);
        }
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    while(vv.size()&&vv.back()<0)vv.pop_back();
    for(int i=0;i<k-1&&i<vv.size();i++){
        sum+=vv[i];
    }
    dp[x][1]=sum;
    if(vv.size()>=k)sum+=vv[k-1];
    dp[x][0]=sum;
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d %d",&n,&k);
        for(int i = 1;i<=n;i++)
            v[i].clear();
        for(int i = 1;i<n;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            v[x].pb(mp(y,w));
            v[y].pb(mp(x,w));
        }
        dfs(1,0);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
    }
}