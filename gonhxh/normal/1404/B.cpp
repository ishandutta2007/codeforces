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
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define Unique(v) sort(all(v));v.erase(unique(all(v)),v.end());
#define sz(v) (int)v.size()
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
#define prl cerr<<"called: "<< __LINE__<<endl;
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

struct Tree{
  vector<vi> g;
  int N;
  Tree(){}
  Tree(int n){
    N = n;
    g.resize(N+1,vi());
  }
  void addEdge(int a,int b){
    g[a].pb(b);
    g[b].pb(a);
  }

  void dfs(int v,int p,vi& d){
    if(p==-1)d[v]=0;
    for(int to : g[v])if(to!=p){
      d[to] = d[v] + 1;
      dfs(to,v,d);
    }
  }

  int dist(int a,int b){
    vi d( N + 1,0);
    dfs(a,-1,d);
    return d[b];
  }

  int diametro(){
    vi d[2];
    int root = 1;
    int ponta[2]={0,0};// pontas do diametro
    rep(it,0,2){
      d[it].resize(N+1,0);
      dfs(root,-1,d[it]);
      int best=-1,id=0;
      for(int i=1;i<=N;i++)if(d[it][i] > best){
        best = d[it][i];
        id = i;
      }
      root = id;
      ponta[it] = id;
    }
    dfs(ponta[0],-1,d[0]);dfs(ponta[1],-1,d[1]);
    // max(d[0][i],d[1][i]) == maior distancia pra alguma folha
    int diam=0;
    for(int i=1;i<=N;i++){
      diam = max(diam,max(d[0][i],d[1][i]));
    }
    return diam;
  }

};

int n,a,b,da,db;
void solve(){
  cin >> n >> a >> b >> da >> db;
  Tree tree(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    tree.addEdge(a,b);
  }
  int diam = tree.diametro();
  
  if(tree.dist(a,b) <= da){
    cout<<"Alice"<<endl;
    return;
  }  
  if(db > 2*da and diam > 2*da){
    cout <<"Bob" << endl;
  }else cout<<"Alice"<<endl;
}

int32_t main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}