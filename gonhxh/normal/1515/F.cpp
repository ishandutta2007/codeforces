#include <bits/stdc++.h>
#define ld long double
//#define endl "\n"
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
//#define left oooooopss
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll b,ll e,ll m){
  b%=m;
  ll ans = 1;
  for (; e; b = b * b % m, e /= 2)
      if (e & 1) ans = ans * b % m;
  return ans;
}
struct dsu{
  vi p , ps;
  dsu(int n){
    p = vi(n+1),ps = vi(n+1,1);
    rep(i,0,n+1) p[i] = i;
  }
  int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
  bool join(int x , int y){
    x = find(x) , y = find(y);
    if(x == y) return 0;
    if(ps[x] > ps[y]) swap(x,y);
    p[x] = y, ps[y] += ps[x];
    return 1;
  }

};

const int N = 300100;
ll a[N];
vector<pii> g[N];
int deg[N];
int vis[N];

int p[N];
int pai[N];

int f(int x){
  return p[x] = (p[x]==x?x:f(p[x]));
}
void join(int A,int B){
  A=f(A),B=f(B);
  p[A] = B;
  a[B]+=a[A];
}
pii e[N];
int32_t main(){
  fastio;
  int n,m;ll x;
  cin >> n >> m >> x;
  ll tot=0;
  rep(i,1,n+1){
    cin >> a[i];
    tot+=a[i];
    p[i]=i;
  }
  if(tot < 1ll * (n-1) * x){
    cout << "NO\n";return 0;
  }
  dsu D(n);
  vi ed;
  rep(i,0,m){
    int a,b;cin >> a >> b;
    e[i] = pii(a,b);
    if(D.join(a,b)){
      g[a].pb(pii(b,i+1));
      g[b].pb(pii(a,i+1));
      deg[a]++;
      deg[b]++;
    }
  }
  vi order;
  rep(i,1,n+1)if(deg[i]==1)order.pb(i);
  cout<<"YES\n";
  for(int i=0;i < sz(order);i++){
    int v = order[i];
    vis[v] = 1;
    for(auto itt : g[v])if(!vis[itt.ff]){
      int it = itt.ff;
      int j = f(v);
      // junta com o pai:
      if(a[j] >= x){
        a[j]-=x;
        join(j,it);
        cout << itt.ss << endl;
      }else ed.pb(itt.ss);

      deg[it]--;
      if(deg[it] == 1)order.pb(it);
    }
  }
  reverse(all(ed));
  for(auto it : ed){
    cout << it<<endl;
    int A = f(e[it-1].ff),B=f(e[it-1].ss);
    assert(a[A] + a[B] - x>=0);
    a[A]-=x;
    join(A,B);
  }

  
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}