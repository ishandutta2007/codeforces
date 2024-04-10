/**
 *    author:  gary
 *    created: 08.07.2022 22:33:50
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
const int MAXN=4e5+10;
const int N=1<<18;
struct BIT{
    int tree[MAXN];
    void clear(){memset(tree,0,sizeof(tree));}
    void add(int pos,int val){
        while(pos<MAXN){tree[pos]+=val;pos+=pos&-pos;}
    }
    int query(int pos){
        pos=max(pos,0);
        int s=0;
        while(pos){
            s+=tree[pos];
            pos-=pos&-pos;
        }
        return s;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
    BIT(){clear();}
}bit;
struct segmenttree{
    LL tag[N+N];
    LL tree[N+N];
    int siz[N+N];
    segmenttree(){memset(tag,0,sizeof(tag));memset(tree,0,sizeof(tree));memset(siz,0,sizeof(siz));}
    void pd(int now){
        tree[now]+=tag[now]*siz[now];
        if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now];
        tag[now]=0;
    }
    void addval(int a,int b,int val,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a) {tag[now]+=val;pd(now);return;}
        int mid=(l+r)>>1;
        addval(a,b,val,now<<1,l,mid);
        addval(a,b,val,now<<1|1,mid,r);
        tree[now]=tree[now<<1]+tree[now<<1|1];
        siz[now]=siz[now<<1]+siz[now<<1|1];
    }
    void addcnt(int a,int b,int val,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a) {siz[now]+=val;pd(now);return;}
        int mid=(l+r)>>1;
        addcnt(a,b,val,now<<1,l,mid);
        addcnt(a,b,val,now<<1|1,mid,r);
        tree[now]=tree[now<<1]+tree[now<<1|1];
        siz[now]=siz[now<<1]+siz[now<<1|1];
    }
    LL querysum(int a,int b,int now=1,int l=1,int r=N+1){
        pd(now);
        if(r<=a||l>=b) return 0;
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)>>1;
        return querysum(a,b,now<<1,l,mid)+querysum(a,b,now<<1|1,mid,r);
    }
    int querycnt(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return 0;
        if(r<=b&&l>=a) return siz[now];
        int mid=(l+r)>>1;
        return querycnt(a,b,now<<1,l,mid)+querycnt(a,b,now<<1|1,mid,r);
    }
}C,pre;
LL rest;
bool in[MAXN];
int d;
LL contributionA(int ai){
    return pre.querysum(ai+1,ai+1+d)-1ll*(bit.query(ai)+1)*pre.querycnt(ai+1,ai+1+d);
}
LL contributionB(int ai){
    return C.querysum(ai+1,ai+1+d)-pre.querysum(ai+1,ai+1+d)+1ll*pre.querycnt(ai+1,ai+1+d)*bit.query(ai);
}
LL contributionC(int ai){
    return 1ll*pre.querycnt(ai-d,ai)*(bit.query(ai)-1)-pre.querysum(ai-d,ai);
}
LL contribution(int ai){
    return contributionA(ai)+contributionB(ai)+contributionC(ai);
}
void add_ele(int ai){
    in[ai]=1;
    bit.add(ai,1);
    C.addcnt(ai,ai+1,1);
    C.addval(ai,ai+1,bit.query(ai-d,ai-1));
    C.addval(ai+1,ai+1+d,1);
    pre.addcnt(ai,ai+1,1);
    pre.addval(ai,ai+1,bit.query(ai));
    pre.addval(ai+1,N+1,1);
    // cout<<contributionC(ai)<<"___"<<ai<<endl;
    rest+=contribution(ai);
}
void era_ele(int ai){
    rest-=contribution(ai);
    in[ai]=0;
    C.addval(ai,ai+1,-bit.query(ai-d,ai-1));
    C.addcnt(ai,ai+1,-1);
    C.addval(ai+1,ai+1+d,-1);
    pre.addval(ai,ai+1,-bit.query(ai));
    pre.addcnt(ai,ai+1,-1);
    pre.addval(ai+1,N+1,-1);
    bit.add(ai,-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q>>d;
    while (q--){
        int ai;
        cin>>ai;
        in[ai]? era_ele(ai):add_ele(ai);
        cout<<rest<<'\n';
    }
    return 0;
}