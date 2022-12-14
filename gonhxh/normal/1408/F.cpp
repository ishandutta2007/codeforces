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


vector<pii> res;
int ID=0;
const int N = 15100;
int a[N];
map<pii,int> mp;
void join(int i,int j){
  if(a[i] > a[j])swap(i,j);
  if(mp.count(pii(a[i],a[j]))==0){
    mp[pii(a[i],a[j])] = ++ID;
  }
  int t = mp[pii(a[i],a[j])];
  a[i] = a[j] = t;
  res.pb(pii(i,j));
}

bool ruim(int x){
  for(int j=0;j<20;j++){
    if((1<<j)==x)return false;
  }
  return true; 
}

int32_t main(){
  fastio;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    a[i] = ++ID;
  }

  int k=0;
  while((1<<(k+1))<=n){
    k++;
  }
  int tam = (1<<k);

  rep(pt,1,k + 1){

    for(int i=1;i<=tam;i+=(1<<pt)){
      int jmp = (1<<(pt-1));
      for(int j=i;j<i + jmp;j++){
        join(j,j + jmp);
      //  cout <<"join "<<j<<" "<<j+jmp<<endl;
      }

    }
  }

  vi v;
  for(int i=tam+1;i<=n;i++){
    v.pb(i);
  }

  if(tam!=n){
  int sla = tam;
  while(ruim(sz(v))){
    join(sla,v[0]);
    v.pb(sla);
    
    if(!ruim(sz(v)))break;
    sla--;
  }

  k=0;
    n = sz(v);
  while((1<<(k+1))<=n){
    k++;
  }
  tam = (1<<k);
  rep(pt,1,k + 1){

    for(int i=1;i<=tam;i+=(1<<pt)){

      int jmp = (1<<(pt-1));
      for(int j=i;j<i + jmp;j++){
        join(v[j-1],v[j + jmp-1]);
     //   cout <<"join2 "<<v[j-1]<<" "<<v[j+jmp-1]<<endl;
      }

    }
  }

  }
  

  cout << sz(res) << endl;
  for(auto it : res){
    cout << it.ff<<" "<<it.ss<<endl;
  }


  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}