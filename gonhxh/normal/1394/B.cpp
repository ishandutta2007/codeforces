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
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
typedef long long ll;
typedef pair<ll,ll> pll;
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

const int N = 2e5 + 10;
vector<pii> g[N];

vi c[N];
int rev[N];



int adj[100 ][ 100 ];

vector<pii> gr[N];

int used[N];

int k;
int have = 0;

int go(int id){
  if(id == k + 1){
   /* 
    cout<<"NOVO"<<endl;
    for(int i=1;i<=k;i++){
      for(int j=0;j<i;j++)if(used[(i-1)*k + j]){
        cout << "("<<i<<","<<j<<")\n";
      }

    }
*/
    return 1;
  }
  int res=0;
  for(int i=0;i<id;i++){
    // c[id] == i + 1:
    bool ok = 1;
    
    for(int j=0;j<=k*k;j++){

      if(adj[(id-1)*k + i][j] and (used[j] or j==(id-1)*k + i)){
        ok =0;
        break;
      }
    }

    if(ok){
      used[(id-1)*k + i] = 1;
      res+=go(id+1);
      used[(id-1)*k + i] = 0;
    }

  }

  return res;
}





int32_t main(){
  fastio;
  int n,m;
  cin >> n >> m >> k;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    g[a].pb(pii(b,c));

    rev[b]++;
  }

  for(int i=1;i<=n;i++){
    sort(all(g[i]),[&](pii a,pii b){
      return a.ss < b.ss;
    });

    c[sz(g[i])].pb(i);
    if(rev[i] == 0){
      cout << 0 << endl;
      return 0;
    }

    for(int j=0;j<sz(g[i]);j++){
      int to = g[i][j].ff;
      gr[to].pb(pii(sz(g[i]),j));
    }


  }


 // for(int i=0;i<k*k;i++)if(ok[i])pai[i] = i,comp++;

  for(int i=1;i<=n;i++){

    set<pii> here;
    map<pii,int> mp;
    for(auto it : gr[i]){
      here.insert(it);
      mp[it]++;
    }
    for(auto it : mp){
      if(it.ss > 1){
        pii a = it.ff;
        adj[(a.ff-1)*k + a.ss][(a.ff-1)*k + a.ss] = 1;
      }
    }

    for(auto it : here){
      for(auto it2 : here){
        if(it == it2)continue;

        int a = (it.ff-1)*k + it.ss;
        int b = (it2.ff-1)*k + it2.ss; 

        adj[a][b] = adj[b][a] = 1;
        // a-> nao b

      }
    }


  }



  int res = go(1);

  cout << res << endl;
  return 0;
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}