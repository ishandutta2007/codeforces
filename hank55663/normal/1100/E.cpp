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
int indegree[100005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<pii,int> > p;
    for(int i=0;i<m;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        p.pb(mp(mp(x,y),c));
    }
    int Max=1e9,Min=-1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        MEM(indegree);
        for(auto it:p){
            if(it.y>mid){
                v[it.x.x].pb(it.x.y);
                indegree[it.x.y]++;
            }
        }
        queue<int> q;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto it:v[x]){
                if(--indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==n){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    for(int i=1;i<=n;i++){
            v[i].clear();
        }
    MEM(indegree);
    for(auto it:p){
        if(it.y>Max){
            v[it.x.x].pb(it.x.y);
            indegree[it.x.y]++;
        }
    }
    queue<int> q;
    int cnt=0;
    int rank[100005];
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        rank[x]=cnt;
        cnt++;
        for(auto it:v[x]){
            if(--indegree[it]==0){
                q.push(it);
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<m;i++){
        if(p[i].y<=Max){
          //  printf("%d %d\n",rank[p[i].x.x],rank[p[i].x.y]);
            if(rank[p[i].x.x]>rank[p[i].x.y]){
                ans.pb(i+1);
            }
        }
    }
    printf("%d %d\n",Max,ans.size());
    for(auto it:ans)
    printf("%d ",it);
    printf("\n");
}