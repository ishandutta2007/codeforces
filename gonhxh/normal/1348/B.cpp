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

const int N = 150;
int a[N];
int b[N*N];
  int n,k;
int ok(){
  int sum=0;

  for(int i=1;i<=k;i++){
    sum+=b[i];
  }
  int s2=sum;
  int tam = n;
  for(int i=k+1;i<=tam;i++){
    s2-=a[i-k];
    s2+=a[i];
    if(s2!=sum)return false;
  }
  return true;
}

void solve(){

  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  if(ok()){
    cout<<n<<endl;
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return;
  }
  int tam=0;
  set<int> S;
  for(int i=1;i<=n;i++){
    S.insert(a[i]);
  }
  if(S.size() > k){
    cout<<-1<<endl;
    return;
  }
  for(int i=1;i<=n;i++){
    if(S.size()==k)break;
    S.insert(i);
  }
  vector<int> v;
  for(auto it : S)v.pb(it);
  for(int i=1;i<=n*k;i++){
    b[i] = v[i%v.size()];
  }
  tam = n*k;
  cout << tam << endl;
  for(int i=1;i<=tam;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;

}

int32_t main(){
  fastio;
  int t;
  cin>>t;
  while(t--)solve();
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}