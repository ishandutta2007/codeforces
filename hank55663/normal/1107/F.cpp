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
#define MAXN 605
struct KM{
    // Maximum Bipartite Weighted Matching (Perfect Match)
    //static const int MXN = 650;
    const LL INF = 1112147483647ll; // long long
    int px[MAXN],py[MAXN],match[MAXN],par[MAXN],n;
    LL g[MAXN][MAXN],lx[MAXN],ly[MAXN],slack_y[MAXN];
    // ^^^^ long long
    void init(int _n){
        n = _n;
        for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        g[i][j] = 0;
    }
    void add_edge(int x, int y, LL w){ // long long
        g[x][y] = w;
    }
    void adjust(int y){
        match[y]=py[y];
        if(px[match[y]]!=-2)
            adjust(px[match[y]]);
    }
    bool dfs(int x){
        for(int y=0;y<n;++y){
            if(py[y]!=-1)continue;
            LL t=lx[x]+ly[y]-g[x][y];
            if(t==0){
                py[y]=x;
                if(match[y]==-1){
                    adjust(y);
                    return 1;
                }
                if(px[match[y]]!=-1)continue;
                px[match[y]]=y;
                if(dfs(match[y]))return 1;
            }else if(slack_y[y]>t){ 
                slack_y[y]=t;
                par[y]=x;
            }
        }
        return 0;
    }
    LL solve(){
        fill(match,match+n,-1);
        fill(ly,ly+n,0);
        for(int i=0;i<n;++i){
            lx[i]=-INF;
            for(int y=0;y<n;++y){
                lx[i]=max(lx[i],g[i][y]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)slack_y[j]=INF;
            fill(px,px+n,-1);
            fill(py,py+n,-1);
            px[i]=-2;
            if(dfs(i))continue;
            bool flag=1;
            while(flag){
                LL cut=INF; //long long
                for(int j=0;j<n;++j)
                    if(py[j]==-1)cut=min(cut,slack_y[j]);
                for(int j=0;j<n;++j){
                    if(px[j]!=-1)lx[j]-=cut;
                    if(py[j]!=-1)ly[j]+=cut;
                    else slack_y[j]-=cut;
                }
                for(int y=0;y<n;++y){
                    if(py[y]==-1&&slack_y[y]==0){
                        py[y]=par[y];
                        if(match[y]==-1){
                            adjust(y);
                            flag=0;
                            break;
                        }
                        px[match[y]]=y;
                        if(dfs(match[y])){
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
        LL res=0;
        for(int i=0;i<n;++i)
            res+=g[match[i]][i];
        return res;
    }
}graph;
int main(){
    int n;
    scanf("%d",&n);
    graph.init(n);
    for(int i=0;i<n;i++){
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        int sum=a;
        for(int j=0;j<n;j++){
            graph.add_edge(i,j,sum);
            if(j<k){
                sum-=b;
            }
            sum=max(sum,0);
        }
    }
    printf("%lld\n",graph.solve());
}