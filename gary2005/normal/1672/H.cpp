/**
 *    author:  gary
 *    created: 29.04.2022 06:56:17
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
const int N=1<<18;
struct node{
    int segleft,segright,y,x,ans,one;
    bool full,Lx,Rx;
    node(){segleft=segright=y=x=ans=0;full=1;one=0;}
    node(int _,int __,int ___,int ____,int _____,bool Lo,bool Ro){
        segleft=_;
        segright=__;
        y=___;
        x=____;
        ans=_____;
        full=1;
        one=1;
        Lx=Lo;
        Rx=Ro;
    }
};
node merge(node A,node B){
    node rest;
    vector<mp> v,v2;
    if(A.x&2) v.PB(II(1,0));
    if(A.y)
    v.PB(II(A.y,1));
    if(A.x&1) if(!A.full) v.PB(II(1,0));
    if(B.x&2) v2.PB(II(1,0));
    if(B.y)
    v2.PB(II(B.y,1));
    if(B.x&1) if(!B.full) v2.PB(II(1,0));
    if((A.segright&1)!=((B.segleft&2)>>1)){
        v2[0].first--;
        v.back().first--;
        v.PB(II(1,1^((A.segright&2)>>1)^(B.segleft&1)));
    }
    for(auto it:v2) v.PB(it);
    rest.ans=A.ans+B.ans;
    bool fir=1;
    while (true){
        bool ok=0;
        if(fir){
            ok=1;
            fir=0;
        }
        else
        rep(i,v.size()){
            if(v[i].second) continue;
            if(i>0&&v[i].first>=2&&v[i-1].first>=1){
                rest.ans+=(v[i].first)/2;
                ok=1;
                v[i].first-=((v[i].first)/2)*2;
            }
            if(i<v.size()-1&&v[i].first>=2&&v[i+1].first>=1){
                rest.ans+=(v[i].first)/2;
                ok=1;
                v[i].first-=((v[i].first)/2)*2;
            }
            if(i<v.size()-1&&i>0&&v[i].first==1&&v[i-1].first>=1&&v[i+1].first>=1){
                int k=min(v[i+1].first,v[i-1].first);
                rest.ans+=k;
                ok=1;
                v[i-1].first-=k;
                v[i+1].first-=k;
            }
            if(v[i].first>=3){
                rest.ans+=(v[i].first-1)/2;
                ok=1;
                v[i].first-=((v[i].first-1)/2)*2;
            }
        }
        vector<mp> newv;
        for(auto it:v){
            if(it.first){
                if(newv.size()&&newv.back().second==it.second) newv.back().first+=it.first;
                else newv.PB(it);
            }
        }
        v.swap(newv);
        if(!ok) break;
    }
    if(v[0].second==0) rest.x|=2;
    if(v.back().second==0) rest.x|=1;
    for(auto it:v) rest.y+=it.second*it.first,rest.one+=it.first;
    rest.Lx=A.Lx;
    rest.Rx=B.Rx;
    rest.segleft|=rest.Lx<<1;
    rest.segright|=rest.Rx;
    if(v[0].second==0) rest.segleft|=rest.Lx^1;
    else rest.segleft|=rest.Lx;
    if(v.back().second==0) rest.segright|=(rest.Rx^1)<<1;
    else rest.segright|=(rest.Rx)<<1;
    rest.full=(rest.one==1);
    return rest;
}
node tree[N+N];
node I0(){
    return node(0,0,1,0,0,0,0);
}
node I1(){
    return node(3,3,1,0,0,1,1);
}
vector<mp> Ve;
int pre=-1;
void work(int idx){
    vector<mp> Seg;
    if(tree[idx].x&2) Seg.PB(II(1,0));
    if(tree[idx].y) Seg.PB(II(tree[idx].y,1));
    if(tree[idx].x&1) if(tree[idx].full==0) Seg.PB(II(1,0));
    if((tree[idx].Lx^1)==pre){
        Ve.back().first--;
        bool Len=Ve.back().second;
        if(Ve.back().first==0) Ve.pop_back();
        Seg[0].first--;
        Ve.PB(II(1,Len^Seg[0].second));
    }
    for(auto it:Seg) if(it.first) Ve.PB(it);
    pre=tree[idx].Rx;
}
int query(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=b&&l>=a){ work(now);return tree[now].ans;}
    int mid=(l+r)>>1;
    if(mid>=b) return query(a,b,now<<1,l,mid);
    if(mid<=a) return query(a,b,now<<1|1,mid,r);
    int tmp=query(a,b,now<<1,l,mid);
    return tmp+query(a,b,now<<1|1,mid,r);
}
int Solve(){
    int ans=0;
    bool fir=1;
    vector<mp> v=Ve;
    while (true){
        bool ok=0;
        if(fir){
            ok=1;
            fir=0;
        }
        else
        rep(i,v.size()){
            if(v[i].second) continue;
            if(i>0&&v[i].first>=2&&v[i-1].first>=1){
                ans+=(v[i].first)/2;
                ok=1;
                v[i].first-=((v[i].first)/2)*2;
            }
            if(i<v.size()-1&&v[i].first>=2&&v[i+1].first>=1){
                ans+=(v[i].first)/2;
                ok=1;
                v[i].first-=((v[i].first)/2)*2;
            }
            if(i<v.size()-1&&i>0&&v[i].first==1&&v[i-1].first>=1&&v[i+1].first>=1){
                int k=min(v[i+1].first,v[i-1].first);
                ans+=k;
                ok=1;
                v[i-1].first-=k;
                v[i+1].first-=k;
            }
            if(v[i].first>=3){
                ans+=(v[i].first-1)/2;
                ok=1;
                v[i].first-=((v[i].first-1)/2)*2;
            }
        }
        vector<mp> newv;
        for(auto it:v){
            if(it.first){
                if(newv.size()&&newv.back().second==it.second) newv.back().first+=it.first;
                else newv.PB(it);
            }
        }
        v.swap(newv);
        if(!ok) break;
    }
    for(auto it:v) ans+=it.first;
    return ans;
}
int main(){
    rb(i,1,N) tree[i+N-1]=I0();
    int n,q;
    gi(n),gi(q);
    rb(i,1,n){
        char c;
        c=gc();
        tree[i+N-1]=(c=='0'? I0():I1());
    }
    rl(i,N-1,1) {
        tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }
    while (q--){
        int l,r;
        gi(l);
        gi(r);
        pre=-1;
        Ve.clear();
        print(query(l,r+1)+Solve());
        putc('\n');
    }
    return 0;
}