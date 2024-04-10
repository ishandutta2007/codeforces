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
    LL n,b;
    scanf("%lld %lld",&n,&b);
    vector<pll> v;
    for(LL i=2;i*i<=b;i++){
        if(b%i==0){
            int cnt=0;
            while(b%i==0){
                cnt++;
                b/=i;
            }
            v.pb(mp(i,cnt));
        }
    }
    if(b!=1){
        v.pb(mp(b,1));
    }
    LL ans=2e18;
    for(int i=0;i<v.size();i++){
        LL temp=n;
        LL tot=0;
        while(n){
            tot+=n/v[i].x;
            n/=v[i].x;
        }
        n=temp;
        //printf("%d\n",v[i])
        ans=min(ans,tot/v[i].y);
    }
    printf("%lld\n",ans);
    return 0;
}