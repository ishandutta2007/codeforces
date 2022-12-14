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
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define M   1000000007 // 1e9 + 7
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
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
int n,k;
int c[N];
const int MAXN = 200100;
ll tree[4*MAXN];



int cnt[N];
void build(int no,int i,int j){
  if(i==j){
    tree[no] = (cnt[i]!=0 ? c[i] : -1e9);
    
  }else{
    int m = (i+j)/2;
    int l = 2*no,r=2*no+1;
    build(l,i,m);
    build(r,m+1,j);
    tree[no] = max(tree[l],tree[r]);
  }
}
void update(int no,int i,int j,int p){
  if(i==j){
    tree[no] = -1e9;
  }else{
    int m = (i+j)/2,l=2*no,r=2*no+1;
    if(p<=m)update(2*no,i,m,p);
    else update(2*no + 1,m+1,j,p);
    tree[no] = max(tree[l],tree[r]);
  }
}

int query(int no,int i,int j,int val){
//  cout<<i<<" "<<j<<" "<<tree[no]<<endl;
  if(tree[no] <= val)return -1;
  if(i==j)return i;
  int m = (i+j)/2,l=2*no,r=2*no+1;
  if(tree[r] > val)return query(2*no+1,m+1,j,val);
  else return query(2*no,i,m,val);
}


// long long ? 
int32_t main(){
  fastio;
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    cnt[x]++;
  }
  for(int i=1;i<=k;i++)cin>>c[i];

   build(1,1,k);
   vector<vector<int> > ans;
   int tot=0,pos =k ;
   while(tot<n){

    vector<int> cur;
    int it=0;
    while(true){
      if(tot>=n)break;
      pos = query(1,1,k,cur.size());
     
      if(pos==-1)break;
        cur.pb(pos);
        cnt[pos]--;
        if(cnt[pos]==0)update(1,1,k,pos);
        tot++;
    }
    
    ans.pb(cur);
  
   }

   cout<< ans.size()<<endl;
   for(vector<int> v : ans){
    cout<<v.size()<<" ";
    for(int x : v){
      cout<<x<<" ";
    }
    cout<<endl;
   }


    // Math -> gcd it all
    // Did u check N=1? Did you switch N,M?
}