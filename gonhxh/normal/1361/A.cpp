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


const int N = 500100;
vector<int> g[N];
int t[N];
int have[N];

map<int,bool> mapa[N];

int p[N];
bool vis[N];
int32_t main(){
fastio;
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
  int a,b;
  cin>>a>>b;
  g[a].pb(b);
  g[b].pb(a);

}
queue<int> q;
for(int i=1;i<=n;i++){
  cin >> t[i];
  if(t[i]==1){
    q.push(i);
    vis[i] = 1;
  }
}

int id=0;

for(int i = 1;i<=n;i++){

  for(int to : g[i]){
    if(t[to] == t[i]){
      cout << -1 << endl;
      return 0;
    }
  }

}



while(!q.empty()){
  int cur = q.front();
  id++;
  q.pop();
  p[id] = cur;
  vis[cur] = 1;
  for(int to : g[cur]){
    if(vis[to])continue;
    if(t[cur] > t[to]){
     // cout << -1 << endl;
     // return 0;
    }else if(mapa[to][t[cur]]==0){
      mapa[to][t[cur]] = 1;
      have[to]++;
      if(have[to]==t[to ] - 1){
        q.push(to);
        vis[to]= 1;
      }

    }

  }

}

if(id!=n){
  cout << -1 << endl;
  return 0;
}

for(int i=1;i<=n;i++){
  cout << p[i] <<" ";
}
cout << endl;

 // Math -> gcd it all
 // Did u check N=1? Did you switch N,M?
}