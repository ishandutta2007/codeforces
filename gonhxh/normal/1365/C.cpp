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
//#define int long long
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

const int N = 200100;
int a[N],b[N],pos1[N],pos2[N];
int cic[2*N];

int32_t main(){
  fastio;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    pos1[a[i]] =i;
  }
  for(int i=1;i<=n;i++){
    cin >> b[i];
   // pos2[b[i]] = i;
    if(i > pos1[b[i]]){
      cic[pos1[b[i]] - 1 + n - i + 1]++;
    }else{
      cic[pos1[b[i]] - i]++;
    }
  }

  int res=0;
  for(int i=0;i<2*N;i++){
    res = max(res,cic[i]);
  }
  cout << res << endl;

  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}