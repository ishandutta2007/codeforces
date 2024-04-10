#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   bool same(int x,int y){
       return find(x)==find(y);
   }
   int size(int x){
       return -par[find(x)];
   }
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    UnionFind uf(n);
    vector<ll> x(m),y(m),z(m);
    rep(i,m){
        cin>>x[i]>>y[i]>>z[i];
        --x[i];--y[i];
    }
    vector<int> ord(m);
    rep(i,m)ord[i]=i;
    sort(ord.begin(),ord.end(),[&](int l, int r){
        return z[l]<z[r];
    });
    ll sum = 0;
    ll ans = longinf;
    for(auto i: ord){
        if(z[i]>k)break;
        uf.unite(x[i], y[i]);
        if(uf.size(0)==n){
            ans = min(ans, k-z[i]);
        }
    }
    bool first = true;
    for(auto i: ord){
        if(z[i]<=k)continue;
        if(first && uf.size(0)==n){
            ans = min(ans, z[i]-k);
            break;
        }
        first = false;
        if(uf.unite(x[i],y[i]))sum+=z[i]-k;
        if(uf.size(0)==n){
            ans=min(ans, sum);
            break;
        }
    }
    cout<<ans<<endl;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}