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
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define Line pair<pii,pii> 
typedef long long LL;
int main(){
    int cnt[1005];
    MEM(cnt);
    int n;
    scanf("%d",&n);
    int ans=0;
    while(n--){
        int x;
        scanf("%d",&x);
        cnt[x]++;
        ans=max(ans,cnt[x]);
    }
    printf("%d\n",ans);
    return 0;
}