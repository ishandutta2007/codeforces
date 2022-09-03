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
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define Line pair<pii,pii> 
typedef long long LL;
vector<int> v[1000005];
int indegree[1000005];
int outdegree[1000005];
int vis[1000005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        indegree[y]++;
        outdegree[x]++;
        v[x].pb(y);
    }
    vector<int> sink;
    for(int i=1;i<=n;i++){
        if(outdegree[i]==0)
        sink.pb(i);
    }
    vector<int> value;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            queue<int> q;
            q.push(i);
            MEM(vis);
            vis[i]=1;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto it:v[x]){
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            int val=0;
            for(int i=0;i<sink.size();i++){
                if(vis[sink[i]]){
                    val+=(1<<i);
                }
            }
            value.pb(val);
        }
    }
    int nn=value.size();
    for(int i=1;i<(1<<nn)-2;i++){
        int val=0;
        for(int j=0;j<nn;j++){
            if(i&(1<<j))
            val|=value[j];
        }
        if(__builtin_popcount(val)==__builtin_popcount(i)){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}