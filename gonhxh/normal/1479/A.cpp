#include <bits/stdc++.h>
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

int a[100100];

int ask(int x){
  if(a[x])return a[x];
  cout <<"? "<<x<<endl;
  int r;
  cin >> r;
  a[x] = r;
  return r;
}

void print(int k){
  cout<<"! "<<k<<endl;
  exit(0);
}

int n;
bool ok(int x){
  int v = ask(x);
  int v1 = ask(x-1);
  int v2 = ask(x+1);
  return v<min(v1,v2);
}

int32_t main(){
  cin >> n;
  a[0] = a[n+1] = 1e9;
  int l = 1,r = n;
  while(l<=r){
    if(ok(l))print(l);
    if(ok(r))print(r);

    if(ask(l) > ask(l-1)){
        l++;
    }
    if(ask(r) > ask(r+1)){
        r--;
    }

    int m = (l+r)/2;
    if(ok(m))print(m);
    
    if(l+2>=r){
        for(int i=l;i<=r;i++){
            if(ok(i))print(i);
        }
        assert(false);
    }


    if(ask(m) < ask(m+1)){
        r = m;
    }else{
        l = m;
    }

 
  }
  
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}