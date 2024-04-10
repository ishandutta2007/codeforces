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

const int M = 998244353;
const int N = 400100;
int l[N],r[N],a[N],b[N],suf[N];
int32_t main(){
  fastio;
  int n,m;
  cin>>n>>m;
  map<int,int> last;
  //mp;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    last[a[i]] = i;
  //  mp[a[i]];
  }
  for(int i=1;i<=m;i++){
    cin >> b[i];
  //  mp[b[i]];
  }
  suf[n+1] = 1e9;
  for(int i=n;i>=1;i--){
    suf[i] = min(suf[i+1],a[i]);
  }

  /*
  int K = 0;
  for(auto &it : mp){
    it.ss = ++K;
  }
  for(int i=1;i<=n;i++){
    cnt[mp[a[i]]]++;
  }
  for(int i=1;i<=K;i++){
    pre[i] = pre[i-1] + cnt[i];
  }*/

  if(n < m){
    cout << 0 << endl;
    return 0;
  }

  int ini = 1;
  for(int id=1;id<=m;id++){
    int R = last[b[id]];
    if(R==0 or R < ini){
      cout << 0 << endl;
      return 0;
    }
    int rr = R;
    while(id!=m and R+1<=n and suf[R+1]<b[id+1])R++;
    l[id] = ini;
    r[id] = rr;
    if(id == m)R = n;

    int mn = 1e9;
    for(int i=ini;i<=R;i++){
      if(mn > a[i])mn = a[i];
    }

    if(mn!=b[id]){
      cout << 0 << endl;
      return 0;
    }

    
    ini = R+1;
  }

  ll ans = 1;
  for(int i=2;i<=m;i++){
  
    ans = mod(ans * (r[i] - l[i] + 1),M);
  }
  cout << ans << endl;



  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}