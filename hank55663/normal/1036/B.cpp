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
typedef long long LL;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        LL x,y,k;
        scanf("%lld %lld %lld",&x,&y,&k);
        if(max(x,y)>k){
            printf("-1\n");
        }
        else if(abs(x-y)&1){
            k--;
            x--;
            LL temp=max(x,y);
            LL ans=0;
            if(temp<=k){
                if((k-temp)&1)
                    ans=k-2;
                else
                    ans=k;
            }
            x++;
            y--;
            temp=max(x,y);
            if(temp<=k){
                if((k-temp)&1)
                    ans=max(ans,k-2);
                else
                    ans=k;
            }
            printf("%lld\n",ans);
        }
        else{
                LL ans=max(x,y);
                if((k-ans)&1){
                    printf("%lld\n",ans-1+(k-ans-1));
                }
                else{
                    printf("%lld\n",k);
                }
            
        }
    }
    return 0;
}