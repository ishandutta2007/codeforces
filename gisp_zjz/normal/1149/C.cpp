#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=400050;
int a[maxn];
char s[maxn];
int n,q;
int v[maxn],lf,rt;
void Min(int &x,int y){if (y<x) x=y;}
void Max(int &x,int y){if (y>x) x=y;}
struct node{
    int mx,mn,ans,ml,mr,lazy;
};
node _merge(node u,node v){
    node ret;
    ret.mx=max(u.mx,v.mx);
    ret.mn=min(u.mn,v.mn);
    ret.ml=max(max(u.ml,v.ml),u.mx-2*v.mn);
    ret.mr=max(max(u.mr,v.mr),v.mx-2*u.mn);
    ret.ans=max(max(u.ans,v.ans),max(u.ml+v.mx,u.mx+v.mr));
    ret.lazy=0;
    return ret;
}
struct segtree{
    node b[maxn*4];
    void pushup(int k){
        b[k]=_merge(b[k*2],b[k*2+1]);
    }
    void build(int k,int l,int r){
        if (l==r){
            b[k].mn=b[k].mx=v[l];
            b[k].ans=b[k].lazy=0;
            b[k].ml=b[k].mr=-v[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);
        build(k*2+1,mid+1,r);
        pushup(k);
        //cout<<l<<' '<<r<<' '<<b[k].mx<<' '<<b[k].mn<<' '<<b[k].ml<<' '<<b[k].mr<<' '<<b[k].ans<<endl;
    }
    void pushdown(int k){
        int w=b[k].lazy;
        if (w){
            for(int i=k*2;i<=k*2+1;i++){
                b[i].mx+=w;
                b[i].mn+=w;
                b[i].ml-=w;
                b[i].mr-=w;
                b[i].lazy+=w;
            }
            b[k].lazy=0;
        }
    }
    void update(int k,int l,int r,int x,int y,int v){
        if (l>y||x>r) return;
        if (l>=x&&r<=y){
            b[k].mx+=v;
            b[k].mn+=v;
            b[k].ml-=v;
            b[k].mr-=v;
            b[k].lazy+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
        //cout<<l<<' '<<r<<' '<<b[k].mx<<' '<<b[k].mn<<' '<<b[k].ml<<' '<<b[k].mr<<' '<<b[k].ans<<endl;
    }
    int query(int k){
        pushdown(k);
        return b[k].ans;
    }
}seg;

int main(){
    scanf("%d%d",&n,&q); --n;
    scanf("%s",s+1);
    for (int i=1;i<=n*2;i++) v[i+1]=v[i]+((s[i]=='(')?1:-1);
    seg.build(1,1,n*2+1);
    printf("%d\n",seg.query(1));
    while (q--){
        scanf("%d%d",&lf,&rt);
        if (lf>rt) swap(lf,rt);
        if (s[lf]=='('&&s[rt]==')') seg.update(1,1,n*2+1,lf+1,rt,-2);
        if (s[lf]==')'&&s[rt]=='(') seg.update(1,1,n*2+1,lf+1,rt,2);
        swap(s[lf],s[rt]);
        printf("%d\n",seg.query(1));
    }
    return 0;
}