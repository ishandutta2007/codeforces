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

const int N = 300100;
vi g[N];
int vis[N];
string s;
int c0,c1,c2;
vi comp;
void dfs(int v){
  vis[v] = 1;
  comp.pb(v);
  if(s[v] == '0')c0++;
  else if(s[v]=='1')c1++;
  else c2++;
  for(int to : g[v]){
    if(!vis[to])dfs(to);
  }

}

void solve(){
  int n,k;
  cin >> n >> k;
  rep(i,0,n)g[i].clear(),vis[i]=0;
  cin>>s;
  for(int i=k;i<n;i++){
    g[i-k].pb(i);
    g[i].pb(i-k);
  }

  bool ok =1;
  for(int i=0;i<n;i++){
    if(!vis[i]){
      c0 = c1 = c2 = 0; 
      comp.clear();
      dfs(i);
      for(int x : comp){
        if(s[x]=='?'){
          if(c0)s[x] = '0';
          else if(c1)s[x] = '1';
        }
      }
      if(c0 and c1){
        ok = 0;
        break;
      }
    }
  }
  c0 = c1 = 0;
  for(int i=0;i<k;i++){
    if(s[i] == '0')c0++;
    else if(s[i] == '1')c1++;
  }
 
  if(c0<=k/2 and c1<=k/2){

  }else ok = 0;

  if(ok)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  for(int i=0;i<=n + 10;i++){
    g[i].clear();
    vis[i]=0;
  }
  
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