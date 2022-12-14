#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int arriz = 1.1e6;
int n,m,pre[arriz]; ll Ans;
#define ls(o) tr[o].child[0]
#define rs(o) tr[o].child[1]
#define fa(o) tr[o].fa
struct node
{
    int child[2],fa,siz,sum;
    ll ans,all,ad,de,a;
}tr[arriz];
void pushup(int o)
{
    tr[o].sum =tr[ls(o)].sum+tr[rs(o)].sum+tr[o].siz;
    tr[o].all =tr[ls(o)].all+tr[rs(o)].all+tr[o].a*tr[o].siz;
    tr[o].ans =tr[ls(o)].ans+tr[rs(o)].ans+tr[o].ad;
    tr[o].ans+=tr[o].a*(1ll*tr[o].siz*tr[o].siz-tr[o].de);
    tr[o].ans+=2ll*tr[o].a*tr[o].siz*tr[rs(o)].sum;
    tr[o].ans+=2ll*tr[ls(o)].all*(tr[o].sum-tr[ls(o)].sum);
}
bool id(int o) { return rs(fa(o))==o; }
bool nr(int o) { return rs(fa(o))==o||ls(fa(o))==o; }
void rotate(int o)
{
    int x=fa(o),y=fa(x),fg=id(o),b=tr[o].child[!fg];
    if(nr(x)) tr[y].child[id(x)]=o; fa(o)=y;
    tr[x].child[fg]=b,fa(b)=x,tr[o].child[!fg]=x,fa(x)=o;
    return pushup(x),pushup(o);
}
void splay(int o)
{
    for(;nr(o);rotate(o)) if(nr(fa(o)))
        id(o)^id(fa(o))?rotate(o):rotate(fa(o));
}
void access(int o)
{
    for(int lst=0;o;o=fa(lst=o))
    {
        splay(o); 
        tr[o].siz+=tr[rs(o)].sum;
        tr[o].ad+=tr[rs(o)].ans;
        tr[o].de+=1ll*tr[rs(o)].sum*tr[rs(o)].sum;
        rs(o)=lst;
        tr[o].siz-=tr[rs(o)].sum;
        tr[o].ad-=tr[rs(o)].ans;
        tr[o].de-=1ll*tr[rs(o)].sum*tr[rs(o)].sum;
        pushup(o);
    }
}
void link(int x,int y)
{
    access(y); splay(y);
    access(x); splay(x);
    fa(y)=x;
    tr[x].siz+=tr[y].sum;
    tr[x].ad+=tr[y].ans;
    tr[x].de+=1ll*tr[y].sum*tr[y].sum;
    return pushup(x);
}
void cut(int x,int y)
{
    access(x),splay(x),splay(y);
    tr[x].siz-=tr[y].sum;
    tr[x].ad-=tr[y].ans;
    tr[x].de-=1ll*tr[y].sum*tr[y].sum;
    fa(y)=0; return pushup(x);
}
bool check(int x,int y)
{
    access(y),splay(y),splay(x); 
    return nr(y);
}
signed main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;++i) scanf("%d",pre+i);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&tr[i].a);
        tr[i].ans=tr[i].all=tr[i].a;
        tr[i].siz=tr[i].sum=1;
    }
    for(int i=2;i<=n;++i) link(pre[i],i);
    access(1),splay(1),Ans=tr[1].ans;
    printf("%.10lf\n",1.0*Ans/n/n);
    scanf("%d",&m); char op[10];
    for(int x,y;m--;)
    {
        scanf("%s%d%d",op,&x,&y);
        if(op[0]=='P')
        {
            if(check(x,y)) swap(x,y);
            cut(pre[x],x),pre[x]=y,link(pre[x],x);
            access(x),splay(x);
        }
        else 
        {
            access(x),splay(x),tr[x].a=y,pushup(x);
        }
        printf("%.10lf\n",1.0*tr[x].ans/n/n);
    }
    return 0;
}