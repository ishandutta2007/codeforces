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

const int MX = 1e7 + 10;
int divi[MX];
bool mark[MX];
void crivo(){
  for(int i=2;i<MX;i++){
    if(!mark[i]){
      divi[i] = i;
      for(int j=i+i;j<MX;j+=i){
        divi[j] = i;
        mark[j] = 1;
      }
    }
  }
}

void brute(){

  for(int i=2;i<300;i++){
    int x = i;
    pii mx(-1,-1);
    for(int d1 = 2;d1<=i;d1++){
      if(i%d1!=0)continue;
      for(int d2=2;d2<=i;d2++){
        if(i%d2!=0)continue;
        if(gcd(i,d1+d2)==1){
          mx = max(mx,pii(d1,d2));
        }
      }
    }
    cout << i<<" "<<mx.ff<<" "<<mx.ss<<endl;
  }


}


const int N = 500100;
int a[N];
int d1[N],d2[N];


int32_t main(){
  fastio;
  crivo();
 // brute();
 // return 0;  

  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }



  for(int i=1;i<=n;i++){
      if(!mark[a[i]]){
        d1[i] = d2[i] = -1;
        continue;
      }
      int x = a[i];

      vi pr;
      
      int a1=1,a2=1;
      while(x>1){
        int p =divi[x];
        pr.pb(p);
        int v = 1;
        while(x%p==0){
          x/=p;
          v*=p;
        }
        if(a1==1)a1*=v;
        else if(a2==1)a2*=v;
        else a1*=v;
      }

      if(a1==1 or a2==1){
        d1[i] = d2[i] = -1;
      }else{
        d1[i] = a1;
        d2[i] = a2;
        assert(gcd(a1+a2,a[i])==1);
      }

  }
  for(int i=1;i<=n;i++)cout<<d1[i]<<" ";
    cout << endl;
  for(int i=1;i<=n;i++)cout << d2[i]<<" ";
    cout << endl;

  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}