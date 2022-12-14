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


struct node{
  ll suf;
  ll tot;
  node operator+(const node &o) const{  // exemplo de operador de merge
    node r;
    r.suf = max(o.suf,o.tot + suf);
    r.tot = o.tot + tot;
    return r;
  }
};
template <class T>
struct ST{
  vector<T> st; int n; 
  T ini; 
  ST(int n , T ini) : st(2*n , ini) , n(n) , ini(ini) {}
  void upd(int pos, T val){ // pos 0index
    for(st[pos += n] = val ; pos /= 2;)
      st[pos] = st[2*pos] + st[2*pos + 1];
  }
  T query(int x , int y){ // [x,y] , x, y -0index
    T ra = ini , rb = ini;
    ra.suf = -1e9;
    rb.suf = -1e9;
    for(x += n, y += n+1 ; x < y ; x/=2 , y/=2){
      if(x&1) ra = ra + st[x++];
      if(y&1) rb = st[--y] + rb;
    }
    return ra + rb;
  }
};

node make(int x){
  node r;
  r.tot = x;
  r.suf = x;
  return r;
}


  int n,k;
int tenta(vector<int> a){

  for(int i=0;i<n;){
    if(a[i]==k){
      int cur = 0;
      i++;
      while(i<n and a[i]!=k){
        if(a[i]<k)cur--;
        else cur++;
        if(cur>=0)return true;
        i++;
      }
      if(i<n and a[i]==k and cur+1>=0)return true;
    }else i++;
  }

  return false;
}


void solve(){
  cin>>n>>k;
  vector<int> a(n);
  int aparece = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i] == k)aparece = 1;
  }
  if(!aparece){
    cout << "no"<<endl;
    return;
  }
  if(n==1){
    cout<<"yes"<<endl;
    return;
  }
  int ok = 0;
  for(int i=0;i<n-1;i++){
    if(a[i]== a[i+1] and a[i]==k){
       ok = 1;
    }
    if(a[i]==k){
      if(a[i+1] >k)ok = 1;
    }
  }
  for(int i=1;i<n;i++){
    if(a[i]==k and a[i-1]>k){
      ok = 1;
    }
  }
  for(int i=0;i<n-1;i++){
    if(a[i]>k and a[i+1]>k){
      ok = 1;
    }
  }


  
  if(ok){
    cout<<"yes"<<endl;
    return;
  }

  if(tenta(a)){
    cout<<"yes"<<endl;
    return;
  }
  reverse(a.begin(),a.end());
  if(tenta(a)){
    cout<<"yes"<<endl;
    return;
  }

  
  int cur = 0,tam = 0;
  
  for(int i=0;i<n;i++){
     if(a[i]>=k)cur++;
     else cur--;
     tam++;
     if(cur >0 and tam > 1)ok = 1;
     if(cur==0 and tam > 2)ok = 1;
     if(cur<0)cur = tam=0;
  }

  if(ok){
    cout<<"yes"<<endl;
    return;
  }

  cout <<"no" << endl;

}

int32_t main(){
 fastio;
 int t;
 cin>>t;
 while(t--){
  solve();
 }
 
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}