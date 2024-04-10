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
int n,k,a,b;
vector<int> v;
LL dp(int l,int r){
    if(upper_bound(v.begin(),v.end(),r)==lower_bound(v.begin(),v.end(),l)){
        return a;
    }
    LL res=(LL)(upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l))*b*(r-l+1);
    //printf("%d %d %lld %d %d %d\n",l,r,res,upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l),b,r-l+1);
    if(l!=r)
    res=min(res,dp(l,(l+r)/2)+dp((l+r)/2+1,r));
    //printf("%d %d %lld\n",l,r,res);
    return res;
}
int main(){
    scanf("%d %d %d %d",&n,&k,&a,&b);
    for(int i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        v.pb(x);
    }
    sort(v.begin(),v.end());
    printf("%lld\n",dp(1,1<<n));
}
/*

i f f x f l b
*/