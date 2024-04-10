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
#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left oooooopss
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
#define prl cerr<<"called: "<< __LINE__ << endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll b, ll e ,ll m) {
  b%=m;
  ll ans = 1;
  for (; e; b = b * b % m, e /= 2)
    if (e & 1) ans = ans * b % m;
  return mod(ans,m);
}



void solve(){
  int n,k;
  cin>>n>>k;
  string a,b;
  vi cnt1(30),cnt2(30);
  cin>>a;
  cin>>b;

  for(int i=0;i<n;i++){
    cnt1[a[i]-'a']++;
    cnt2[b[i]-'a']++;
  }
  int ok=1;
  for(int i=0;i<25;i++){
    if(cnt1[i]==cnt2[i])continue;
    if(cnt1[i]<cnt2[i] || (cnt1[i]-cnt2[i])%k!=0){
      ok=0;
      break;
    }
    int tira = (cnt1[i] - cnt2[i])/k;
    cnt1[i]-=tira*k;
    cnt1[i+1]+=tira*k;
  }

  for(int i=0;i<26;i++)if(cnt1[i]!=cnt2[i]){
    ok=0;
  }
  cout<<(ok ? "Yes" : "No")<<endl;

}

int32_t main(){
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve();
  }

  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}