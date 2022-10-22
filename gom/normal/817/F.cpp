#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int q,n;
ll qry[N][3],x[N*4];
int tree[N*16],lazy[N*16];
void mrg(int p,int v)
{
    if(!lazy[p]){
        lazy[p]=v;
        return;
    }
    if(v==3){
        lazy[p]=3-lazy[p];
        return;
    }
    lazy[p]=v;
}
void pushdown(int nd,int l,int r)
{
    if(!lazy[nd]) return;
    if(l!=r){
        mrg(nd*2,lazy[nd]);
        mrg(nd*2+1,lazy[nd]);
    }
    if(lazy[nd]==1) tree[nd]=r-l+1;
    if(lazy[nd]==2) tree[nd]=0;
    if(lazy[nd]==3) tree[nd]=r-l+1-tree[nd];
    lazy[nd]=0;
}
void update(int nd,int l,int r,int s,int e,int v)
{
    pushdown(nd,l,r);
    if(r<s||e<l) return;
    if(s<=l&&r<=e){
        lazy[nd]=v;
        pushdown(nd,l,r);
        return;
    }
    int m=(l+r)/2;
    update(nd*2,l,m,s,e,v);
    update(nd*2+1,m+1,r,s,e,v);
    tree[nd]=tree[nd*2]+tree[nd*2+1];
}
ll query(int nd,int l,int r)
{
    pushdown(nd,l,r);
    if(l==r) return x[l];
    int m=(l+r)/2;
    pushdown(nd*2,l,m); pushdown(nd*2+1,m+1,r);
    if(tree[nd*2]==m-l+1) return query(nd*2+1,m+1,r);
    else return query(nd*2,l,m);
}
int xto(ll v)
{
    return lower_bound(x+1,x+1+n,v)-x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    x[++n]=1;
    for(int i=1;i<=q;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        qry[i][0]=a; qry[i][1]=b; qry[i][2]=c;
        x[++n]=b; x[++n]=b+1; x[++n]=c; x[++n]=c+1;
    }
    sort(x+1,x+1+n);
    n=unique(x+1,x+1+n)-x-1;
    for(int i=1;i<=q;i++){
        ll a,b,c;
        a=qry[i][0]; b=qry[i][1]; c=qry[i][2];
        b=xto(b); c=xto(c);
        update(1,1,n,b,c,a);
        cout<<query(1,1,n)<<"\n";
    }
    return 0;
}