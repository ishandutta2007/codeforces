/**
 *    author:  gary
 *    created: 01.04.2022 09:56:43
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
__int128_t gcd(__int128_t A,__int128_t B){
    if(B==0) return A;
    return gcd(B,A%B);
}
__int128_t lcm(__int128_t A,__int128_t B){
    return A/gcd(A,B)*B;
}
const int MAXN=1001;
int n,m;
__int128_t a[MAXN],b[MAXN];
bool ea[MAXN],eb[MAXN];
const int N=1<<10;
struct Segmenttree{
    __int128_t B;
    __int128_t tree[N+N];
    Segmenttree(){memset(tree,0,sizeof(tree));}
    void buildtree(){
        rb(i,1,N) tree[i+N-1]=gcd(tree[i+N-1],B);
        rl(i,N-1,1) tree[i]=lcm(tree[i<<1],tree[i<<1|1]);
    }
    __int128_t query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return 1;
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)>>1;
        return lcm(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
    void clr(int now){
        now+=N-1;
        tree[now]=1;
        now>>=1;
        while (now){
            tree[now]=lcm(tree[now<<1],tree[now<<1|1]);
            now>>=1;
        }
    }
}tra[MAXN],trb[MAXN];
void solve(){
    gi(n);
    gi(m);
    rb(i,1,n) gi(a[i]),ea[i]=0;
    rb(i,1,m) gi(b[i]),eb[i]=0;
    rb(i,1,m) {
        tra[i].B=b[i];
        rb(j,1,n) tra[i].tree[j+N-1]=a[j];
        tra[i].buildtree();
    }
    rb(i,1,n){
        trb[i].B=a[i];
        rb(j,1,m) trb[i].tree[j+N-1]=b[j];
        trb[i].buildtree();
    }
    while (true){
        bool ok=0;
        rb(i,1,n) if(!ea[i]&&trb[i].query(1,m+1)!=a[i]){
            ok=1;
            ea[i]=1;
            rb(j,1,m) tra[j].clr(i);
        }
        rb(i,1,m) if(!eb[i]&&tra[i].query(1,n+1)!=b[i]){
            ok=1;
            eb[i]=1;
            rb(j,1,n) trb[j].clr(i);
        }
        if(!ok) break;
    }
    if(*min_element(ea+1,ea+1+n)+*min_element(eb+1,eb+1+m)==0){
        vector<__int128_t> ans1,ans2;
        rb(i,1,n) if(!ea[i]) ans1.PB(a[i]);
        rb(i,1,m) if(!eb[i]) ans2.PB(b[i]);
        putc('Y');putc('E');putc('S');putc('\n');
        print(ans1.size());putc(' ');print(ans2.size());putc('\n');
        for(auto it:ans1) print(it),putc(' ');
        putc('\n');
        for(auto it:ans2) print(it),putc(' ');
        putc('\n');
    }
    else{
        putc('N');putc('O');putc('\n');

    }
}
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int t;
    gi(t);
    while (t--)
    {
        solve();
    }
    return 0;
}