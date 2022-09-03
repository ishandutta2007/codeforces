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
#define last Last
#define MAXK 2500
vector<int> v[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    int u[200005];
    for(int i = 0;i<n;i++)scanf("%d",&u[i]);
    LL sum=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        v[u[i]].pb(x);
        sum+=x;
    }
    LL ans[200005];
    fill(ans,ans+n+1,0);
    for(int i = 1;i<=n;i++){
        LL pre[200005];
        pre[0]=0;
        LL sum=0;
        sort(v[i].begin(),v[i].end());
        for(int j = 1;j<=v[i].size();j++){
            pre[j]=pre[j-1]+v[i][j-1];
            sum+=v[i][j-1];
        }
        for(int j = 1;j<=v[i].size();j++){
           // if(j==1)printf("%d %d\n",i,sum);
            ans[j]+=sum-pre[v[i].size()%j];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
    printf("\n");
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
*/