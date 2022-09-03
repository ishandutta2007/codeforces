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
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<pii> v[200005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int degree[200005];
    MEM(degree);
    vector<pii> edge;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        edge.pb(mp(x,y));
        v[x].pb(mp(x,y));
        v[y].pb(mp(x,y));
        degree[x]++;
        degree[y]++;
    }
    int Max=0,Maxi;
    for(int i=1;i<=n;i++){
        f[i]=i;
        if(degree[i]>Max){
            Max=degree[i];
            Maxi=i;
        }
    }
    vector<pii> ans;
    for(auto it:v[Maxi]){
        ans.pb(it);
        int fx=Find(it.x);
        int fy=Find(it.y);
        f[fx]=fy;
    }
  //  printf("%d\n",Maxi);
    for(auto it:edge){
        int fx=Find(it.x);
        int fy=Find(it.y);
        if(fx!=fy){
            f[fx]=fy;
            ans.pb(it);
        }
    }
    for(auto it:ans)
    printf("%d %d\n",it.x,it.y);
}