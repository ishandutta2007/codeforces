#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mxn=5e5+10;
struct linkcut
{
    struct node
    {
        int p,l,r;
        bool inv;
        ll v,mx,lz;
        node(){p=l=r=0,inv=0,v=mx=-INF,lz=0;}
    }tr[mxn*2];
    linkcut(){}
    vector<int>nv;
    inline bool isroot(int x)
    {
        node&c=tr[x];
        return c.p<=0||(tr[c.p].l!=x&&tr[c.p].r!=x);
    }
    inline void iput(int x)
    {
        if(x==0)
            return;
        node&c=tr[x];
        swap(c.l,c.r);
        c.inv=!c.inv;
        return;
    }
    inline void put(int x,ll p)
    {
        if(x==0)
            return;
        node&c=tr[x];
        c.v+=p,c.mx+=p,c.lz+=p;
        return;
    }
    inline void prop(int x)
    {
        node&c=tr[x];
        if(c.inv)
            iput(c.l),iput(c.r);
        if(c.lz!=0)
            put(c.l,c.lz),put(c.r,c.lz);
        c.inv=0;
        c.lz=0;
        return;
    }
    inline void upd(int x)
    {
        node&c=tr[x];
        c.mx=c.lz+max({c.v,tr[c.l].mx,tr[c.r].mx});
        return;
    }
    inline void rot(int x)
    {
        node&c=tr[x];
        int pp=c.p;
        node&p=tr[pp];
        int b=0;
        if(x==p.l)
            b=p.l=c.r,c.r=pp;
        else
            b=p.r=c.l,c.l=pp;
        if(b!=0)
            tr[b].p=pp;
        if(!isroot(pp))
            (pp==tr[p.p].l?tr[p.p].l:tr[p.p].r)=x;
        c.p=p.p,p.p=x;
        upd(pp);
        upd(x);
        return;
    }
    inline void splay(int x)
    {
        vector<int>v(1,x);
        for(int y=x;!isroot(y);v.eb(y=tr[y].p));
        reverse(all(v));
        for(int&t:v)
            prop(t);
        node&c=tr[x];
        while(!isroot(x))
        {
            int pp=c.p;
            node&p=tr[pp];
            if(!isroot(pp))
                rot((tr[p.p].l==pp)==(p.l==x)?pp:x);
            rot(x);
        }
        return;
    }
    inline int access(int x)
    {
        int y=x;
        node&c=tr[x];
        splay(x);
        c.r=0;
        upd(x);
        while(c.p>0)
        {
            splay(y=c.p);
            tr[y].r=x;
            upd(y);
            splay(x);
        }
        return y;
    }
    inline int lca(int x,int y)
    {
        access(x);
        int l1=access(y);
        int l2=access(x);
        return l1==l2?l1:0;
    }
    inline void makeroot(int x)
    {
        access(x);
        iput(x);
        return;
    }
    inline void init(int n)
    {
        for(int i=0;i<mxn*2;i++)
            tr[i]=node();
        nv.clear();
        for(int i=n+1;i<mxn*2;i++)
            nv.eb(i);
        return;
    }
    inline int newnode()
    {
        int cur=nv.back();
        nv.pop_back();
        tr[cur]=node();
        return cur;
    }
    inline void delnode(int x)
    {
        tr[x]=node();
        nv.eb(x);
        return;
    }
    inline void link(int x,int y)
    {
        node&c=tr[x];
        makeroot(x);
        access(x);
        int z=newnode();
        tr[z].v=tr[z].mx=0;
        c.p=z;
        tr[z].p=y;
        return;
    }
    inline void cut(int x,int y)
    {
        node&c=tr[x];
        node&d=tr[y];
        makeroot(y);
        access(x);
        prop(x);
        prop(c.l);
        int z;
        if(c.l==y)
            z=tr[c.l].r;
        else
            z=c.l;
        c.p=d.p=c.l=d.l=c.r=d.r=0;
        delnode(z);
        upd(x);
        upd(y);
        return;
    }
    inline void pathupd(int x,int y,ll p)
    {
        if(lca(x,y)==0)
            return;
        makeroot(x);
        access(y);
        splay(x);
        put(x,p);
        return;
    }
    inline ll pathq(int x,int y)
    {
        if(lca(x,y)==0)
            return-INF;
        makeroot(x);
        access(y);
        splay(x);
        return tr[x].mx;
    }
}lct;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<pi>ve(m);
    for(pi&t:ve)
        cin>>t.fi>>t.se;
    lct.init(n);
    ll ans=0;
    for(int i=0,j=0;i++<m;)
    {
        int u=ve[i-1].fi,v=ve[i-1].se;
        while(lct.pathq(u,v)>0)
        {
            int cu=ve[j].fi,cv=ve[j].se;
            int ne=lct.pathq(cu,cv);
            if(ne>0)
                lct.pathupd(ve[ne-1].fi,ve[ne-1].se,-ne);
            lct.cut(cu,cv);
            j++;
            if(ne>0)
                lct.link(ve[ne-1].fi,ve[ne-1].se);
        }
        if(lct.lca(u,v)==0)
            lct.link(u,v);
        else
            lct.pathupd(u,v,i);
        ans+=i-j;
    }
    cout<<ans<<endl;
    return 0;
}