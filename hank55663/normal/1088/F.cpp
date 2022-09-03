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
#define hash Hash
#define LL long long
vector<int> v[500005];
vector<int> stk;
int a[500005];
LL ans;
void dfs(int x,int f){
    stk.pb(a[x]);
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    stk.pop_back();
    if(f==0) return;
    LL add=1e12;
    for(int i=0;i<20;i++){
        int index=stk.size()-(1<<i);
        index=max(index,0);
        //printf("%d %d %d %d\n",x,i,stk[index],index);
        add=min(add,(LL)stk[index]*(i+1));
    }
    ans+=add;
    //printf("%d %d\n",x,add);
}
int main(){
    int n;
    scanf("%d",&n);
    ans=0;
    int Min=1e9+1,root;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans+=a[i];
        if(a[i]<Min){
            Min=a[i];
            root=i;
        }
    }
    ans-=Min;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(root,0);
    printf("%lld\n",ans);
}