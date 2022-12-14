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
//#define int long long  
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
//#define left oooooopss
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll b,ll e,ll m){
  b%=m;
  ll ans = 1;
  for (; e; b = b * b % m, e /= 2)
      if (e & 1) ans = ans * b % m;
  return ans;
}

const int N = 300100;
vi vec[N];
int a[N];
int C[N];

int32_t main(){
  fastio;
  int n,q;
  cin>>n>>q;
  rep(i,1,n+1){
    cin>>a[i];
    vec[a[i]].pb(i);
  }
  auto cnt = [&](int x,int l,int r){
    return upper_bound(all(vec[x]),r) - upper_bound(all(vec[x]),l-1);
  };
  while(q--){
    int l,r;
    cin>>l>>r;
    int mx = 0;
    int tam = (r-l+1);
    if(tam <= 100){
      rep(i,l,r+1){
        C[a[i]]++;
      }
      rep(i,l,r+1){
        if(C[a[i]] > mx)mx=C[a[i]];
        C[a[i]]--;
      }

    }else{
      
      rep(i,0,35){
        int v = a[l + mod(rng(),tam)];
        int c = cnt(v,l,r);
        if(c > mx){
          mx = c;
        }
      }

    }
       
    if(mx > ((tam+1)/2)){
      cout << mx - (tam - mx) << endl;
    }else cout<<1<<endl;


  }
  
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}