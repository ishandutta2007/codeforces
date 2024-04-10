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
#define Unique(v) sort(all(v));v.erase(unique(all(v)),v.end());
#define sz(v) (int)v.size()
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
#define prl cerr<<"called: "<< __LINE__<<endl;
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
  int mx,sum;
  node(){}
  node(int mx,int sum):mx(mx),sum(sum){}
  node operator+(const node& o){
    node r;
    r.mx = max(mx,o.mx);
    r.sum = sum + o.sum;
    return r;
  }
};
const int inf = 1e9;
struct Lazy{
  vector<node> tree;
  vector<int> lazy;
  int n;
  Lazy(int N){
    n = N;
    tree.resize(4*n + 100);
    lazy.resize(4*n + 100);
  } 

  void flush(int no,int i,int j){
    if(lazy[no]==0)return;
    tree[no].mx+=lazy[no];
    int l = no<<1,r=no<<1|1;
    if(i!=j){
      lazy[l]+=lazy[no];
      lazy[r]+=lazy[no];
    }
    lazy[no]=0;
  }

  void upd(int no,int i,int j,int a,int b){
    flush(no,i,j);
    if(i > j || i > b || j < a)return;
    if(a<=i and j<=b){
      lazy[no] = 1;
      flush(no,i,j);
      return;
    }
    int mid = (i+j)>>1,l=no<<1,r=no<<1|1;
    upd(l,i,mid,a,b);
    upd(r,mid+1,j,a,b);
    tree[no] = tree[l] + tree[r];
  }
  vi sla;
  void go(int no,int i,int j){
    flush(no,i,j);
    if(tree[no].mx <= 0)return;
    if(i == j){
      tree[no].mx = -inf;
      tree[no].sum = 0;
      sla.pb(i);
      return;
    }
    int mid = (i+j)>>1,l=no<<1,r=no<<1|1;
    go(l,i,mid);
    go(r,mid+1,j);
    tree[no] = tree[l] + tree[r];
  }
  void reset(int no,int i,int j,int p){
    flush(no,i,j);
    if(i == j){
      tree[no].mx = -inf;
      tree[no].sum = 0;
      return;
    }
    int mid = (i+j)>>1,l=no<<1,r=no<<1|1;
    if(p<=mid)reset(l,i,mid,p);
    else reset(r,mid+1,j,p);
    tree[no] = tree[l] + tree[r];
  }

  void fix(){

   // cout <<"vamo ";
    while(true){
      sla.clear();
      go(1,1,n);
      if(sz(sla) == 0)break;
      for(int x : sla){
  //    cout << x<<" ";
        upd(1,1,n,x,n);
      }
      sla.clear();
    }
 //   cout << endl;
  }
  int query(int no,int i,int j,int a,int b){
    flush(no,i,j);
    if(i > j || i > b || j <a)return 0;
    if(a<=i and j<=b)return tree[no].sum;
    int mid = (i+j)>>1,l=no<<1,r=no<<1|1;
    return query(l,i,mid,a,b) + query(r,mid+1,j,a,b);
  }


  vi vec,val;
  void build(int no,int i,int j){
    lazy[no] = 0;
    if(i == j){
      if(vec[i]){
        tree[no].mx = val[i];
        tree[no].sum = 1;
      }else{
        tree[no].mx = -inf,tree[no].sum = 0;

      }
      return;
    }
    int mid = (i+j)>>1,l=no<<1,r=no<<1|1;
    build(l,i,mid);
    build(r,mid+1,j);
    tree[no] = tree[l] + tree[r];
  }
  void buildi(vi a,vi b){
    vec = a,val = b;
    for(int i=1;i<=n;i++){
      if(val[i] > 0)vec[i] = 0;
  //    cout << val[i]<<" ";
    }
  //  cout << endl;
    build(1,1,n);
  }
  void print(int no,int i,int j){
    flush(no,i,j);
    if(i == j){
      cout << tree[no].mx<<" ";
      return;
    }
    int mid = (i+j)>>1,l=no<<1,r=no<<1|1;
    print(l,i,mid);
    print(r,mid+1,j);
  }
  void print(){
    print(1,1,n);
  }
};

const int N = 300100;
int x[N],y[N],a[N];
vector<pii> qry[N];
int res[N];
int32_t main(){
  fastio;
  int n,q;
  cin >> n >> q;
  Lazy L(n);
  vi vec(n+1),val(n+1);
  int pre=0;
  for(int i=1;i<=n;i++){
 
    cin >> a[i];
    vec[i] = (i>=a[i]);
    val[i] = i - a[i] - pre;
    if(val[i] > 0 || vec[i] == 0)vec[i] = 0,val[i] = -inf;

    if(i>=a[i] and i - a[i] <= pre){
      pre++;
    }
  }

  L.buildi(vec,val);
  for(int i=0;i<q;i++){
    cin >> x[i] >> y[i];
    qry[x[i]].pb(pii(y[i],i));
  }

  for(int it=0;it<n;it++){
    if(it){
      int ok = L.query(1,1,n,it,it);
      if(ok){
        L.reset(1,1,n,it);
        L.upd(1,1,n,it,n);
        L.fix();
      }
    }

    for(auto it2 : qry[it]){
      int id = it2.ss;
      int r = n - it2.ff;
      int ans = L.query(1,1,n,it+1,r);
      res[id] = ans;
    }
    continue;
    cout << it <<" ";
    L.print();
    cout << endl;
  }
  for(int i=0;i<q;i++){
    cout << res[i] << endl;
  }
  
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}