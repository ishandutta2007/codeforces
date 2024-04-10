#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int E=1e6+5;
const int maxn=1e6+10;
struct node{
    int x,y,z;
}c[maxn];
struct pt{
    int lazy,val;
};
bool cmp(node u,node v){
    return u.x<v.x;
}
int n,m,a[maxn],b[maxn],ra[maxn],rb[maxn];
const ll inf=1e18;
pt T[maxn*9];
void update(int p){
    T[p].val=max(T[p*2].val,T[p*2+1].val);
}
void build(int p,int l,int r){
    if (l==r) {T[p].val=0;return;}
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    update(p);
}
void pushdown(int p){
    ll x=T[p].lazy;
    if (x){
        T[p].lazy=0;
        T[p*2].val+=x;
        T[p*2].lazy+=x;
        T[p*2+1].val+=x;
        T[p*2+1].lazy+=x;
    }
}
void modify(int p,int l,int r,int nl,int nr,int v){
    //if (p==1)cout<<p<<' '<<l<<' '<<r<<' '<<nl<<' '<<nr<<' '<<v<<endl;
    int mid=(l+r)>>1;
    if (nl<=l&&r<=nr){
        T[p].val+=v;
        T[p].lazy+=v;
        return;
    }
    pushdown(p);
    if (nl<=mid) modify(p*2,l,mid,nl,nr,v);
    if (nr>mid) modify(p*2+1,mid+1,r,nl,nr,v);
    update(p);
}
int qry(int p,int l,int r,int nl,int nr){
    if (nl<=l&&r<=nr) return T[p].val;
    int mid=(l+r)>>1;
    int ret=-inf;
    if (nl<=mid) ret=max(ret,qry(p*2,l,mid,nl,nr));
    if (nr>mid) ret=max(ret,qry(p*2+1,mid+1,r,nl,nr));
    return ret;
}
void add(int x){
    modify(1,1,n,1,ra[x],1);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ra[a[i]]=i;
    }
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    build(1,1,n);
    int ans=n; add(ans);
    for (int i=1;i<=n;i++){
        while (qry(1,1,n,1,n)<=0) ans--,add(ans);
        printf("%d ",ans);
        modify(1,1,n,1,b[i],-1);
    }
    return 0;
}