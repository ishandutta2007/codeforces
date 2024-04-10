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
int main(){
    int n,k;
    int cnt[105];
    MEM(cnt);
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int d;
        scanf("%d",&d);
        cnt[d%k]++;
    }
    LL ans=cnt[0]/2;
    for(int i=1;i<(k+1)/2;i++){
        ans+=min(cnt[i],cnt[k-i]);
    }
    if(k%2==0)
    ans+=cnt[k/2]/2;
    printf("%lld\n",ans*2);
}