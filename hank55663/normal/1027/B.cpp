#pragma GCC optimize("Ofast") 
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
    LL n,q;
    scanf("%lld %lld",&n,&q);
    while(q--){
        LL x,y;
        scanf("%lld %lld",&x,&y);
        if((x+y)&1){
            LL ans=(LL)(n*n+1)/2;
            if(n&1){
                ans+=(LL)(x-1)/2*n;
                if(x&1){

                }
                else{
                    ans+=n/2;
                }
                printf("%lld\n",ans+(y+1)/2);
            }
            else{
                printf("%lld\n",ans+n/2*(x-1)+(y+1)/2);
            }
        }
        else{
            if(n&1){
                LL ans=(LL)(x-1)/2*n;
                if(x&1){

                }
                else{
                    ans+=(n+1)/2;
                }
                printf("%lld\n",ans+(y+1)/2);
            }
            else{
                printf("%lld\n",n/2*(x-1)+(y+1)/2);
            }
        }
    }
}