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
LL dp[505][5005];
int main(){
    MEM(dp);
    int n,k;
    scanf("%d %d",&n,&k);
    int cnt[100005];
    MEM(cnt);
    for(int i=0;i<n*k;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    int cnt2[100005];
    MEM(cnt2);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt2[x]++;
    }
    int h[20];
    h[0]=0;
    for(int i=1;i<=k;i++)
    scanf("%d",&h[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*k;j++){
            for(int kk=0;kk<=k&&kk<=j;kk++){
                dp[i][j]=max(dp[i][j],dp[i-1][j-kk]+h[kk]);
            }
        }
    }
    LL ans=0;
    for(int i=1;i<=1e5;i++){
        ans+=dp[cnt2[i]][cnt[i]];
    }
    printf("%lld\n",ans);
}