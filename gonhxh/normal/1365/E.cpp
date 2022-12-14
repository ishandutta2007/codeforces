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

const int N = 505,MAXL = 60;
int n;


ll solve(int b,ll msk,int k,vector<int> cur,vi bad,int out){
  if(b<0){
    return msk;
  }

  int qtd=0;
  for(ll x : cur){
    if(x&(1LL<<b))qtd++;
  }
  int qtd2=0;
  for(ll x : bad){
    if(x&(1LL<<b))qtd2++;
  }

  if(qtd>=k-2){
    vi novo;
    msk|=(1LL<<b);
    for(ll x : cur){
      if(x&msk){
        novo.pb(x);
      }else{
        bad.pb(x);
      }
    }



    cur.clear();
    return solve(b-1,msk,k,novo,bad,out);
  }else if(qtd+qtd2>=k-2 and k-2-qtd + out <= 2){
    msk|=(1LL<<b); 
    vi novo;
    
    for(ll x : bad){
      if(x&(1LL<<b)){
        novo.pb(x);
      }
    }

    for(ll x : cur){
      if(x&msk){
        novo.pb(x);
      }else{
        bad.pb(x);
      }
    }
    out+= k-2-qtd;

    return solve(b-1,msk,k,novo,bad,out);
  }else return solve(b-1,msk,k,cur,bad,out);

}


ll a[N];
int32_t main(){
  fastio;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  sort(a+1,a+1+n,greater<int>());
  ll res=0;
  vector<int> vv;
  for(int i=1;i<=n;i++)vv.pb(a[i]);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        res = max(res,(a[i]|a[j]|a[k]));
      }
    }
  }  


  /*

  for(int k=3;k<=n;k++){
    vi v;
    vi v2;
    for(int i=1;i<=n;i++)v.pb(a[i]);

    res = max(res,solve(MAXL-1,0,k,v,v2,0));
  }
  */
  cout << res << endl;

  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}