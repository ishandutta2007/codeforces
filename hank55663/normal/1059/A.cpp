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
int main(){
    int n,l,a;
    scanf("%d %d %d",&n,&l,&a);
    int ans=0;
    int last=0;
    for(int i=0;i<n;i++){
        int t,l;
        scanf("%d %d",&t,&l);
        ans+=(t-last)/a;
        last=t+l;
    }
    ans+=(l-last)/a;
    printf("%d\n",ans);
}