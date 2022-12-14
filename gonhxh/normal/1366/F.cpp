#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
//#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define M   1000000007 // 1e9 + 7
#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
typedef long long ll;
typedef pair<int,int> pii;
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
const int N = 2020;

struct edge{
 int a,b,c;
 edge(){}
 edge(int A,int B,int C){
  a = A;
  b= B;
  c=  C;
 }
}e[N];

ll dist[2][N];

struct Line {
  mutable ll k, m, p,id;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = inf; return false; }
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m,int id) {
    auto z = insert({k, m, 0 , id}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.id;
  }
};


const int M = 1e9 + 7;
LineContainer L;
int m,q;

ll X[N];
int32_t main(){
  fastio;
  int n;
  cin >> n >> m >> q;
  for(int i=1;i<=m;i++){
    cin>>e[i].a>>e[i].b>>e[i].c;
    e[i].c*=-1;
  }
  for(int i=1;i<=n;i++){
    if(i==1)dist[0][i] = 0;
    else dist[0][i] = 1e18;
  }
  int last = 0;

  ll res = 0;
  for(int i=1;i<=m;i++){

    int cur=last^1;
    for(int i=1;i<=n;i++)dist[cur][i] = 1e18;

    for(int id=1;id<=m;id++){
      int a=e[id].a,b=e[id].b,c= e[id].c;
    
      if(dist[cur][a] > dist[last][b] + c){
        dist[cur][a] = dist[last][b] + c;
      }
      if(dist[cur][b]> dist[last][a] + c){
        dist[cur][b] = dist[last][a] + c;
      }

    }

    ll mx = 0;
    for(int i=1;i<=n;i++){
      mx = max(mx, - dist[cur][i]);
    }
    res = mod(res + mx,M);
    last= cur;
  } 

  for(int i=1;i<=m;i++){
    int a= e[i].a;
    int b = e[i].b;
    e[i].c*=-1;
    int d = -min(dist[last][a],dist[last][b]);

    L.add( e[i].c , d , i);
    X[i] = d;
    
  }
  

  int cur = m + 1;
  while(cur <= q){
    ll l = cur,r = q;
    ll ans = cur;
    int id = L.query(l - m);
    while(l<=r){
      int mid = (l+r)/2;
      if(L.query(mid - m) == id){
        l = mid+1;
        ans = mid;
      }else r= mid-1;
    }

    // add (l,r)
    ll x = X[id];
    ll k = e[id].c;
    l = cur;

    r = ans;
    res = mod(res + 1LL*(r - l + 1)*mod(x,M),M);

    ll add1 = (r+l)*(r-l+1) /2;
    add1%=M;
    add1 = (add1*k)%M;
    ll add2 = (m *(r-l+1))%M;
    add2 = mod(add2*k,M);
    res = mod(res + add1 - add2,M); 

    cur = ans + 1;
  }

  cout << res << endl;
  
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}