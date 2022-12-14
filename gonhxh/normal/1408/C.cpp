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
#define left sefude
#define db(x) cerr <<#x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
#define prl cerr<<"called: "<< __LINE__ << endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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

int n,l;

const int N = 100100;
int a[N];

double ok(){
  int p1 = 0,p2 = n + 1;
  a[n + 1] = l;
  a[0] = 0;

  double t0 = 0,t1 = 0;
  double v1 = 1,v2 = 1;
  while(true){
    if(p1 + 1 >= p2){
      double dist = a[p2] - a[p1];
      if(t0 > t1){
        dist-=v2 * (t0 - t1);
        t1 = t0;
      }else if(t1 > t0){
        dist-=v1 * (t1 - t0);
        t0 = t1;
      }

      return t0 + (dist)/(v1 + v2);
    }
    double d1 = a[p1+1] - a[p1];
    double T1 = t0 + d1/v1;
    double d2 = a[p2] - a[p2-1];
    double T2 = t1 + d2/v2;
    if(T1 <= T2){
      t0 = T1;
      v1++;
      p1++;
    }else{
      t1 = T2;
      v2++;
      p2--;
    }
  }

}

void solve(){
  cin >> n >> l;
  for(int i=1;i<=n;i++)cin >> a[i];
  double ans;
  /*
  double L = 0 ,R = 1e9;
  rep(iter,0,60){
    double mid = (L+R)/2.0;
    if(ok(mid)){
      ans = mid;
      R = mid;
    }else L = mid;
  }*/
  cout << setprecision(10) << fixed;
  ans = ok();
  cout << ans << endl;
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