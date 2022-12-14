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
//#define left oooooopss
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll b,ll e,ll m){
  b%=m;
  ll ans = 1;
  for (; e; b = b * b % m, e /= 2)
      if (e & 1) ans = ans * b % m;
  return ans;
}


const int N = 100100;
const int sq = 300;
int a[N];
int f[N];


int sum[N];
int mn[N];
int lazy[N];

int n,q;

void updF(int i){
  int X = lazy[i];
  lazy[i] = 0;
  int lim = min(n,(i+1)*sq);
  int ini = i*sq;
  mn[i] = 1e9;
  for(int j=ini;j<lim;j++){
      a[j] = max(0,a[j] - X);
      if(a[j] < ini){
        f[j] = j;
      }else f[j] = f[a[j]];

      if(mn[i] > j - a[j])
        mn[i] = j - a[j];
  }
}

void sumX(int i,int x){
    lazy[i]+=x;
    if(lazy[i] > N)lazy[i] = N;
  if(mn[i] > sq){
    return;
  }
  updF(i);
}

int getint(){
  int x=0;
  char c = '*';
  while(c<'0' || c>'9'){
    c = getchar();
  }
  while(c>='0' and c<='9'){
    x = 10*x + (c- '0');
    c = getchar();
  }
  return x;
}

int block[N];

void write(int x){
  if(x<10)return (void)putchar(x+'0');
  write(x/10);
  putchar(x%10+'0');
}


int32_t main(){
  //fastio;
  n = getint();
  q = getint();
  //cin >> n >> q;
  for(int i=1;i<n;i++){
   // cin >> a[i];
    a[i] = getint();
    a[i]--;
  }
  rep(i,0,n)block[i] = i/sq;

  for(int i=0;i*sq<n;i++){
    updF(i);
  }

  while(q--){
    int t;
    t = getint();
    if(t==1){
      int l = getint(),r=getint(),x=getint();

      --l;--r;
      int id=-1;
      for(int i=l;i<=r;){
        if(i%sq==0 and i+sq-1<=r){
          sumX(i/sq,x);
          i+=sq;
        }else{
          a[i] = max(a[i] - x,0);
          id = i;
          i++;
        }
      
      }
      
      updF(block[l]);
      if(block[l]!=block[r])
        updF(block[r]);
      
    }else{
      int u = getint(),v = getint();

      --u;--v;

      while(u!=v){
        
        if(u < v){
          int c = u;u=v,v=c;
        }

        if(block[u]!=block[v]){

          u = f[u];

          u = max(0,a[u] - lazy[block[u]]);

        }else{

          if(f[u] == f[v]){

            while(u!=v){
              if(u < v){int c = u;u=v,v=c;}
              u = max(0,a[u] - lazy[block[u]]);
            }

            break;
          }else{
            u = f[u],v = f[v];
            
            u = max(0,a[u] - lazy[block[u]]);
            v = max(0,a[v] - lazy[block[v]]);

          }

        }

      }


      write(u + 1);
      putchar('\n');
    }
  }

  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}