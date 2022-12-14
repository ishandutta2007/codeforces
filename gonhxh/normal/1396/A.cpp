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
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
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

const int N = 100100;

int a[N];


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int x[N],y[N];
int32_t main(){
  fastio;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    int g;
    find_any_solution(n,n-1,a[i],x[i],y[i],g);
  }
  if(n == 1){
    for(int i=1;i<=3;i++){
      cout << 1<<" "<<1 << endl;
      cout << -a[1] << endl;
      a[1] = 0;
    }
    return 0;
  }

  cout << 1 <<" "<< n << endl;
  for(int i=1;i<=n;i++){
    cout << -1ll*x[i]*n <<" ";
    if(i==1)a[i] += (-1ll*x[i]*n);
  }
  cout << endl;
  cout << 2<<" "<<n << endl;
  for(int i=2;i<=n;i++){
    cout << -1ll*y[i]*(n-1)<<" ";
    assert(1ll*x[i]*n + y[i]*(n-1) == a[i]);
    
  }
  cout << endl;
  cout << 1 <<" "<<1<<endl;
  cout << -a[1]<<endl;

  return 0;
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}