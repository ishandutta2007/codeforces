#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200010,D=20,M=N*D,Mx=(1<<D)-1;
int n,m;
namespace trie{
    int val[M],ls[M],rs[M],tot,tag[M];
    int h0[M],h1[M];
    void setg(int u,int v,int d=D-1)
    {
        if(!u || d<0) return;
        if(v>>d&1) swap(ls[u],rs[u]);
        int p=(h0[u]^h1[u])&v;
        h0[u]^=p;h1[u]^=p;
        tag[u]^=v;
    }
    int ton[M],tp;
    void del(int u)
    {
        h0[u]=h1[u]=ls[u]=rs[u]=tag[u]=val[u]=0;
        ton[++tp]=u;
    }
    int node(){return tp?ton[tp--]:++tot;}
    void push(int u,int d)
    {
        if(tag[u]) setg(ls[u],tag[u],d-1),setg(rs[u],tag[u],d-1),tag[u]=0;
    }
    void upd(int u,int d)
    {
        val[u]=val[ls[u]]+val[rs[u]];
        h0[u]=h0[ls[u]]|h0[rs[u]],h1[u]=h1[ls[u]]|h1[rs[u]];
        if(ls[u]) h0[u]|=1<<d;
        if(rs[u]) h1[u]|=1<<d;
    }
    void insert(int &u,int x,int d=D-1)
    {
        if(!u) u=++tot;
        if(d<0){val[u]=1;return;}
        if(x>>d&1) insert(rs[u],x,d-1);
        else insert(ls[u],x,d-1);
        upd(u,d);
    }
    int merge(int x,int y,int d=D-1)
    {
        if(!x || !y) return x+y;
        if(d<0){val[x]|=val[y];del(y);return x;}
        push(x,d);push(y,d);
        ls[x]=merge(ls[x],ls[y],d-1);
        rs[x]=merge(rs[x],rs[y],d-1);
        upd(x,d);del(y);
        return x;
    }
    void split(int u,int k,int &l,int &r,int d=D-1)
    {
        if(d==-1){l=u;r=0;return;}
        if(!u){l=r=0;return;}
        push(u,d);
        if(k>>d&1) l=u,r=node(),split(rs[u],k,rs[l],rs[r],d-1);
        else l=node(),r=u,split(ls[u],k,ls[l],ls[r],d-1);
        upd(l,d);upd(r,d);
    }
    void set_k(int u,int k,int d=D-1)//set all 0 in k to 1
    {
        if(!u || !(h0[u]>>k&1)) return;
        if(!(h1[u]>>k&1)){setg(u,1<<k,d);return;}
        push(u,d);
        if(d==k){rs[u]=merge(rs[u],ls[u],d-1);ls[u]=0;upd(u,d);return;}
        set_k(ls[u],k,d-1);set_k(rs[u],k,d-1);
        upd(u,d);
    }
    void reset_k(int u,int k,int d=D-1)//set all 1 in k to 0
    {
        if(!u || !(h1[u]>>k&1)) return;
        if(!(h0[u]>>k&1)){setg(u,1<<k,d);return;}
        push(u,d);
        if(d==k){ls[u]=merge(rs[u],ls[u],d-1);rs[u]=0;upd(u,d);return;}
        reset_k(ls[u],k,d-1);reset_k(rs[u],k,d-1);
        upd(u,d);
    }
}
using trie::insert;using trie::merge;using trie::split;
using trie::setg;using trie::set_k;using trie::reset_k;
int root;
void set_xor(int l,int r,int x)
{
    int lt=0,rt=0;
    if(l) split(root,l-1,lt,root);
    split(root,r,root,rt);
    setg(root,x);
    root=merge(merge(lt,root),rt);
}
void set_or(int l,int r,int x)
{
    int lt=0,rt=0;
    if(l) split(root,l-1,lt,root);
    split(root,r,root,rt);
    for(int i=0;i<D;i++) if(x>>i&1) set_k(root,i);
    root=merge(merge(lt,root),rt);
}
void set_and(int l,int r,int x)
{
    int lt=0,rt=0;
    if(l) split(root,l-1,lt,root);
    split(root,r,root,rt);
    for(int i=0;i<D;i++) if(!(x>>i&1)) reset_k(root,i);
    root=merge(merge(lt,root),rt);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x;i<=n;i++) scanf("%d",&x),trie::insert(root,x);
    while(m --> 0)
    {
        int op,l,r,x;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1) scanf("%d",&x),set_and(l,r,x);
        else if(op==2) scanf("%d",&x),set_or(l,r,x);
        else if(op==3) scanf("%d",&x),set_xor(l,r,x);
        else
        {
            int lt=0,rt=0;
            if(l) split(root,l-1,lt,root);
            split(root,r,root,rt);
            printf("%d\n",trie::val[root]);
            root=merge(merge(lt,root),rt);
        }
    }
    return 0;
}