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
  string t;
  cin>>t;
  int z=0,u=0;
  int n=t.size();
  string s = t+t;
  for(int i=0;i<n;i++){
    if(t[i]=='0')z++;
    else u++;
  }
  if(u==0 or z==0){
    cout<<t<<endl;
  }else{
    for(int i=0;i<n*2;i++){
      if(i%2==0)cout<<0;
      else cout<<1;
    }
    cout<<endl;
  }
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