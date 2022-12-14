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
//#define M   1000000007 // 1e9 + 7
#define int long long
using namespace std;
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
int mark[N];

void crivo(){
  mark[1] = 1;
  for(int i=2;i<N;i++){
    if(mark[i])continue;
    mark[i] = i;
      for(int j=2*i;j<N;j+=i){
          if(mark[j]==0){
            mark[j] = i;
          }     
      }
  }
 
}

vector<int> pot[N];

int32_t main(){
 fastio;
 int n;
 cin>>n;
 vector<int> v(n);
crivo();
 for(int i=0;i<n;i++){
    cin>>v[i];
    int x = v[i];

    while(mark[x] > 1){
      int p = mark[x];
      int k =0;
      while(mark[x]==p){
        x/=p;
       
        k++;
      }
      
      pot[p].pb(k);
    }

 }
 int g = 1;
 for(int i=2;i<N;i++){
    if(pot[i].size()){
      
      for(int j=0;j<2;j++){
        if(pot[i].size()==n)break;
        pot[i].pb(0);
      }
      sort(pot[i].begin(),pot[i].end());

      int k = pot[i][1];
      int p = 1;
      while(k--){
        p*=i;
      }
      g*=p;

    }
 }
 cout << g << endl;

 
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}