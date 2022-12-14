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
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define M   1000000007 // 1e9 + 7
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
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


void solve(){
  int x,y;
  cin>>x>>y;
  x = abs(x);
  y = abs(y);
  int mn = min(x,y);
  int a,b;
  cin>>a>>b;
  int res=0;
  if(b<=2*a){
    res+=mn*b;
    x-=mn;
    y-=mn;
  }
  res+=a*x + a*y;
  cout<< res << endl;
}
// long long ? 
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