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
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int val[300005];
vector<int> v[300005];
int ans;
int tot;
int dfs(int x,int f){
    int sum=val[x];
    for(auto it:v[x]){
        if(it!=f){
            int xx=dfs(it,x);
            if(xx==tot)ans++;
            sum+=xx;
        }
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    tot=0;
    int tot2=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==1){
            tot++;
            //val[i]
        }
        if(x==2){
            val[i]=-1;
            tot2++;
        }
        else{
            val[i]=x;
        }
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    tot=tot2;
    for(int i=1;i<=n;i++)
    val[i]=-val[i];
    dfs(1,0);
    printf("%d\n",ans);
}