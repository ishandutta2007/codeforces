
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
vector<int> v[1005];
int f[1005];
pii ans[1005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int dfs(int x,int f){
    int Max=0;
    for(auto it:v[x]){
        if(it!=f){
            Max=max(Max,dfs(it,x)+1);
        }
    }
    return Max;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    ans[i]=mp(1e9,i);
    for(int i=1;i<=n;i++)
    f[i]=i;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        f[Find(x)]=Find(y);
    }
    for(int i=1;i<=n;i++){
        pii p=mp(dfs(i,0),i);
        ans[Find(i)]=min(ans[Find(i)],p);
     //   printf("%d\n",Find(i));
    }
    vector<pii> edge;
    vector<pii> vv;
    for(int i=1;i<=n;i++){
        if(Find(i)==i){
            vv.pb(ans[i]);
        }
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    for(int i=1;i<vv.size();i++){
        edge.pb(mp(vv[i].y,vv[0].y));
        v[vv[i].y].pb(vv[0].y);
        v[vv[0].y].pb(vv[i].y);
    }
    int Min=0;
    for(int i=1;i<=n;i++){
        Min=max(Min,dfs(i,0));
    }
    printf("%d\n",Min);
    for(auto it:edge)
    printf("%d %d\n",it.x,it.y);
    return 0;
}