#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define Unique(v) sort(all(v));v.erase(unique(all(v)),v.end());
#define sz(v) ((int)v.size())
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
#define db(x) cerr <<#x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
#define prl cerr<<"called: "<< __LINE__ << endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

template<class T>
struct BIT{
 int n;
 int MAX;
 vector<T> bit;
 BIT(){}
 BIT(int _n){
   n = _n;
   MAX = n +2;
   bit.resize(n+10,0);
 }
 
 T query(int x){
   T r=0;
   while(x>0){
     r+=bit[x];
     x-=(x&-x);
   }
   return r;
 }
 
 T query(int l,int r){
   return query(r) - query(l-1);
 }
 
 void update(int x,T val){
   while(x<MAX){
     bit[x]+=val;
     x+=(x&-x);
   }
 }
    
};

const int N = 200100;
vi g[N];
int tin[N],tout[N];
int t=0;
int H[N];
void dfs(int v,int p = -1){
  tin[v]=++t;
  for(int to : g[v])if(to!=p){
    H[to] = H[v] + 1;
    dfs(to,v);
  }
  tout[v]=t;
}
int A[N];
int32_t main(){
  fastio;
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin >> A[i];
  for(int i=1;i<n;i++){
    int a,b;cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  BIT<ll> T[2];
  T[0] = T[1] = BIT<ll>(n + 1);
  dfs(1);

  while(m--){
    int op;
    cin>>op;
    if(op == 1){
      int x,v;
      cin>>x>>v;
      T[H[x]&1].update(tin[x],v);
      T[H[x]&1].update(tout[x]+1,-v);      
    }else{
      int v;
      cin >> v;
      
      int res = A[v] + T[H[v]&1].query(tin[v])
                - T[~H[v]&1].query(tin[v]);
      cout << res << endl;
    }
  }
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}