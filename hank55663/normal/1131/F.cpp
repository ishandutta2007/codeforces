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
vector<int> v[150005];
int f[150005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<int> stk;
void dfs(int x,int f){
    stk.pb(x);
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>y)
        swap(x,y);
        int fx=Find(x);
        int fy=Find(y);
        f[fy]=fx;
        v[fx].pb(fy);
        v[fy].pb(fx);
        //v[x].pb(y);
        //v[y].pb(x);
    }
    dfs(1,0);
    for(auto it:stk)
    printf("%d ",it);
}
/*

i f f x f l b
*/