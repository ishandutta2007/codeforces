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
//#define int long long
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

const int N = 1010;
int vis[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
char mat[N][N];
int ok(int l,int c){
  if(l>=1 and l<=n and c>=1 and c<=m and !vis[l][c] and mat[l][c]=='#')return true;
  return false;
}

void dfs(int i,int j){
  vis[i][j]=1;
  for(int k=0;k<4;k++){
    int l = i + dx[k];
    int c = j + dy[k];
    if(ok(l,c)){
      dfs(l,c);
    }
  }
}


int col[N],lin[N];

int32_t main(){
  fastio;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>mat[i][j];
    }
  }
  int comp=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(vis[i][j])continue;
      if(mat[i][j]=='#'){
        comp++;
        dfs(i,j);
      }
    }
  }

  // look for bad:
  int ok = 1;
  for(int i=1;i<=n;i++){
    int f=0;
    int t=0;
    for(int j=1;j<=m;j++){
      if(mat[i][j]=='#'){
        if(f==0)t++;
        f=1;
      }else f=0;
    }
    if(t>1)ok=0;
  }
  for(int j=1;j<=m;j++){
    int f=0;
    int t=0;
    for(int i=1;i<=n;i++){
      if(mat[i][j]=='#'){
        if(f==0)t++;
        f=1;
      }else f=0;
    }
    if(t>1)ok=0;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(mat[i][j]=='#')lin[i]++;
    }
  }
  for(int j=1;j<=m;j++){
    for(int i=1;i<=n;i++){
      if(mat[i][j]=='#')col[j]++;
    }
  }



  for(int i=1;i<=n;i++){
    if(lin[i]!=0)continue;
    int have=0;  
    for(int j=1;j<=m;j++){
      if(col[j]==0)have++;
    }
    if(!have)ok=0;
  }
  for(int j=1;j<=m;j++){
    if(col[j]!=0)continue;
    int have=0;
    for(int i=1;i<=n;i++){
      if(lin[i]==0)have++;
    }
    if(!have)ok=0;
  }

  if(!ok)cout<<-1<<endl;
  else cout<<comp<<endl;


  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}