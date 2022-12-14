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
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
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

const int N = 1e6 + 100;
ll a[N];
ll r1,r2,r3;
ll d;
ll dp[N][2];// to em i, usei laser no anterior yes/no
bool vis[N][2];
int n;
ll solve(int i,int f){
  if(i == n + 1){
    if(f)return d;
    return -d;
  }
  if(vis[i][f])return dp[i][f];
  vis[i][f] = 1;
  ll op1 = a[i]*r1 + r3;
  if(f)op1+=d+d;
  op1+=solve(i+1,0) + d;
  ll op2 = r2 + r1;
  if(f){
    op2+=d * 2;
    op2+=d + solve(i+1,0);
  }else{
    op2+=solve(i+1,1) + d;
    
  }
  ll op3 = (a[i]+2)*r1;
  if(f){
    op3+=d * 2;
    op3+=d + solve(i+1,0);
  }else{
    op3+=solve(i+1,1) + d;
  }
  if(i == n and f){
    ll op4 = a[i]*r1 + r3 + d;
    op1 = min(op1,op4);
  }

  //cout << i<<" "<<f<<" "<<op1<<" "<<op2<<" "<<op3<<endl;
  return dp[i][f] = min({op1,op2,op3});
}

void roll(int i,int f){
  if(i == n + 1)return;
  ll op1 = a[i]*r1 + r3;
  if(f)op1+=d+d;
  op1+=solve(i+1,0) + d;
  ll op2 = r2 + r1;
  if(f){
    op2+=d * 2;
    op2+=d + solve(i+1,0);
  }else{
    op2+=solve(i+1,1) + d;
    
  }
  ll op3 = (a[i]+2)*r1;
  if(f){
    op3+=d * 2;
    op3+=d + solve(i+1,0);
  }else{
    op3+=solve(i+1,1) + d;
  }
  if(i == n and f){
    ll op4 = a[i]*r1 + r3 + d;
    op1 = min(op1,op4);
  }
  if(i == 1){
    cout<<"best "<<min({op1,op2,op3}) << endl;
  }
  if(op1 == min({op1,op2,op3})){
    cout <<"use op1 at "<<i<<" "<<f<<endl;
    roll(i+1,0);
    return;
  }
  if(op2 == min({op2,op3})){
    cout<<"use op2 at "<<i<<" "<<f<<endl;
    if(f)roll(i+1,0);
    else roll(i+1,1);
    return;
  }
  cout<<"use op3 at "<<i<<" "<<f<<endl;
  if(f)roll(i+1,0);
  else roll(i+1,1);
  return;
}

int32_t main(){
  fastio;

  cin>>n>>r1>>r2>>r3 >> d;
  //if(r3 > 2*r1)r3 = 2*r1;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }

  cout << solve(1,0) << endl;
  return 0;

  roll(1,0);
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}