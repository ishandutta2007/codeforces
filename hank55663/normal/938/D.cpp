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
vector<pll> v[200005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        LL x,y,w;
        scanf("%lld %lld %lld",&x,&y,&w);
        v[x].pb(mp(y,w<<1));
        v[y].pb(mp(x,w<<1));
    }
    LL d[200005];
    MEMS(d);
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    for(int i=1;i<=n;i++){
        LL x;
        scanf("%lld",&x);
        pq.push(mp(x,i));
    }
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        if(d[p.y]!=-1)continue;
        d[p.y]=p.x;
        for(auto it:v[p.y]){
            if(d[it.x]==-1){
                pq.push(mp(it.y+p.x,it.x));
            }
        }
    }
    for(int i=1;i<=n;i++)
    printf("%lld ",d[i]);
}