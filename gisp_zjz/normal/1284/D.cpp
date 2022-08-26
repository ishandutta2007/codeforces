#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e6+3;
typedef long long ll;
map <int,int> f;
set <int> s;
typedef pair<ll,ll> pi;
int n,x[maxn],y[maxn],xx[maxn],yy[maxn],cc;
ll b[maxn],c[maxn];
struct node{
    int op,t,l,r;
}a[maxn];
bool cmp(node u,node v){
    if (u.t!=v.t) return u.t<v.t;
    return u.op>v.op;
}
void add1(int x,ll y){
    while (x<maxn) b[x]+=y,x+=x&(-x);
}
void add2(int x,ll y){
    while (x<maxn) c[x]+=y,x+=x&(-x);
}
ll qry1(int x){
    ll ret=0;
    while (x) ret+=b[x],x-=x&(-x);
    return ret;
}
ll qry2(int x){
    ll ret=0;
    while (x) ret+=c[x],x-=x&(-x);
    return ret;
}
ll qry(int x){
    return qry1(x)+x*qry2(x);
}
bool work(){
    for (int i=1;i<=n;i++) {
        a[i*2-1]=(node){1,x[i],xx[i],yy[i]};
        a[i*2]=(node){0,y[i],xx[i],yy[i]};
    }
    sort(a+1,a+n*2+1,cmp);
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (int i=1;i<=n*2;i++){
            //cout<<a[i].op<<' '<<a[i].l<<' '<<a[i].r<<endl;
        if (a[i].op==0){
            add1(a[i].r+1,a[i].r-a[i].l+1);
            add2(a[i].l,1);
            add2(a[i].r+1,-1);
            add1(a[i].l,-a[i].l+1);
            add1(a[i].r+1,a[i].l-1);
        } else {
            ll sum=qry(a[i].r)-qry(a[i].l-1);
            if (sum) return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
    f.clear(); s.clear(); cc=0;
    for (int i=1;i<=n;i++) if (s.find(x[i])==s.end()) s.insert(x[i]);
    for (int i=1;i<=n;i++) if (s.find(y[i])==s.end()) s.insert(y[i]);
    for (auto x:s) f[x]=++cc;
    for (int i=1;i<=n;i++) x[i]=f[x[i]],y[i]=f[y[i]];
    f.clear(); s.clear(); cc=0;
    for (int i=1;i<=n;i++) if (s.find(xx[i])==s.end()) s.insert(xx[i]);
    for (int i=1;i<=n;i++) if (s.find(yy[i])==s.end()) s.insert(yy[i]);
    for (auto x:s) f[x]=++cc;
    for (int i=1;i<=n;i++) xx[i]=f[xx[i]],yy[i]=f[yy[i]];
    if (work()) {puts("NO");return 0;}
    for (int i=1;i<=n;i++) swap(x[i],xx[i]),swap(y[i],yy[i]);
    if (work()) puts("NO"); else puts("YES");
    return 0;
}