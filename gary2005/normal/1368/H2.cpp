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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int N=1<<17;
struct SEGMENTTREE1{//  , B:0  R:1
    int tree[N+N][2];
    bool tag[N+N];
    SEGMENTTREE1(){
        memset(tree,0,sizeof(tree));
        memset(tag,0,sizeof(tag));
    }
    void build(){
        rl(i,N-1,1){
            tree[i][0]=tree[i<<1][0]+tree[i<<1|1][0];
            tree[i][1]=tree[i<<1][1]+tree[i<<1|1][1];
        }
    }
    void pd(int now){
        if(tag[now]){
            if(now<N){
                tag[now<<1]^=1;
                tag[now<<1|1]^=1;
                swap(tree[now<<1][0],tree[now<<1][1]);
                swap(tree[now<<1|1][0],tree[now<<1|1][1]);
            }
            tag[now]=false;
        }
    }
    void flip(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a){
            swap(tree[now][0],tree[now][1]);
            tag[now]^=1;
            return ;
        }
        pd(now);
        int mid=(l+r)>>1;
        flip(a,b,now<<1,l,mid);
        flip(a,b,now<<1|1,mid,r);
        tree[now][0]=tree[now<<1][0]+tree[now<<1|1][0];
        tree[now][1]=tree[now<<1][1]+tree[now<<1|1][1];
    }
}L,R,U,D;
struct matrix{
    int a[2][2];
    matrix(){a[0][0]=a[1][1]=a[0][1]=a[1][0]=INF;}
};
matrix operator * (matrix A,matrix B){
    matrix c;
    rep(i,2) rep(j,2) rep(k,2) check_min(c.a[i][k],A.a[i][j]+B.a[j][k]);
    return c;
}
struct SEGMENTTREE2{
    matrix tree[N+N][2][2];
    bool tag[N+N][2];
    SEGMENTTREE2(){
        memset(tag,0,sizeof(tag));
        rb(i,1,N) rep(j,2) rep(k,2) tree[i+N-1][j][k].a[0][0]=tree[i+N-1][j][k].a[1][1]=0,tree[i+N-1][j][k].a[0][1]=tree[i+N-1][j][k].a[1][0]=INF;
    }
    void build(){
        rl(i,N-1,1){
            tree[i][0][0]=tree[i<<1][0][0]*tree[i<<1|1][0][0];
            tree[i][0][1]=tree[i<<1][0][1]*tree[i<<1|1][0][1];
            tree[i][1][0]=tree[i<<1][1][0]*tree[i<<1|1][1][0];
            tree[i][1][1]=tree[i<<1][1][1]*tree[i<<1|1][1][1];
        }
    }
    void pd(int now){
        if(tag[now][0]){
            if(now<N){
                tag[now<<1][0]^=1,tag[now<<1|1][0]^=1;
                swap(tree[now<<1][0][0],tree[now<<1][1][0]);
                swap(tree[now<<1][0][1],tree[now<<1][1][1]);
                swap(tree[now<<1|1][0][0],tree[now<<1|1][1][0]);
                swap(tree[now<<1|1][0][1],tree[now<<1|1][1][1]);
            }
            tag[now][0]=0;
        }
        if(tag[now][1]){
            if(now<N){
                tag[now<<1][1]^=1,tag[now<<1|1][1]^=1;
                swap(tree[now<<1][0][0],tree[now<<1][0][1]);
                swap(tree[now<<1][1][0],tree[now<<1][1][1]);
                swap(tree[now<<1|1][0][0],tree[now<<1|1][0][1]);
                swap(tree[now<<1|1][1][0],tree[now<<1|1][1][1]);
            }
            tag[now][1]=0;
        }
    }
    void flip(int a,int b,bool c,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return;
        if(r<=b&&l>=a){
            if(!c){
                swap(tree[now][0][0],tree[now][1][0]);
                swap(tree[now][0][1],tree[now][1][1]);
                tag[now][0]^=1;
            }
            else{
                swap(tree[now][0][0],tree[now][0][1]);
                swap(tree[now][1][0],tree[now][1][1]);
                tag[now][1]^=1;
            }
            return;
        }
        pd(now);
        int mid=(l+r)>>1;
        flip(a,b,c,now<<1,l,mid);
        flip(a,b,c,now<<1|1,mid,r);
        tree[now][0][0]=tree[now<<1][0][0]*tree[now<<1|1][0][0];
        tree[now][0][1]=tree[now<<1][0][1]*tree[now<<1|1][0][1];
        tree[now][1][0]=tree[now<<1][1][0]*tree[now<<1|1][1][0];
        tree[now][1][1]=tree[now<<1][1][1]*tree[now<<1|1][1][1];
    }
}H,V;
char Lc[N],Rc[N],Dc[N],Uc[N];
bool Lb[N],Rb[N],Db[N],Ub[N];
int n,m,q;
matrix getmatrix(bool A,bool B,int C){
    matrix rest;
    rep(i,2) rep(j,2){
        rest.a[i][j]=0;
        if(i!=j) rest.a[i][j]=C;
        rest.a[i][j]+=A^j;
        rest.a[i][j]+=B^j;
    }
    return rest;
}
void init(){
    rb(i,1,m){
        rep(j,2) rep(k,2)
        V.tree[i+N-1][j][k]=getmatrix(j^Ub[i],k^Db[i],n);
        U.tree[i+N-1][Ub[i]]=1;
        D.tree[i+N-1][Db[i]]=1;
    }
    V.build();
    rb(i,1,n){
        rep(j,2) rep(k,2)
        H.tree[i+N-1][j][k]=getmatrix(j^Lb[i],k^Rb[i],m);
        L.tree[i+N-1][Lb[i]]=1;
        R.tree[i+N-1][Rb[i]]=1;
    }
    H.build();
    L.build(),R.build();
    D.build(),U.build();
}
void flip_L(int l,int r){
    L.flip(l,r+1);
    H.flip(l,r+1,0);
}
void flip_R(int l,int r){
    R.flip(l,r+1);
    H.flip(l,r+1,1);
}
void flip_U(int l,int r){
    U.flip(l,r+1);
    V.flip(l,r+1,0);
}
void flip_D(int l,int r){
    D.flip(l,r+1);
    V.flip(l,r+1,1);
}
int queryH(){
    int a[2][2];
    a[0][0]=U.tree[1][1];
    a[0][1]=U.tree[1][0];
    a[1][0]=D.tree[1][1];
    a[1][1]=D.tree[1][0];
    matrix Mat=H.tree[1][0][0];
    int ans=INF;
    rep(i,2){
        rep(j,2){
            rep(k,2){
                int tmp=0;
                tmp=a[0][i]+a[1][k];
                tmp+=Mat.a[i][j];
                if(j!=k) tmp+=m;
                check_min(ans,tmp);
            }
        }
    }
    return ans;
}
int queryV(){
    int a[2][2];
    a[0][0]=L.tree[1][1];
    a[0][1]=L.tree[1][0];
    a[1][0]=R.tree[1][1];
    a[1][1]=R.tree[1][0];
    matrix Mat=V.tree[1][0][0];
    int ans=INF;
    rep(i,2){
        rep(j,2){
            rep(k,2){
                int tmp=0;
                tmp=a[0][i]+a[1][k];
                tmp+=Mat.a[i][j];
                if(j!=k) tmp+=n;
                check_min(ans,tmp);
            }
        }
    }
    return ans;
}
int answer(){
    return min(queryH(),queryV());
}
namespace io {
        const int SIZE = (1 << 21) + 1;
        char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
        #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
        inline void flush () {
                fwrite (obuf, 1, oS - obuf, stdout);
                oS = obuf;
        }
        inline void putc (char x) {
                *oS ++ = x;
                if (oS == oT) flush ();
        }
        template <class I>
        inline void gi (I &x) {
                for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
                for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
        }
        template <class I>
        inline void print (I x) {
                if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
                while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
                while (qr) putc (qu[qr --]);
        }
        struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using namespace io;
void gic(char &c){
    c=gc();
    while (c>'Z'||c<'A'){
        c=gc();
    }
}
int main(){
    gi(n);
    gi(m);
    gi(q);
    rb(i,1,n) gic(Lc[i]);
    rb(i,1,n) gic(Rc[i]);
    rb(i,1,m) gic(Uc[i]);
    rb(i,1,m) gic(Dc[i]);
    rb(i,1,n) Lb[i]=(Lc[i]=='R'),Rb[i]=(Rc[i]=='R');
    rb(i,1,m) Ub[i]=(Uc[i]=='R'),Db[i]=(Dc[i]=='R');
    init();
    print(answer());
    putc('\n');
    while (q--){
        char t;
        gic(t);
        int l,r;
        gi(l);
        gi(r);
        if(t=='L'){
            flip_L(l,r);
        }
        if(t=='R'){
            flip_R(l,r);
        }
        if(t=='U'){
            flip_U(l,r);
        }
        if(t=='D'){
            flip_D(l,r);
        }
        print(answer());
        putc('\n');
    }
    return 0;
}
/*

4 5 4
BBRR
RBBR 
BBBBB 
RRRRR 
L 2 3 
R 3 4 
U 1 5 
D 1 5


*/