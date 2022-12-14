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
typedef vector<ll> vl;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll b,ll e,ll m){
  b%=m;
  ll ans = 1;
  for (; e; b = b * b % m, e /= 2)
      if (e & 1) ans = ans * b % m;
  return ans;
}

// debug:
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ 
  cerr << ' ' << H; 
  dbg_out(T...); 
}
#ifdef LOCAL
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl
#else
#define dbg(...) 
#endif
//

struct bipartite_match{ // 1 indice
  int n , m;
  vector<vi> g; vi vis , match;
  int ans=0;
  bipartite_match(int n , int m) : n(n) , m(m), vis(n+m+2) , match(n+m+2) , g(n+m+2){}
 
  void add(int x,int y){
    g[x].pb(y + n);
    g[y + n].pb(x);
  }
  bool dfs(int x){
    allin(w,g[x]){
      if(vis[w]) continue;
      vis[w] = true;
      if(match[w] == 0 || dfs(match[w])){
        match[w] = x, match[x] = w; 
        return true;
      }
    }
    return false;
  }
  int solve(){
     bool haspath;
    do{
      haspath = false;
      fill(all(vis) , false);
      for(int i = 1 ; i<= n + m; i ++){
        if(!match[i] && dfs(i)) haspath = 1 , ans ++ ;
      }
    } while(haspath);
    return ans;
  }

  // status: tested
  void dfs2(int v){
    vis[v] = 1;
    for(auto w : g[v]){
      if(vis[w])continue;
      if(v<=n){
          dfs2(w);
      }else{
        if(match[v]==w)dfs2(w);
      }
    }
  }
  vector<int> vertex_cover(){ // size == maximum matching
    solve();
    vector<int> res;
    fill(all(vis),false);
    for(int i=1;i<=n;i++){
      if(match[i]==0){
        dfs2(i);
      }
    }
    for(int i=1;i<=n;i++){
      if(match[i]!=0 and !vis[i]){
        res.pb(i);
      }
    }
    for(int i=n+1;i<=n+m;i++){
      if(vis[i]){
        res.pb(i);// change the index if needed
      }
    }
    assert(sz(res)==solve());
    return res;
  }
  // end of vertex cover


  int matchL(int x){return (match[x] ? match[x] - n : 0);}
  int matchR(int x){return match[x+n];}
};

const int N = 55;
ll X[N],Y[N];
ll dp[N][N];
int nxt[N][N];
bool vis[N][N];
int n,m,k;

ll solve(int w,int c){
  if(w == k+1){
    return 0;
  }
  ll &x = dp[w][c];
  if(vis[w][c])return x;
  vis[w][c]=1;
  x = -1e18;
  for(int j=0;j+c<=n;j++){
    ll score = max(0LL,X[w] - j * Y[w]);
    if(c + j <= w)continue;
    ll nv = score + solve(w + 1,c + j);
    if(x < nv){
      x = nv;
      nxt[w][c] = j;
    }
  }

  return x;
}

int32_t main(){
  fastio;
  ms(dp,-1);
  cin >> n >> m >> k;
  bipartite_match B(n,n);
  rep(i,0,m){
    int a,b;
    cin >> a >> b;
    B.add(a,b);
  }

  rep(i,1,k+1){
    cin >> X[i] >> Y[i];
  }

  vi vec = B.vertex_cover();
  int c = n - sz(vec);

  vi res;
  rep(wave,1,k+1){
    solve(wave,c);
    int j = nxt[wave][c];
    while(j--){ // precisa da dp na real...
      c++;
      int id = vec.back();
      vec.pop_back();
      if(id > n)res.pb(- (id - n));
      else res.pb(id);
    }
    res.pb(0);
  }

  cout << sz(res) << endl;
  for(auto it : res)cout<<it<<" ";
  cout<<endl;

  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}