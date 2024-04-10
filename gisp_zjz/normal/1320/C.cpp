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
    ll lazy,val;
};
bool cmp(node u,node v){
    return u.x<v.x;
}
int n,m,q;
ll a[maxn],b[maxn],ans;
const ll inf=1e18;
pt T[maxn*9];
void update(int p){
    T[p].val=max(T[p*2].val,T[p*2+1].val);
}
void build(int p,int l,int r){
    if (l==r) {T[p].val=-b[l];return;}
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
void modify(int p,int l,int r,int nl,int nr,ll v){
    //cout<<p<<' '<<l<<' '<<r<<' '<<nl<<' '<<nr<<' '<<v<<endl;
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
ll qry(int p,int l,int r,int nl,int nr){
    if (nl<=l&&r<=nr) return T[p].val;
    int mid=(l+r)>>1;
    ll ret=-inf;
    if (nl<=mid) ret=max(ret,qry(p*2,l,mid,nl,nr));
    if (nr>mid) ret=max(ret,qry(p*2+1,mid+1,r,nl,nr));
    return ret;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=E;i++) a[i]=b[i]=inf;
    for (int i=1;i<=n;i++){
        int x,y;scanf("%d%d",&x,&y);
        a[x]=min(a[x],(ll)y);
    }
    for (int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        b[x]=min(b[x],(ll)y);
    }
    for (int i=E;i;i--) a[i-1]=min(a[i-1],a[i]),b[i-1]=min(b[i-1],b[i]);
    //for (int i=1;i<=E;i++)cout<<b[i]<<' ';cout<<endl;
    ans=-a[1]-b[1];
    for (int i=1;i<=q;i++) {
        scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
        c[i].x++; c[i].y++;
    }
    sort(c+1,c+q+1,cmp);
    build(1,1,E);
    int pos=1;
    for (int i=1;i<=E;i++){
        bool o=0;
        while (pos<=q&&c[pos].x==i){
            o=1;
            modify(1,1,E,c[pos].y,E,c[pos].z);
            ++pos;
        }
        if (o) ans=max(ans,qry(1,1,E,1,E)-a[i]);
    }
    cout << ans << endl;
    return 0;
}