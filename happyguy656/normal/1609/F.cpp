#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(rint i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rint register int
#define uu unsigned
#define scanf a1234=scanf
#define eee __builtin_popcountll
int a1234;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e6+3;
ll b[mxn];
int b1[mxn],n1,b2[mxn],n2;
int n;
struct node{
    node*ch[2],*prt;
    int siz,v1,v2;
    inline void up(){siz=ch[0]->siz+ch[1]->siz+v2-v1+1;}
}*nil;
class P{
    public:
    node*rt;
    inline void init(){
        rt=nil;
    }
    inline void rotate(node*x){
        node*f=x->prt,*g=f->prt;
        int k=son(x),kk=son(f);
        conn(x->ch[k^1],f,k),conn(f,x,k^1);
        f->up(),x->up();
        if(g==nil)rt=x,rt->prt=nil;
        else conn(x,g,kk);
    }
    inline void conn(node*x,node*f,int k){f->ch[k]=x;if(x!=nil)x->prt=f;}
    inline bool son(node*x){return x==x->prt->ch[1];}
    inline void splay(node*x,node*y=nil){
        while(x->prt!=y){
            node*f=x->prt;
            if(f->prt==y)return rotate(x);
            if(son(x)^son(f))rotate(x),rotate(x);
            else rotate(f),rotate(x);
        }
    }
    inline node*find(int r){
        node*x=rt;
        while(1){
            if(x->v2==r)return splay(x),x;
            x=x->ch[r>x->v2];
        }
    }
    inline void ins(int l,int r){
        if(rt==nil)return rt=newd(l,r),void();
        node*x=rt;
        while(1){
            x->siz+=r-l+1;
            node*&nxt=x->ch[l>x->v1];
            if(nxt==nil)return nxt=newd(l,r,x),splay(nxt),            assert(nil->siz==0);;
            x=nxt;
        }
                    assert(nil->siz==0);
    }
    inline node*newd(int l,int r,node*f=nil){
        node*x=new node(*nil);
        x->prt=f,x->v1=l,x->v2=r,x->siz=1;
        return x;
    }
    inline void era(int l,int r){
        find(r);
        node*x;
        if(rt->ch[0]==nil)x=rt->ch[1];
        else if(rt->ch[1]==nil)x=rt->ch[0];
        else{
            x=rt->ch[0];
            while(x->ch[1]!=nil)x=x->ch[1];
            splay(x,rt);
            conn(rt->ch[1],x,1);
        }
        delete rt;rt=x;if(rt==nil)return;x->up(),x->prt=nil;
    }
    inline int getrk(int v){
        if(rt==nil)return 0;
        int res=0;
        node*x=rt,*nxt;
        while(1){
            if(v>=x->v1&&v<=x->v2)return res+=x->ch[0]->siz+v-x->v1+1,splay(x),res;
            nxt=x->ch[v>x->v2];
            if(v>x->v2)res+=x->ch[0]->siz+x->v2-x->v1+1;
            if(nxt==nil)return splay(x),res;
            x=nxt;
        }
    }
    int ask(int l,int r){int re=getrk(r)-getrk(l-1);return re;}
}d[2][61];
int vv;
void era(int l,int r,int k){
    int x=eee(b[l]);
    vv-=d[k^1][x].ask(l,r);
    d[k][x].era(l,r);
}
void ins(int l,int r,int k){
    int x=eee(b[l]);
    vv+=d[k^1][x].ask(l,r);
    d[k][x].ins(l,r);
}

int main(){
    nil=new node;nil->ch[0]=nil->ch[1]=nil->prt=nil;nil->siz=0;
    for(int i=0;i<=1;++i)for(int j=0;j<=60;++j)d[i][j].init();
    cin>>n;for(int i=1;i<=n;++i)scanf("%lld",b+i);
    ll ans=0;b1[0]=b2[0]=n+1;
    for(int t=n;t;--t){
        while(n1&&b[t]>=b[b1[n1]])era(b1[n1],b1[n1-1]-1,0),--n1;
        ins(t,b1[n1]-1,0),b1[++n1]=t;
        while(n2&&b[t]<=b[b2[n2]])era(b2[n2],b2[n2-1]-1,1),--n2;
        ins(t,b2[n2]-1,1),b2[++n2]=t;
        ans+=vv;
    }
    cout<<ans<<endl;
    return 0;
}