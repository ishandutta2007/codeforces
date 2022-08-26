#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
bool vis[maxn];
int n,f[2][maxn],a[maxn],v[maxn];
struct node{
    int to[3],sum[3];
}T[maxn*4];
node w[4];
priority_queue<pi,vector<pi>,greater<pi> > Q;
node _merge(node u,node v){
    node ret;
    for (int i=0;i<3;i++){
        int j=v.to[i];
        ret.to[i]=u.to[j];
        ret.sum[i]=u.sum[j]+v.sum[i];
    }
    return ret;
}
void build(int x,int l,int r){
    if (l==r){
        T[x]=w[v[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    T[x]=_merge(T[x*2],T[x*2+1]);
}
void modify(int x,int l,int r,int p){
    if (l==r){
        T[x]=w[v[l]];
        return;
    }
    int mid=(l+r)>>1;
    if (p<=mid) modify(x*2,l,mid,p);
    else modify(x*2+1,mid+1,r,p);
    T[x]=_merge(T[x*2],T[x*2+1]);
}
node qry(int x,int l,int r,int L,int R){
    if (L<=l&&r<=R) return T[x];
    int mid=(l+r)>>1;
    if (R<=mid) return qry(x*2,l,mid,L,R);
    if (L>mid) return qry(x*2+1,mid+1,r,L,R);
    return _merge(qry(x*2,l,mid,L,R),qry(x*2+1,mid+1,r,L,R));
}
void add(int o,int x,int y){
    f[o][x]+=y;
    int nv=(f[0][x]>0)+(f[1][x]>0)*2;
    if (nv!=v[x]){
        v[x]=nv;
        modify(1,1,n,x);
    }
}
void solve(){
    for (int i=0;i<4;i++){
        for (int j=0;j<3;j++){
            w[i].to[j]=i|j;
            if (w[i].to[j]==3) w[i].to[j]=0,w[i].sum[j]++;
        }
    }
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    ll ans=0;
    for (int i=1;i<=n;i++) add(0,a[i],1);
    for (int i=1;i<=n;i++){
        add(0,a[i],-1);
        if (a[i]>1){
            node tmp=qry(1,1,n,1,a[i]-1);
            ans+=tmp.sum[0]+1;
        } else {
            ans+=a[i];
        }
        add(1,a[i],1);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    while (_--) solve();
}