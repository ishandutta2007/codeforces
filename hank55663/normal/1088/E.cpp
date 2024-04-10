
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
int a[300005];
vector<int> v[300005];
LL Size[300005];
LL dfs(int x,int f){
    Size[x]=a[x];
    for(auto it:v[x]){
        if(it!=f){
            LL value=dfs(it,x);
            Size[x]+=max(0ll,value);
        }
    }
    return Size[x];
}
LL Max;
LL dfs2(int x,int f){
    Size[x]=a[x];
    for(auto it:v[x]){
        if(it!=f){
            LL value=dfs2(it,x);
            Size[x]+=max(0ll,value);
        }
    }
    if(Size[x]==Max)
    return 0;
    else
    return Size[x];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
     //   a[i]=-1e9;
    }
    for(int i=1;i<n;i++){
        int x,y;
        //x=i,y=i+1;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    Max=-1e9-1;
    LL cnt=0;
    for(int i=1;i<=n;i++){
        if(Size[i]>Max){
            Max=Size[i];
        }
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        if(Size[i]==Max)
        cnt++;
    }
    printf("%lld %lld\n",Max*cnt,cnt);
    return 0;
}