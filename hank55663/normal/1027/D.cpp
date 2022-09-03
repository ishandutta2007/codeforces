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
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int c[200005];
int a[200005];
int val[200005];
vector<int> stk;
int vis[200005];
int dfs(int x){
    stk.pb(x);
    vis[x]=1;
    if(vis[a[x]]){
        int ans=c[a[x]];
        while(stk.back()!=a[x]){
            ans=min(ans,c[stk.back()]);
            stk.pop_back();
        }
        return ans;
    }
    else
    return dfs(a[x]);
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    f[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[Find(a[i])]=Find(i);
    }
    fill(val,val+n+1,1e9);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(Find(i)==i){
            stk.clear();
            ans+=dfs(i);
            //val[Find(i)]=min(val[Find(i)],c[i]);
        }
    }
    //int ans=0;
    printf("%d\n",ans);
}