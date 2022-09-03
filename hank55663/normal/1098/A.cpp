
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
vector<int> v[100005];
int s[100005];
int a[100005];
int h[100005];
void dfs(int x,int f,int now){
    h[x]=h[f]+1;
    if(s[x]==-1){
        a[x]=0;
    }
    else if(s[x]<now){
        printf("-1\n");
        exit(0);
    }
    else{
        a[x]=s[x]-now;
        now=s[x];
    }
    for(auto it:v[x]){
        dfs(it,x,now);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int p[100005];
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i]);
        v[p[i]].pb(i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }
    dfs(1,0,0);
    vector<pii> vv;
    for(int i=1;i<=n;i++){
        vv.pb(mp(h[i],i));
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    for(auto it:vv){
        int Min=1e9+1;
        for(auto x:v[it.y]){
            Min=min(Min,a[x]);
        }
        if(Min!=1e9+1&&s[it.y]==-1){
            a[it.y]+=Min;
            for(auto x:v[it.y]){
                a[x]-=Min;
            }
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i];
     //   printf("%d ",a[i]);
    }
    printf("%lld\n",ans);
}