#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 700005
struct treap{
    treap *l,*r,*f;
    pii Max;
    int val;
    int id;
    int pri;
    treap(int x,int _id):l(NULL),r(NULL),f(NULL),id(_id),val(x),pri((rand()*(1ll<<20)+rand())%1000000000)
    {  
        Max=mp(val,id);
    }
}*node[200005];
pii Max(treap *t){
    return t?t->Max:mp(0,0);
}
void pull(treap *t){
    t->Max=max(max(Max(t->l),Max(t->r)),mp(t->val,t->id));
}
treap* merge(treap *l,treap *r){
    if(!l||!r)return l?l:r;
    if(l->pri<r->pri){
        l->r=merge(l->r,r);
        l->r->f=l;
        pull(l);
        return l;
    }
    else{
        r->l=merge(l,r->l);
        r->l->f=r;
        pull(r);
        return r;
    }
}
void split(treap *t,int k,treap *&l,treap *&r){
    if(!t)l=r=NULL;
    else if(t->id<k){
        l=t;
        split(t->r,k,l->r,r);
        if(r)
        r->f=NULL;
        if(l->r)
        l->r->f=l;
        pull(l);
    }
    else{
        r=t;
        split(t->l,k,l,r->l);
        if(l)
        l->f=NULL;
        if(r->l)
        r->l->f=r;
        pull(r);
    }
}
treap *getf(treap *t){
    while(t->f)t=t->f;
    return t;
}
pii e[300005];
int ok[300005];
int f[200005];
vector<int> v[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int in[200005],out[200005];
int t;
int p[200005];
void dfs(int x,int f){
    in[x]=++t;
    node[t]=new treap(p[x],t);
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=t;
}
void solve(){
    srand(time(NULL));
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);

    for(int i = 1;i<=n;i++)scanf("%d",&p[i]),f[i]=i;
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        e[i]=mp(x,y);
    }
    fill(ok,ok+m+1,1);
    vector<pii> qu;
    for(int i =1;i<=q;i++){
        int op,x;
        scanf("%d %d",&op,&x);
        qu.pb(mp(op,x));
        if(op==2)ok[x]=0;
    }
    for(int i = 1;i<=m;i++){
        if(ok[i]){
            int x,y;
            tie(x,y)=e[i];
            x=Find(x);
            y=Find(y);
            if(x!=y){
                v[e[i].x].pb(e[i].y);
                v[e[i].y].pb(e[i].x);
                f[x]=y;
            }
        }
    }
    for(int i = q-1;i>=0;i--){
        if(qu[i].x==2){
            int x,y;
            tie(x,y)=e[qu[i].y];
            int fx=Find(x),fy=Find(y);
            if(fx!=fy){
                ok[qu[i].y]=1;
                v[x].pb(y);
                v[y].pb(x);
                f[fx]=fy;
            }
        }
    }
    int lastnum=0;
    for(int i = 1;i<=n;i++){
        if(in[i]==0){
            dfs(i,0);
            treap *last=node[lastnum+1];
            for(int j=lastnum+2;j<=t;j++){
                last=merge(last,node[j]);
            }
            lastnum=t;
        }
    }
   /* dfs(1,0);
    for(int i = 1;i<=n;i++){
        node[in[i]]=new treap(p[i],in[i]);
    }
    treap *last=node[1];
    for(int i = 2;i<=n;i++){
        last=merge(last,node[i]);
    }*/
   // printf("?\n");
    for(int i = 0;i<q;i++){
        if(qu[i].x==2&&ok[qu[i].y]){
            int x,y;
            tie(x,y)=e[qu[i].y];
            if(in[x]<in[y])swap(x,y);
            treap *t=getf(node[in[y]]);
            treap *l,*mid,*r;
            split(t,in[x],l,mid);
            split(mid,out[x]+1,mid,r);
            if(l)
            l->f=NULL;
            mid->f=NULL;
            if(r)
            r->f=NULL;
            t=merge(l,r);
        }
        if(qu[i].x==1){
            int v=qu[i].y;
            treap *t=getf(node[in[v]]);
            printf("%d\n",t->Max.x);
            if(t->Max.x){
            int re=t->Max.y;
            treap *l,*mid,*r;
            split(t,re,l,mid);
            split(mid,re+1,mid,r);
            mid->val=0;
            mid->Max=mp(0,mid->id);
            if(l)
            l->f=NULL;
            if(r)
            r->f=NULL;
            mid->f=NULL;
            t=merge(l,merge(mid,r));
            //printf("q2%d %d\n",t->Max.x,t->Max.y);
            }
        }
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/