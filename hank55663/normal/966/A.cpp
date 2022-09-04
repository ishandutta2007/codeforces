#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int mod=1e9+7;
int main(){
    int n,m,l,e,v;
    scanf("%d %d %d %d %d",&n,&m,&l,&e,&v);
    vector<LL> ll;
    ll.pb(-1e9);
    for(int i=0;i<l;i++){
        int a;
        scanf("%d",&a);
        ll.pb(a);
    }
    ll.pb(1e9);
    vector<LL> ee;
    ee.pb(-1e9);
    for(int i=0;i<e;i++){
        int a;
        scanf("%d",&a);
        ee.pb(a);
    }
    ee.pb(1e9);
    int q;
    scanf("%d",&q);
    while(q--){
        LL x1,y1,x2,y2;
        scanf("%lld %lld %lld %lld",&y1,&x1,&y2,&x2);
        auto it=lower_bound(ll.begin(),ll.end(),x1);
        LL ans=2e9;
        if(y1==y2){
            ans=abs(x2-x1);
        }
        ans=min(ans,abs(y1-y2)+abs(x1-*it)+abs(x2-*it));
        it--;
        ans=min(ans,abs(y1-y2)+abs(x1-*it)+abs(x2-*it));
        it=lower_bound(ee.begin(),ee.end(),x1);
        ans=min(ans,(abs(y1-y2)+v-1)/v+abs(x1-*it)+abs(x2-*it));
        it--;
        ans=min(ans,(abs(y1-y2)+v-1)/v+abs(x1-*it)+abs(x2-*it));
        printf("%lld\n",ans);
    }
}