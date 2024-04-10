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
int d[300005];
LL c[300006];
int main(){
    int n;
    LL a;
    scanf("%d %lld",&n,&a);
    vector<pll> v;
    LL ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d %lld",&d[i],&c[i]);
        ans=max(ans,a-c[i]);
        c[i]=a-c[i];
        c[i]+=c[i-1];
    }
    v.pb(mp(1e9+1,min(c[0],c[1])));
    for(int i=2;i<=n;i++){
        while(v.back().x<=d[i]-d[i-1]){
            v.pop_back();
        }
        v.pb(mp(d[i]-d[i-1],c[i-1]));
        for(int j=0;j<v.size()-1;j++){
            v[j].y=min(v[j].y,c[i-1]);
          //  printf("%lld\n",c[i]);
            ans=max(ans,c[i]-v[j].y-(LL)v[j+1].x*v[j+1].x);
           // printf("%lld %lld\n",v[j+1].x,v[j].y);
        }
      //  printf("\n");
    }
    printf("%lld\n",ans);
}