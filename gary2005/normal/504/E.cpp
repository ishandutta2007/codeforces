/**
 *    author:  gary
 *    created: 16.03.2022 08:36:36
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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=3e5+10;
char ch[MAXN];
int Lg[MAXN];
int Highbit[MAXN];
const int MOD=1e9+7;
const int AA=29;
struct string_hash{
    vector<int> g[MAXN];
    int pw[MAXN],ipw[MAXN],depth[MAXN],fa[19][MAXN],hasH[MAXN],hash2[MAXN],tp[MAXN],le[MAXN],hs[MAXN];
    vector<int> up[MAXN],dow[MAXN];
    int quick(int A,int B){
        if(B==0) return 1;
        int tmp=quick(A,B>>1);
        tmp=1ll*tmp*tmp%MOD;
        if(B&1) tmp=1ll*tmp*A%MOD;
        return tmp;
    }
    string_hash(){
        memset(hs,0,sizeof(hs));
        memset(hasH,0,sizeof(hasH));
        memset(hash2,0,sizeof(hash2));
        memset(depth,0,sizeof(depth));
        memset(fa,0,sizeof(fa));
        pw[0]=1;
        rb(i,1,MAXN-1) pw[i]=1ll*pw[i-1]*AA%MOD;
        ipw[0]=1;
        ipw[1]=quick(AA,MOD-2);
        rb(i,2,MAXN-1) ipw[i]=1ll*ipw[i-1]*ipw[1]%MOD;
    }
    void init(int now,int pre=0){
        le[now]=1;
        tp[now]=now;
        hasH[now]=(1ll*hasH[pre]*AA+ch[now]-'a')%MOD;
        hash2[now]=(1ll*pw[depth[now]]*(ch[now]-'a')+hash2[pre])%MOD;
        for(auto it:g[now]) if(it!=pre) depth[it]=depth[now]+1,init(it,now),check_max(le[now],le[it]+1);
        for(auto it:g[now]) if(it!=pre&&le[it]+1==le[now]){
            hs[now]=it;
            tp[it]=now;
            break;
        }
    }
    void init2(int now,int pre=0){
        if(tp[now]!=now) tp[now]=tp[tp[now]];
        fa[0][now]=pre;
        rb(j,1,18) fa[j][now]=fa[j-1][fa[j-1][now]];
        for(auto it:g[now]) if(it!=pre) init2(it,now);
    }
    void dfs1(int now){
        dow[tp[now]].PB(now);
        if(hs[now]) dfs1(hs[now]);
    }
    void dfs2(int now,vector<int> &v,int to){
        if(v.size()==to) return;
        v.PB(now);
        if(fa[0][now]) dfs2(fa[0][now],v,to);
    }
    void init3(int n){
        rb(i,1,n) if(tp[i]==i){
            dfs1(i);
            dfs2(i,up[i],le[i]);
        }
    }
    int jump(int u,int k){
        if(!k) return u;
        int hb=Highbit[k];
        u=fa[hb][u];
        k^=1<<hb;
        if(!k) return u;
        int T,L;
        T=tp[u];
        L=depth[u]-depth[T];
        if(k>L){
            k-=L;
            return up[T][k];
        }
        else{
            return dow[T][L-k];
        }
    }
    int lca(int u,int v){
        if(depth[u]<depth[v]) swap(u,v);
        u=jump(u,depth[u]-depth[v]);
        if(u==v) return u;
        rl(i,18,0) if(fa[i][u]!=fa[i][v]) u=fa[i][u],v=fa[i][v];
        return fa[0][u];
    }
}H;
int gethash(int u,int v){
    if(H.depth[u]<H.depth[v]){
        return 1ll*(H.hash2[v]-H.hash2[H.fa[0][u]]+MOD)*H.ipw[H.depth[u]]%MOD;
    }
    else{
        return (H.hasH[u]-1ll*H.hasH[H.fa[0][v]]*H.pw[H.depth[u]-H.depth[v]+1]%MOD+MOD)%MOD;    
    }
}
int gethash2(int u,int v,int U,int V){
    return (1ll*gethash(U,V)*H.pw[abs(H.depth[u]-H.depth[v])+1]+gethash(u,v))%MOD;
}
int l1,l2;
int A,B,C,D,x,y;
int a,b,c,d;
bool check(int mid){
    if(mid>min(A+B,C+D)+1) return 0;
    int H1,H2;
    if(mid<=A) H1=gethash(a,H.jump(a,mid-1));
    else{
        if(mid==A+1){
            H1=gethash(a,l1);
        }
        else{
            H1=gethash2(a,l1,x,H.jump(b,B-(mid-(A+1))));
        }
    }
    if(mid<=C) H2=gethash(c,H.jump(c,mid-1));
    else{
        if(mid==C+1){
            H2=gethash(c,l2);
        }
        else{
            H2=gethash2(c,l2,y,H.jump(d,D-(mid-(C+1))));
        }
    }
    return H1==H2;
}
int solve(){
    if(ch[a]!=ch[c]) return 0;
    l1=H.lca(a,b);
    l2=H.lca(c,d);
    A=H.depth[a]-H.depth[l1];
    B=H.depth[b]-H.depth[l1];
    if(B>=1) x=H.jump(b,B-1);
    C=H.depth[c]-H.depth[l2];
    D=H.depth[d]-H.depth[l2];
    if(D>=1) y=H.jump(d,D-1);
    int l=0,r=min(A+B+1,C+D+1)+1;
    while (l<r-1){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    return l;
}
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
        inline void gic (char &x) {
            x=gc();
            while (x>'z'||x<'a'){
                x=gc();
            }
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
using io :: gic;
using io :: gi;
using io :: putc;
using io :: print;
int main(){
    rep(i,19) Lg[1<<i]=i;
    rb(i,1,MAXN-1){
        rl(j,18,0){
            if((i>>j)&1){
                Highbit[i]=j;
                break;
            }
        }
    }
    int n;
    gi(n);
    rb(i,1,n) gic(ch[i]);
    rb(i,1,n-1){
        int u,v;
        gi(u);
        gi(v);
        H.g[u].PB(v);
        H.g[v].PB(u);
    }
    H.init(1);
    H.init2(1);
    H.init3(n);
    int q;
    gi(q);
    while (q--){
        gi(a);
        gi(b);
        gi(c);
        gi(d);
        print(solve());
        putc('\n');
    }
    return 0;
}