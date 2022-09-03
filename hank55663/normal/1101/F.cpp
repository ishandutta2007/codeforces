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
#define hash Hash
int dp[405][405][405];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[405];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int l=1;l<=n;l++){
        for(int r=l+1;r<=n;r++)
        dp[l][0][r]=a[r]-a[l];
        for(int k=1;k<=n;k++){
            int opt=l+k;
            for(int r=l+k+1;r<=n;r++){
               // printf("%d %d %d\n",l,r,k);
                while(opt!=r&&max(dp[l][k-1][opt+1],a[r]-a[opt+1])<max(dp[l][k-1][opt],a[r]-a[opt]))opt++;
                dp[l][k][r]=max(dp[l][k-1][opt],a[r]-a[opt]);
            }
        }
    }
    LL ans=0;
    while(m--){
        int s,f,c,r;
        scanf("%d %d %d %d",&s,&f,&c,&r);
        if(r>f-s-1)r=f-s-1;
        ans=max((LL)dp[s][r][f]*c,ans);
    }
    printf("%lld\n",ans);
}