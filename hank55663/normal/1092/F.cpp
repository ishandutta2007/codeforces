
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
vector<int> v[200005];
LL Size[200005];
int a[200005];
LL sum=0;
LL now=0;
LL ans=0;
void dfs(int x,int f){
    Size[x]=a[x];
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
    now+=Size[x];
   // printf("Size %d %lld\n",x,Size[x]);
}
void dfs2(int x,int f,LL num){
    ans=max(ans,num);
    //printf("%d %lld\n",x,num);
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x,num-Size[it]+sum-Size[it]);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    now-=Size[1];
    dfs2(1,0,now);
    printf("%lld\n",ans);
    return 0;
}