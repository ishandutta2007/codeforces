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
const int L = 30;
//vi bit[30];
int bit[L + 10];
void solve(){
  int n;
  cin>>n;
  int zer=0;
  for(int i=0;i<30;i++)bit[i]=0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    int big=0;

    for(int j=L-1;j>=0;j--){
      big+=(1LL<<j);
      if(a[i]&(1LL<<j)){
        bit[j]++;
      }
    }


  }

  for(int j=L-1;j>=0;j--){

    if((bit[j])&1){
      int resto = n - bit[j];
      int pega = (n+1)/2;
      if(n%2==0){
        cout<<"WIN"<<endl;
        return;
      }
      pega = (bit[j] + 1)/2;
      if(pega&1){
        cout<<"WIN"<<endl;
        return;
      }
      if(bit[j] == 1){
        cout <<"WIN" << endl;
      }else{
        cout<<"LOSE" << endl;

      }
      return;
    }
  }

  cout << "DRAW" << endl;

}

int32_t main(){
  fastio;
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}