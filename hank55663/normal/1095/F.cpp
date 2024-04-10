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
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL a[200005];
    LL Min=1e12+1,Mini=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<Min){
            Min=a[i];
            Mini=i;
        }
    }
    pair<LL,pii> p[200005];
    for(int i=0;i<m;i++){
        int x,y;
        LL w;
        scanf("%d %d %lld",&x,&y,&w);
        p[i]=mp(w,mp(x,y));
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(p,p+m);
    LL ans=0;
    for(int i=0;i<m;i++){
        int fx=Find(p[i].y.x);
        int fy=Find(p[i].y.y);
        if(fx!=fy){
            LL Max=max(a[fx],a[fy]);
            if(Max+Min>p[i].x){
                ans+=p[i].x;
                if(a[fx]>a[fy])
                f[fx]=fy;
                else
                f[fy]=fx;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=Mini&&Find(i)==i){
            ans+=Min+a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}