#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1e9+7;
ll Fast(ll x,int b) {
    ll t=1;
    for(; b; b>>=1,x=x*x%Mod) {
        if(b&1) t=t*x%Mod;
    }
    return t;
}
const int N=2e5+50;
int a[N];
int b[N];
vector<ll> g[N];
multiset<ll> f;
void print() {
    printf("%lld\n",*f.rbegin());
}
int mark[N];
void solve() {
    int n,q;
    scanf("%d%d",&n,&q);
    FOR(i,0,n-1) scanf("%d",&a[i]);
    int m=0;
    FOR(i,1,n-1) if(n%i==0 && !mark[n/i]) {
        b[++m]=i;
        g[m].clear();
        g[m].resize(b[m],0);
    }
    FOR(i,0,n-1) FOR(j,1,m) g[j][i%b[j]]+=1ll*a[i]*b[j];
    f.clear();
    FOR(i,1,m) FOR(j,0,b[i]-1) f.insert(g[i][j]);
    print();
    while(q--) {
        int i,x;
        scanf("%d%d",&i,&x);
        --i;
        FOR(j,1,m) {
            f.erase(f.find(g[j][i%b[j]]));
            // cerr << " -- " << a[i] << endl;
            g[j][i%b[j]]-=1ll*a[i]*b[j];
        }
        a[i]=x;
        FOR(j,1,m) {
            g[j][i%b[j]]+=1ll*a[i]*b[j];
            f.insert(g[j][i%b[j]]);
        }
        print();
    }
}
int main() {
    int n=2e5;
    FOR(i,2,n) if(!mark[i]) {
        for(int j=i+i; j<=n; j+=i) {
            mark[j]=1;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}