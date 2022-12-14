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
#define int long long
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

const int N = 200100;
int a[N];
int cnt[N];

int32_t main(){
  fastio;
  int n;
  cin>>n;
  ll ans=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n,greater<int>());
  for(int i=0;i<n;i++){
    for(int j=0;j<20;j++){
      if(a[i]&(1<<j))cnt[j]++;
    }
  }


  for(int i=0;i<n;i++){
    ll tot=0;
    for(int j=19;j>=0;j--){
      if(cnt[j]){
        cnt[j]--;
        tot+=(1LL<<j);
      }
    }
    ans+=tot*tot;
  }
  cout << ans << endl;


/*
  for(int i=0;i<n;i++){

    for(int j = 19;j>=0;j--){
      if(a[i]&(1<<j)){
        S[j].erase(pii(a[i],i));
        continue;
      }
      if(S[j].empty())continue;
      pii cur = *S[j].begin();
      S[j].erase(cur);
      int x = a[i];
      int y = a[cur.ss];
      for(int j=0;j<20;j++){
        if(y&(1<<j)){
          S[j].erase(pii(a[cur.ss],j));
        }
      }
      a[i] = (x|y);
      a[cur.ss] = (x&y);
    }


  }
  */


  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}