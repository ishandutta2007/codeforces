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


int cnt[250*250];

void solve(){
  int a,b,q;
  cin>>a>>b>>q;
  for(int i=0;i<=a*b;i++)cnt[i]=0;
  for(int i=1;i<=a*b;i++){
    if((i%a)%b != (i%b)%a)cnt[i]++;
    if(i) cnt[i]+=cnt[i-1];
  }

  auto get = [&](int x){
    if(x==0)return 0LL;
    int qtd = x/(a*b);
    int r = x%(a*b);  
    int res = qtd*cnt[a*b] + cnt[r];
    return res; 
  };

  while(q--){
    int l,r;
    cin>>l>>r;
    int res = get(r) - get(l-1);
    cout<< res << " ";
  }
  cout<<endl;

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