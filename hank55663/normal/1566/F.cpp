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
#define MXN 3000000
int mod=1e9+7;
pii p[200005];
bool cmp(const pii &p,const pii &q){
    if(p.x==q.x)return p.y>q.y;
    return p.x<q.x;
}
vector<pll> arr[200005];
vector<LL> dp[200005];
void solve(int T){
    int n,m;
    scanf("%d %d",&n,&m);
    LL a[200005];
    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i= 0;i<=n+1;i++)arr[i].clear(),dp[i].clear();
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    sort(p,p+m,cmp);
    vector<pii> v;
    reverse(p,p+m);
    set<int> s;
    for(int i = 1;i<=n;i++)s.insert(a[i]);
    for(int i = 0;i<m;i++){
        if(v.empty()||v.back().y>p[i].y){
            auto it=s.lower_bound(p[i].x);
            if(it!=s.end()&&*it<=p[i].y);
            else
            v.pb(p[i]);
        }
    }
    sort(v.begin(),v.end());
    sort(a+1,a+n+1);
    a[0]=-2e9;
    a[n+1]=2e9;
    for(auto it:v){
    //    printf("!%d %d ",it.x,it.y);
        auto idx=lower_bound(a,a+n+2,it.x)-a-1;
        arr[idx].pb(it);
      //  printf("%d\n",idx);
    }
    dp[0].pb(0);
    for(int i = 0;i<arr[0].size();i++)dp[0].pb(1e12);
    for(int i = 1;i<=n;i++){
        if(arr[i].empty()){
            if(arr[i-1].empty()){
                dp[i].pb(dp[i-1][0]);
            }
            else{
                LL Min=dp[i-1].back();
                for(int j = 0;j<arr[i-1].size();j++){
                    Min=min(Min,dp[i-1][j]+a[i]-arr[i-1][j].y);
                }
                dp[i].pb(Min);
            }
        }
        else{
            if(arr[i-1].empty()){
                dp[i].pb(dp[i-1][0]);
                for(int j = 0;j<arr[i].size();j++){
                    dp[i].pb(dp[i-1][0]+arr[i][j].x-a[i]);
                }
            }
            else{
                LL Min=dp[i-1].back();
                for(int j = 0;j<arr[i-1].size();j++){
                    Min=min(Min,dp[i-1][j]+a[i]-arr[i-1][j].y);
                }
                dp[i].pb(Min);
                for(int j = 0;j<arr[i].size();j++){
                    dp[i].pb(Min+(arr[i][j].x-a[i])*2);
                }
                Min=dp[i-1].back();
                for(int j = 0;j<arr[i-1].size();j++){
                    Min=min(Min,dp[i-1][j]+(a[i]-arr[i-1][j].y)*2);
                }
                for(int j = 0;j<arr[i].size();j++){
                    dp[i][j+1]=min(dp[i][j+1],Min+(arr[i][j].x-a[i]));
                }
            }

        }
       // printf("??? %d %d\n",arr[i].size(),dp[i].size());
       // for(auto it:dp[i])printf("%d ",it);
      //  printf("\n");
    }
    printf("%lld\n",dp[n].back());
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve(i);
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/