/**
 *    author:  gary
 *    created: 06.03.2022 19:07:45
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
typedef pair<int,int> mp;
namespace io {
        const int SIZE = (1 << 21) + 1;
        char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
        // getchar
        #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
        // print the remaining part
        inline void flush () {
                fwrite (obuf, 1, oS - obuf, stdout);
                oS = obuf;
        }
        // putchar
        inline void putc (char x) {
                *oS ++ = x;
                if (oS == oT) flush ();
        }
        // input a signed integer
        template <class I>
        inline void gi (I &x) {
                for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
                for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
        }
        // print a signed integer
        template <class I>
        inline void print (I x) {
                if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
                while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
                while (qr) putc (qu[qr --]);
        }
        //no need to call flush at the end manually!
        struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
const int MAXN=2e5+10;
int n,m;
vector<mp> g2[MAXN];
int jump[MAXN][18],mx[MAXN][18],dep[MAXN];
struct DSU{    
    vector<vector<int> > cont[MAXN];
    int fa[MAXN],siz[MAXN];
    void init(int n){
        rb(i,1,n) fa[i]=i,cont[i]={{i}},siz[i]=1;
    }
    int root(int x){
        return fa[x]=(fa[x]==x? x:root(fa[x]));
    }
}tree1,tree2;
const int SIZE=(1<<23)-1;
struct Hash_Table{
    int tp[SIZE+1];
    vector<long long> keys;
    vector<int> nex;
    Hash_Table(){rb(i,0,SIZE) tp[i]=-1;}
    void insert_edge(int u,int v){
        if(u>v) swap(u,v);
        unsigned long long Key=((long long)(u)<<20)|v;
        unsigned long long Has=Key^(Key>>20);
        Has^=Has<<7;
        Has^=Has>>17;
        Has^=Has<<13;
        Has^=Has>>23;
        Has&=SIZE;
        nex.PB(tp[Has]);
        keys.PB(Key);
        tp[Has]=nex.size()-1;
    }
    bool query_edge(int u,int v){
        if(u>v) swap(u,v);
        unsigned long long Key=((long long)(u)<<20)|v;
        unsigned long long Has=Key^(Key>>20);
        Has^=Has<<7;
        Has^=Has>>17;
        Has^=Has<<13;
        Has^=Has>>23;
        Has&=SIZE;
        for(int now=tp[Has];now!=-1;now=nex[now]) if(keys[now]==Key) return true;
        return false;
    }
    void clear(){
        for(unsigned long long Key:keys){
            unsigned long long Has=Key^(Key>>20);
            Has^=Has<<7;
            Has^=Has>>17;
            Has^=Has<<13;
            Has^=Has>>23;
            Has&=SIZE;
            tp[Has]=-1;
        }
        keys.clear();
        nex.clear();
    }
}edge_exist;
int mergeto(vector<vector<int> > &v,int x,int y){
    if(v[x].size()<v[y].size()) v[x].swap(v[y]);
    for(auto it:v[y]) v[x].PB(it);
    if(x==v.size()-1) x=y;
    v[y].swap(v.back());
    v.pop_back();
    return x;
}
void addedge(int u,int v,int w){
    g2[u].PB(II(v,w));
    g2[v].PB(II(u,w));
}
void merge(int u,int v,int w){
    u=tree1.root(u);
    v=tree1.root(v);
    if(u==v) return;
    if(tree1.siz[u]>tree1.siz[v]) swap(u,v);
    auto &ano=tree1.cont[v];
    tree1.fa[u]=v;
    tree1.siz[v]+=tree1.siz[u];
    for(auto it:tree1.cont[u]){
        int to=-1;
        for(auto itt:it){
            rep(i,ano.size()){
                if(i!=to){
                    bool ok=0;
                    rep(j,ano[i].size()){
                        if(!edge_exist.query_edge(itt,ano[i][j])){
                            addedge(itt,ano[i][j],w);
                            ok=1;
                            break;
                        }
                    }
                    if(ok){
                        if(to==-1) to=i;
                        else to=mergeto(ano,to,i);
                        i--;
                    }
                }
            }
            if(to==-1){
                ano.push_back(vector<int>(0));
                to=ano.size()-1;
            }
            ano[to].push_back(itt);
        }
    }
}
void dfs(int now,int pre){
    rb(j,1,17){
        jump[now][j]=jump[jump[now][j-1]][j-1];
        mx[now][j]=max(mx[now][j-1],mx[jump[now][j-1]][j-1]);
    }
    for(auto it:g2[now]) if(it.first!=pre) dep[it.first]=dep[now]+1,jump[it.first][0]=now,mx[it.first][0]=it.second,dfs(it.first,now);
}
int query(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    int ans=0;
    rep(j,18) if((d>>j)&1) check_max(ans,mx[u][j]),u=jump[u][j];
    if(u!=v){
        rl(j,17,0){
            if(jump[u][j]!=jump[v][j]){
                check_max(ans,mx[u][j]);
                check_max(ans,mx[v][j]);
                u=jump[u][j];
                v=jump[v][j];
            }
        }
        check_max(ans,max(mx[u][0],mx[v][0]));
    }
    return ans;
}
void solve(){
    edge_exist.clear();
    gi(n);
    gi(m);
    tree1.init(n);
    tree2.init(n);
    rb(i,1,n) g2[i].clear(),memset(jump[i],0,sizeof(jump[i])),memset(mx[i],0,sizeof(mx[i])),dep[i]=0;
    vector<mp > olde;
    vector<pair<int,mp > > Es;
    rb(i,1,m){
        int u,v,w;
        gi(u);gi(v);gi(w);
        edge_exist.insert_edge(u,v);
        Es.PB(II(w,II(u,v)));
        olde.PB(II(u,v));
    }
    sort(ALL(Es));
    for(auto it:Es){
        merge(it.second.first,it.second.second,it.first);
    }
    dfs(1,0);
    for(auto it:olde) print(query(it.first,it.second)),putc(' ');
    putc('\n');
}
int main(){
    int t;
    gi(t);
    while(t--) solve();
    return 0;
}