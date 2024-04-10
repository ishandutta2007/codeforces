#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=998244353;
ll Fast(ll x,int b) {
    ll t=1;
    for(; b; b>>=1,x=x*x%Mod) {
        if(b&1) t=t*x%Mod;
    }
    return t;
}
const int N=4e5+50;
pii a[N],b[N];
map<int,ll> f;
int ans[N];
void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    f.clear();
    {
        int K=0;
        FOR(i,1,n) {
            b[++K]=a[i];
            b[++K]={a[i].fi+a[i].se,0};
        }
        sort(b+1,b+K+1);
        ll u=0,v=0;
        FOR(i,1,K) {
            if(b[i].se==0) ++u,v-=b[i].fi+b[i].se;
            else --u,v+=b[i].fi+b[i].se;
            if(i==K || b[i].fi!=b[i+1].fi) f[b[i].fi]+=u*b[i].fi+v;
        }
    }
    {
        int K=0;
        FOR(i,1,n) {
            b[++K]=a[i];
            b[++K]={a[i].fi-a[i].se,0};
        }
        sort(b+1,b+K+1);
        ll u=0,v=0;
        FOR(i,1,K) {
            if(b[i].se==0) ++u,v-=b[i].fi-b[i].se;
            else --u,v+=b[i].fi-b[i].se;
            if(i==K || b[i].fi!=b[i+1].fi) f[b[i].fi]+=u*b[i].fi+v;
        }
    }
    ll v1=-1e18,v2=-1e18;
    int l=2e9,r=-2e9;
    for(auto [x,p]: f) if(p>m) {
        l=min(l,x);
        r=max(r,x);
        // cerr << p-m << " " << x << endl;
        v1=max(v1,p-m-x);
        v2=max(v2,p-m+x);
    }
    FOR(i,1,n) ans[i]=0;
    FOR(i,1,n) if(a[i].fi-a[i].se<=l && r<=a[i].fi+a[i].se) {
        if(a[i].se-a[i].fi>=v1 && a[i].se+a[i].fi>=v2) ans[i]=1;
    }
    FOR(i,1,n) putchar(ans[i]+'0');
    putchar('\n');
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}