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
vector<int> v[300005];
int dp[300005];
int ans;
int dfs(int x,int f){
    vector<int> t;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            t.pb(dp[it]);
        }
    }
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    if(t.size()>=2){
        ans=max(ans,t[0]+t[1]+(int)v[x].size()-1);
        dp[x]=v[x].size()-1+t[0];
    }
    else if(t.size()==1){
        ans=max(ans,t[0]+(int)v[x].size());
        dp[x]=v[x].size()-1+t[0];
    }
    else{
        dp[x]=v[x].size();
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        v[i].clear();
        for(int i = 1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        ans=2;
        dfs(1,0);
        printf("%d\n",ans);
    }
}