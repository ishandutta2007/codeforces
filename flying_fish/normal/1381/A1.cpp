#include <sstream>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
#include <cassert>
#include <bitset>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
 
#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define deputs(str) fprintf(stderr, "%s\n",str)
#else
#define debug(...)
#define deputs(str)
#endif // DEBUG
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+107;
const double pi=acos(-1.0);
const double eps=0.0000000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline void pr2(T x,int k=64) {ll i; REP(i,k) debug("%d",(x>>i)&1); putchar(' ');}
template<typename T>inline void add_(T &A,int B,ll MOD=M) {A+=B; (A>=MOD) &&(A-=MOD);}
template<typename T>inline void mul_(T &A,ll B,ll MOD=M) {A=(A*B)%MOD;}
template<typename T>inline void mod_(T &A,ll MOD=M) {A%=MOD; A+=MOD; A%=MOD;}
template<typename T>inline void max_(T &A,T B) {(A<B) &&(A=B);}
template<typename T>inline void min_(T &A,T B) {(A>B) &&(A=B);}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
inline ll powMM(ll a, ll b, ll mod=M) {
    ll ret=1;
    for (; b; b>>=1ll,a=a*a%mod)
        if (b&1) ret=ret*a%mod;
    return ret;
}
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}

int A[maxn];
struct splay_tree {
    struct node {
        int val,size,son[2];//add=lazy
        bool rev;
        void init(int _val) { //T[i].val==a[i-1]();
            val=_val; size=1;
            son[0]=son[1]=0; rev=0;
        }
    } T[maxn*2]; //
    int fa[maxn*2],root,tot;
    void pushup(int x) {
        T[x].size=1;
        if (T[x].son[0]) {
            T[x].size+=T[T[x].son[0]].size;
        }
        if (T[x].son[1]) {
            T[x].size+=T[T[x].son[1]].size;
        }
    }
    void pushdown(int x) {
        if (x==0) return;
        if (T[x].rev) {
            if (T[x].son[0]) T[T[x].son[0]].rev^=1;
            if (T[x].son[1]) T[T[x].son[1]].rev^=1;
            swap(T[x].son[0],T[x].son[1]);
            T[x].rev=0;
        }
    }
    void rotate(int x,int kind) { //zig(1->) zag(0<-)
        int y=fa[x],z=fa[y];
        T[y].son[!kind]=T[x].son[kind],fa[T[x].son[kind]]=y;
        T[x].son[kind]=y,fa[y]=x;
        T[z].son[T[z].son[1]==y]=x,fa[x]=z;
        pushup(y);
    }
    void splay(int x,int goal) { //node x->goal's son
        if (x==goal) return;
        while (fa[x]!=goal) {
            int y=fa[x],z=fa[y];
            pushdown(z),pushdown(y),pushdown(x);
            int rx=T[y].son[0]==x,ry=T[z].son[0]==y;
            if (z==goal) rotate(x,rx);
            else {
                if (rx==ry) rotate(y,ry);
                else rotate(x,rx);
                rotate(x,ry);
            }
        } pushup(x);
        if (goal==0) root=x;
    }
    int select(int pos) { //getnode
        int u=root;
        pushdown(u);
        while (T[T[u].son[0]].size!=pos) { //-INF -1
            if (pos<T[T[u].son[0]].size) u=T[u].son[0];
            else {
                pos-=T[T[u].son[0]].size+1;
                u=T[u].son[1];
            } pushdown(u);
        } return u;
    }
    //?
    void reverse(int l,int r) {
        // printf("reverse: %d-%d",l,r);
        int u=select(l-1),v=select(r+1);
        splay(u,0); splay(v,u);
        T[T[v].son[0]].rev^=1;
    }

    int nodebuff[maxn],bufs;//bufs:position
    int build(int l,int r) { //add_list
        if (l>r) return 0;
        ++tot; if (tot==maxn) tot=1;
        int ret=nodebuff[tot];
        int mid=(l+r)/2;
        T[ret].init(A[mid]);
        if (l==r) return ret;
        int ls=build(l,mid-1);
        int rs=build(mid+1,r);
        if (ls) fa[ls]=ret,T[ret].son[0]=ls;
        if (rs) fa[rs]=ret,T[ret].son[1]=rs;
        pushup(ret);
        return ret;
    }
    void init(int n) {
        int i; tot=0;
        REP(i,maxn) nodebuff[i]=i;
        rFOR(i,1,n) A[i+1]=A[i];
        A[1]=A[n+2]=INF;
        root=build(1,n+2);
        fa[root]=0; T[0].init(-INF);
        fa[0]=0; T[0].son[1]=root; T[0].size=0;
    }
    // void dfs(int x) {

    // }
} T;
int B[maxn];
bool mark;
int main() {
    int _T,_; _T=1;
    scanf("%d",&_T);
    FOR(_,1,_T){
        int i; int n;
        scanf("%d",&n);
        FOR(i,1,n) scanf("%1d",&A[i]);
        FOR(i,1,n) scanf("%1d",&B[i]);
        T.init(n); int now=0;
        vector<int> ans;
        FOR(i,1,n) A[i]=A[i+1];//A
        rFOR(i,1,n) {
            if ((T.T[T.select(1)].val^now)==B[i]) ans.push_back(1),A[1]^=1;
            ans.push_back(i),now^=1,T.reverse(1,i);
            // int k; reverse(A+1,A+1+i); FOR(k,1,i) A[k]^=1;
            // printf("pos=%d; t=%d   < T\n",T.select(1),T.T[T.select(1)].val);
            // printf("k=%d now=%d <- k\n",i,now);
            // FOR(k,1,i) printf("%d",T.T[T.select(k)].val^now); puts(" <- now");
            // FOR(k,1,n) printf("%d",A[k]); puts("<- k"); puts("");
        }
        printf("%d",(int)ans.size());
        for (int v:ans) printf(" %d",v); puts("");
        // puts("");
    }

}
/*
2
5
01011
11100
*/