#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<ll>val;
vector<P>must_same[500005];
vector<int>atn[500005];
vector<P>edge;
int n,m,k;
ll a[500005];
ll bin[500005];
struct union_find{
    int par[600005],ran[600005];
    void init(int v){ for(int i=0;i<v;i++) par[i] = i,ran[i] = 0; }
    int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
    void unite(int x,int y){
        x = find(x); y = find(y); if(x==y) return;
        if(ran[x] < ran[y]) par[x] = y;
        else{
            par[y] = x;
            if(ran[x] == ran[y]) ran[x]++;
        }
    }
    bool same(int x,int y){ return find(x)==find(y); }
}kaede;

int main(){
    bin[0] = 1;
    repn(i,500004) bin[i] = bin[i-1]*2LL%mod;
    scanf("%d%d%d",&n,&m,&k);
    repn(i,n) scanf("%lld",&a[i]);
    rep(i,m){
        int x,y; scanf("%d%d",&x,&y);
        ll forbid = (a[x]^a[y]);
        val.pb(forbid);
        edge.pb(mp(x,y));
    }
    SORT(val); ERASE(val);
    for(int i=0;i<edge.size();i++){
        int x = edge[i].fi, y = edge[i].sc;
        ll forbid = (a[x]^a[y]);
        int pos = POSL(val,forbid);
        assert(val[pos] == forbid);
        must_same[pos].pb(mp(x,y));
        atn[pos].pb(x); atn[pos].pb(y);
    }
    ll ret = 0;
    assert((1LL<<k) >= val.size());
    ret += ((1LL<<k)-val.size())%mod*bin[n]%mod;
    for(int i=0;i<val.size();i++){
        SORT(atn[i]); ERASE(atn[i]);
        kaede.init(atn[i].size()+10);
        int free = n;
        for(int j=0;j<must_same[i].size();j++){
            int a = must_same[i][j].fi, b = must_same[i][j].sc;
            int aa = a,bb = b;
            a = POSL(atn[i],a);
            b = POSL(atn[i],b);
            assert(atn[i][a] == aa && atn[i][b] == bb);
            if(!kaede.same(a,b)) free--;
            kaede.unite(a,b);
        }
        ret += bin[free];
        ret %= mod;
    }
    cout<<(ret%mod+mod)%mod<<endl;
}