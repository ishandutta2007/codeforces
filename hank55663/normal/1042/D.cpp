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
#define hash Hash
int S[200005];
void add(int x){
    for(int i=x;i<200005;i+=i&-i)
    S[i]++;
}
int query(int x){
    int res=0;
    for(int i=x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int main(){
    LL n,t;
    scanf("%lld %lld",&n,&t);
    LL a[200005];
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    LL sum[200005];
    sum[0]=0;
    map<LL ,int> m;
    m[0];
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        m[-sum[i]];
    }
    m[1000000000000000000LL];
    int index=1;
    for(auto &it:m){
        it.y=index++;
     //   printf("%d ",it.x);
    }
   // printf("\n");
    add(m[0]);
    LL tot=0;
    for(int i=1;i<=n;i++){
        int x=m.lower_bound(t-sum[i])->y;
        x--;
        tot+=query(x);
       // printf("%lld %d\n",tot,x);
        add(m[-sum[i]]);
    }
    printf("%lld\n",tot);
}