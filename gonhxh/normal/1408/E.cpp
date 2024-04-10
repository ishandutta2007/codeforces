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

const int N = 200100;
vector<int> A[N];
int a[N],b[N];


struct dsu{
  vi p , ps;
  dsu(int n){
    p = vi(n+1),ps = vi(n+1,1);
    rep(i,0,n+1) p[i] = i;
  }
  int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
  bool join(int x , int y){
    x = find(x) , y = find(y);
    if(x == y) return 0;
    if(ps[x] > ps[y]) swap(x,y);
    p[x] = y, ps[y] += ps[x];
    return 1;
  }
};  
int s[N];
typedef array<ll,3> ar;
int32_t main(){
  fastio;
  int m,n;
  cin>>m>>n;
  for(int i=1;i<=m;i++){
    cin >> a[i];
  }
  for(int i=1;i<=n;i++){
    cin >> b[i];
  }
  ll tot=0;
  vector<ar> vec;
  for(int i=1;i<=m;i++){
    cin >> s[i];
    A[i].resize(s[i]);
    rep(j,0,s[i]){
      cin >> A[i][j];
      vec.pb({n + i,A[i][j],b[A[i][j]] + a[i]});
      tot+=(b[A[i][j]]+a[i]);
    }
    
  }

  sort(all(vec),[&](ar i,ar j){
    return i[2] > j[2];
  });

  dsu D(n + m + 100);

  for(auto it : vec){
    if(D.find(it[0])!=D.find(it[1])){
      D.join(it[0],it[1]);
      tot-=it[2];
    }
  }
  cout << tot << endl;
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}