#include<bits/stdc++.h>
using namespace std;
const int node_size = 1.1e6;
#define ls(o) tr[o].child[0]
#define rs(o) tr[o].child[1]
struct { int child[2],sum; } tr[node_size<<5];
int n,m,cnt,root[node_size];
int a[node_size],b[node_size],rev[node_size];
void modify(int lst,int &now,int l,int r,int pos)
{
    now=++cnt; tr[now]=tr[lst]; ++tr[now].sum;
    if(l==r) return void(); int mid=(l+r)>>1;
    if(pos<=mid) modify(ls(lst),ls(now),l,mid,pos);
        else     modify(rs(lst),rs(now),mid+1,r,pos);
}
int query(int lst,int now,int l,int r,int li,int ri)
{
    if(li<=l&&r<=ri) return tr[now].sum-tr[lst].sum;
    int mid=(l+r)>>1;
    if(ri<=mid) return query(ls(lst),ls(now),l,mid,li,ri);
    if(li >mid) return query(rs(lst),rs(now),mid+1,r,li,ri);
    return  query(ls(lst),ls(now),l,mid,li,ri)+
            query(rs(lst),rs(now),mid+1,r,li,ri);
}
void dfs(int now,int l,int r)
{
    if(l==r) return printf("%d%c",tr[now].sum," \n"[l==n]),void();
    int mid(l+r>>1); dfs(ls(now),l,mid),dfs(rs(now),mid+1,r);
}
int f(int lst,int val) { return (val+lst-1)%n+1; }
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int i=1;i<=n;++i) scanf("%d",b+i);
    for(int i=1;i<=n;++i) rev[a[i]]=i;
    for(int i=1;i<=n;++i) modify(root[i-1],root[i],1,n,rev[b[i]]);
    scanf("%d",&m);
    for(int a,b,c,d,lst=0;m;m--,lst++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d); 
        a=f(lst,a),b=f(lst,b),c=f(lst,c),d=f(lst,d);
        if(a>b) swap(a,b); if(c>d) swap(c,d);
        printf("%d\n",lst=query(root[c-1],root[d],1,n,a,b));
    }
    return 0;
}