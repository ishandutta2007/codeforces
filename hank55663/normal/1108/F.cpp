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
#define MAXN 605
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<int,pii> > v;
    for(int i=0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v.pb(mp(w,mp(x,y)));
    }
    sort(v.begin(),v.end());
    vector<pair<int,pii> > useless;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(auto it:v){
        int fx=Find(it.y.x);
        int fy=Find(it.y.y);
        if(fx!=fy){
            f[fx]=fy;
        }
        else
            useless.pb(it);
    }
    int index=0;
    int ans=0;
    for(int i=1;i<=n;i++)f[i]=i;
    for(auto it:v){
        while(index!=useless.size()&&it.x==useless[index].x){
            int fx=Find(useless[index].y.x);
            int fy=Find(useless[index].y.y);
            if(fx!=fy)ans++;
            index++;
        }
        int fx=Find(it.y.x);
        int fy=Find(it.y.y);
        if(fx!=fy)f[fx]=fy;
    }
    printf("%d\n",ans);
}