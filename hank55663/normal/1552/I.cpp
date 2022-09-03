#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL fra[105];
int MOD=998244353;
const int N = 1005;
struct PQ_tree{
    int fail,res,n,tot;
    vector<int> G[N << 2];
    int ty[N << 2],sz[N << 2],szc[N << 2];
    bool s[N];
    inline int getstate(int u){
        if(szc[u] == 0) return 0;
        if(szc[u] == sz[u]) return 2;
        return 1;
    }
    void addson(int x, int y) {if(y) G[x].pb(y);}
    void join(int x, int y) {for(auto v : G[y]) G[x].pb(v);}
    int mergeP(vector<int> &vec){
        if(vec.size() == 0) return 0;
        if(vec.size() == 1) return vec[0];
        G[++tot] = vec;
        return tot;
    }
    void init(int _n){
        n = _n;
        tot = n + 1;
        memset(ty, 0, sizeof(ty));
        for(int i = 1; i <= n; i++) G[n + 1].pb(i);
        fail = 0;
    }
    void dfs(int u){
        sz[u] = u <= n;
        szc[u] = u <= n && s[u];
        for(auto v : G[u]){
            dfs(v);
            sz[u] += sz[v];
            szc[u] += szc[v];
        }
    }
    int check(int u, int t){
        if(fail) return 0;
 
        vector<int> vec[3];
        for(auto v : G[u]) vec[getstate(v)].pb(v);
 
        if(vec[1].size() > 2 || (t && vec[1].size() > 1)) return fail = 1, 0;
        if(t == 0 && vec[1].size() == 1 && vec[2].size() == 0) return check(vec[1][0], 0);
 
        if(ty[u] == 0){
            int p2 = mergeP(vec[2]);
            if(t == 0){
                G[u] = vec[0];
                if(vec[1].size() == 0) addson(u, p2);
                else{
                    int tmp1 = check(vec[1][0], 2);
                    addson(tmp1, p2);
                    if(vec[1].size() == 2) join(tmp1, check(vec[1][1], 1));
                    addson(u, tmp1);
                }
                return u;
            }
            else{
                ty[u] = 1;
                G[u].clear();
                addson(u, p2);
                if(vec[1].size() == 1) join(u, check(vec[1][0], 1));
                addson(u, mergeP(vec[0]));
 
                if(t == 2) reverse(G[u].begin(), G[u].end());
            }
            return u;
        }
        else{
            if(getstate(G[u].front()) > getstate(G[u].back())) reverse(G[u].begin(), G[u].end());
 
            int flag = 0;
 
            vector<int> tG;
            for(auto v : G[u]){
                int sta = getstate(v);
                if(sta == 0){
                    if(flag == 1) flag = 2;
                    tG.pb(v);
                }
                else if(sta == 2){
                    if(flag == 0) flag = 1;
                    else if(flag == 2) return fail = 2, 0;
                    tG.pb(v);
                }
                else{
                    int p1;
                    if(flag == 0) flag = 1, p1 = check(v, 2);
                    else if(flag == 1) flag = 2, p1 = check(v, 1);
                    else return fail = 3, 0;
                    for(auto x : G[v]) tG.pb(x);
                }
            }
            if(t && flag == 2) return fail = 4, 0;
            if(t == 1) reverse(tG.begin(), tG.end());
            G[u] = tG;
            return u;
        }
    }
    void dfs_permutation(int u){
        if(u <= n) {
            return;
        }
        if(!ty[u]){
            res=(LL)res*fra[G[u].size()]%MOD;
        }else if(G[u].size()!=1){
            res=(LL)res*2%MOD;
        }
        for(auto v : G[u]){
            dfs_permutation(v);
        }
    }
    int get_permutation(){
        res=1; dfs_permutation(n + 1);
        return res;
    }
    void restrict(vector<int> res){
        for(int i = 1; i <= n; i++) s[i] = 0;
        for(auto x : res) s[x] = 1;
        dfs(n + 1); check(n + 1, 0);
    }
};
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    PQ_tree pq;
    fra[0]=1;
    for(int i = 1;i<=n;i++)fra[i]=fra[i-1]*i%MOD;
    pq.init(n);
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        vector<int> v;
        for(int i = 0;i<x;i++){
            int a;
            scanf("%d",&a);
            v.pb(a);
        }
        pq.restrict(v);
    }
    if(pq.fail)printf("0\n");
    else{
        printf("%d\n",pq.get_permutation());
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/