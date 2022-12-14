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
#define left oooooopss
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
#define prl cerr<<"called: "<< __LINE__ << endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll b, ll e ,ll m) {
  b%=m;
  ll ans = 1;
  for (; e; b = b * b % m, e /= 2)
    if (e & 1) ans = ans * b % m;
  return mod(ans,m);
}



map<pii,int> mp[3];

int ask(int i,int j,int op){
  if(mp[op].count(pii(i,j)))return mp[op][pii(i,j)];
  if(op==0)cout<<"AND ";
  else if(op==1)cout<<"XOR ";
  else cout<<"OR ";
  cout << i<<" "<<j<<endl;
  cout.flush();
  int c;
  cin>>c;
  mp[op][pii(i,j)] = mp[op][pii(j,i)] = c;
  return c;
}


int cnt[100];
int a[(1<<16) + 100];
int32_t main(){
  fastio;
  int n;
  cin >> n;
  int h=0;
  while((1<<h)!=n)h++;

  for(int i=2;i<=3;i++){
    int o = ask(1,i,2);
    for(int j=0;j<h;j++){
      if(o&(1<<j))cnt[j]++;
    }
  }

  a[1]=0;
  int r = ask(2,3,0);
  int r2 = ask(1,2,0);
  for(int j=0;j<h;j++){
    if(cnt[j] != 2)continue;
    // ou eu ou todos:
    if(r&(1<<j)){
      // todos ainda podem ter:
      if(r2&(1<<j)){  // ok
        a[1]|=(1<<j);
      }
    }else{ // OK
      a[1]|=(1<<j);//yo tengo
    }
  }

  for(int i=2;i<=2;i++){
    int o = ask(1,i,2);
    int A = ask(1,i,0);
    int xo = o - A;
    a[i] = a[1]^xo;
  }
  for(int i=3;i<=3;i++){
    int o = ask(1,i,2);
    int A = ask(1,i,0);
    int xo = o - A;
    a[i] = a[1]^xo;
  }

  for(int i=4;i<=n;i++){
    int xo = ask(1,i,1);
    a[i] = xo^a[1];
  }
  cout <<"! ";
  for(int i=1;i<=n;i++){
    cout << a[i]<<" ";
  }
  cout << endl;
  cout.flush();


  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}