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

const int N = 55;
char mat[N][N];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
  int n,m;
inline bool ok(int l,int c){
  return l>=1 and l<=n and c>=1 and c<=m and mat[l][c]!='#';
}


bool vis[N][N];

bool bfs(int X,int Y){

  queue<pii> q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      vis[i][j] = 0;
    }
  }

  q.push(pii(X,Y));
  vis[X][Y] = 1;
  while(!q.empty()){
    pii cur = q.front();
    q.pop();
    for(int k=0;k<4;k++){
      int l = cur.ff + dx[k];
      int c = cur.ss + dy[k];
      if(ok(l,c) and !vis[l][c]){
        vis[l][c] = 1;
        q.push(pii(l,c));
      }

    }

  }


  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(mat[i][j]=='G'){
        if(!vis[i][j])return false;
      }
      if(mat[i][j]=='B'){
        if(vis[i][j])return false;
      }
    }
  }
  return true;
}

void solve(){
  cin>>n>>m;
  int bad=0,good=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> mat[i][j];
      if(mat[i][j]=='G')good++;
      else if(mat[i][j]=='B')bad++;
    }
  }
  if(good==0){
    cout <<"Yes" << endl;
    return;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){

      if(mat[i][j]=='B'){

        for(int k=0;k<4;k++){
          int l = i + dx[k];
          int c = j + dy[k];
          if(ok(l,c) and mat[l][c]!='G' and mat[l][c]!='B'){
            mat[l][c]='#';
          }
        }

      }

    }
  }

  int can = bfs(n,m);
  
  if(can)cout<<"Yes"<<endl;
  else cout<<"No" << endl;
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