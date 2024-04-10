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
vector<int> v[100005];
int vis[100005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    pq.push(1);
    while(!pq.empty()){
        int x=pq.top();
        pq.pop();
        if(vis[x])continue;
        vis[x]=1;
        printf("%d ",x);
        for(auto it:v[x]){
            if(!vis[it])
            pq.push(it);
        }
    }
    printf("\n");
}