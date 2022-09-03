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
int Size[100005];
vector<int> v[100005];
int dfs(int x,int f){
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            Size[x]+=dfs(it,x);
        }
    }
    return Size[x];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    int ans=-1;
    if(n%2){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(Size[i]%2==0)
        ans++;
    }
    printf("%d\n",ans);
}