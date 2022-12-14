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
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
//#define right sefudermano
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
char a[N],b[N];
  vi res;
char c[N];
char d[N];

int n;

void go(int x){
  return;
  for(int i=1;i<=x;i++){
    c[i] = (d[x-i+1]=='0' ? '1' : '0');
 
  }
  for(int i=1;i<=x;i++){
    d[i] = c[i];
  }


/*
  for(int i=1;i<=n;i++){
    cout << d[i];
  }
  cout << endl;
  */
}


void go(int l,int r,int id,int inv ,int cnt){
  if(id<0)return;
  if(l>r)return;
  int pos = (inv ? r-id+1 : l+id-1);
  
  char cur = a[pos];
  if(cnt)cur = (cur=='0' ? '1' : '0');
  
  if(id == 1){
    if(cur == b[id])return;
    res.pb(1);
    go(1);
    return;
  }  

  if(cur == b[id]){
    if(id == 1)return;
    if(!inv)go(l,r-1,id-1,inv,cnt);
    else go(l+1,r,id-1,inv,cnt);
    return;
  }
  // invert a[1] then invert all
  char cur2;
  if(inv)cur2 = a[r];
  else cur2= a[l];

  if(cnt)cur2 = (cur2 == '0' ? '1' : '0');
//  cout << l<<" "<<r<<" "<<id<<" "<<cur2<<endl;
  if(cur2 == b[id]){

    res.pb(1);
    go(1);
    if(inv)a[r] = (a[r] == '0' ? '1' : '0');
    else a[l] = (a[l]=='0' ? '1' : '0');
  }

  res.pb(id);
  go(id);
  inv^=1;
  cnt^=1;

  if(inv){
    l++;
  }else r--;



  go(l,r,id-1,inv,cnt);
}

void solve(){

  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    d[i] = a[i];
  }
  for(int i=1;i<=n;i++){
    cin >> b[i];
  }

  res.clear();
  go(1,n,n,0,0);


  cout << sz(res)<<" ";
  for(int x : res){
    cout << x<<" ";
  }
  cout << endl;
}

int32_t main(){
  fastio;
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}