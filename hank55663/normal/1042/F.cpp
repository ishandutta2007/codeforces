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
int k;
vector<int> v[1000005];
int ans;
int dfs(int x,int f){
    vector<int> vv;
    for(auto it:v[x]){
        if(it!=f){
            vv.pb(dfs(it,x));
        }
    }
    if(vv.empty())
    vv.pb(0);
    sort(vv.begin(),vv.end());
    while(vv.size()>1){
        int x=vv.back();
        vv.pop_back();
        if(x+vv.back()>k){
            ans++;
        }
        else{
            vv.pb(x);
            break;
        }
    }
    return vv.back()+1;
}
int main(){
    int n;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        if(v[i].size()!=1){
            dfs(i,0);
            break;
        }
    }
    printf("%d\n",ans+1);
}