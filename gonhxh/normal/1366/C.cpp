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
//#define int long long
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

const int N = 35;
int a[N][N];

int vis[N][N];
void solve(){
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> a[i][j];
      vis[i][j]=0;
    }
  }

  int res=0;
  int mx = n + m - 2;
  for(int dist = 0;dist<=mx;dist++){

    vector<pii> v1,v2;
    int ok=1;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        int d = i + j - 2;
        
        if(d!=dist and d!=mx - dist)continue;
        if(vis[i][j]){
          ok =0;
          break;
        }

        vis[i][j] = 1;
        if(d == dist)v1.pb(pii(i,j));
        else v2.pb(pii(i,j));

      }
    }

    if(!ok)continue;

    pii p1=pii(0,0),p2=pii(0,0);
    for(auto it : v1){
      if(a[it.ff][it.ss] == 1)p1.ff++;
      else p1.ss++;
    }
    for(auto it : v2){
      if(a[it.ff][it.ss] == 1)p2.ff++;
      else p2.ss++;
    }

    if(p1==pii(0,0) or p2==pii(0,0))continue;
    int op1 = p1.ss + p2.ss;
    int op2 = p1.ff + p2.ff;
    res+=min(op1,op2);

  }

  cout << res << endl;

}

int32_t main(){
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}