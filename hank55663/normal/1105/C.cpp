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
int mod=1e9+7;
int main(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    int cnt[3];
    cnt[0]=r/3-(l-1)/3;
    cnt[1]=(r+2)/3-(l+1)/3;
    cnt[2]=(r+1)/3-(l)/3;
    //printf("%d %d %d\n",cnt[0],cnt[1],cnt[2]);
    LL dp[200005][3];
    MEM(dp);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                dp[i+1][(j+k)%3]+=dp[i][j]*cnt[k];
                dp[i+1][(j+k)%3]%=mod;
            }
        }
    }
    printf("%lld\n",dp[n][0]);
}