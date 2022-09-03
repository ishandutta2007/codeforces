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
const int MV=210;
class MaxClique{
    public:
    int V;
    int el[MV][MV/30+1];
    int dp[MV];
    int ans;
    int s[MV][MV/30+1];
    vector<int> sol;
    void init(int v){
        V=v; ans = 0;
        MEM(el);MEMS(dp);
    }
    void addEdge(int u,int v){
     //   printf("%d %d\n",u,v);
        if(u>v)swap(u,v);
        if(u==v)return ;
        el[u][v/32]|=(1<<(v%32));
    }
    bool dfs(int v,int k){
        int c=0,d=0;
        for(int i=0;i<(V+31)/32;i++){
            s[k][i] = el[v][i];
            if(k!=1) s[k][i] &=s[k-1][i];
            c+= __builtin_popcount(s[k][i]);
        }
        if(c==0){
            if(k>ans){
                ans=k;
                sol.clear();
                sol.pb(v);
                return 1;
            }
            return 0;
        }
        for(int i=0;i<(V+31)/32; i++){
            for(int a=s[k][i];a;d++){
                if(k+(c-d)<=ans)return 0;
                int lb=a&(-a),lg=0;
                a^=lb;
                while(lb!=1){
                    lb=(unsigned int)(lb)>>1;
                    lg++;
                }
                int u=i*32+lg;
                if(k+dp[u]<=ans) return 0;
                if(dfs(u,k+1)){
                    sol.pb(v);
                    return 1;
                }
            }
        }
        return 0;
    }
    int solve(){
        for(int i=V-1;i>=0;i--){
            dfs(i,1);
            dp[i]=ans;
        }
        return ans;
    }
}MC;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int g[45][45];
    MEMS(g);
    map<string,int> ma;
    int index=0;
    set<int> s;
    while(n--){
        int x;
        scanf("%d",&x);
        if(x==1){
            for(auto it:s){
                for(auto it2:s){
                    g[it][it2]=0;
                }
            }
            s.clear();
        }
        if(x==2){
            char c[100];
            scanf("%s",c);
            string str(c);
            if(ma.find(str)==ma.end()){
                ma[str]=index++;
            }
            s.insert(ma[str]);
        }
    }
    for(auto it:s){
        for(auto it2:s){
            g[it][it2]=0;
        }
    }
    MC.init(m);
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(g[i][j])
                MC.addEdge(i,j);
        }
    }
    printf("%d\n",MC.solve());
}