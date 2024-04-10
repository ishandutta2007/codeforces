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

const int N = 1010;
char mat[N][N];
char mat2[N][N];
 int n,m,t;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int ok(int l,int c){
  return l>=1 and l<=n and c>=1 and c<=m;
}

int sla(int i,int j){
  
  for(int k=0;k<4;k++){
    int l = dx[k] + i;
    int c = dy[k] + j;
    if(ok(l,c) and mat[l][c]==mat[i][j])return true;
  }
  return false;

}

 void process(){  



  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){

      if(sla(i,j))mat2[i][j] = (mat[i][j]=='0' ? '1' : '0');
      else mat2[i][j] = mat[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<mat2[i][j];
      mat[i][j] = mat2[i][j];
    }
    cout<<endl;
  }


}

struct coisa{
 int ini,t,vis;

};

coisa v[N][N];

int32_t main(){
 fastio;
 cin>>n>>m>>t;
 for(int i=1;i<=n;i++){
  for(int j=1;j<=m;j++){
    cin>>mat[i][j];
    v[i][j].ini = mat[i][j]-'0';
    v[i][j].vis = -1;
    v[i][j].t = 0;
  }
 }

 queue<pii> q;
 for(int i=1;i<=n;i++){
  for(int j=1;j<=m;j++){
      if(sla(i,j)){
         v[i][j].t = 0;
         v[i][j].vis = 1;
         q.push(pii(i,j));
      }
  }
 }

 while(!q.empty()){
     pii cur = q.front();
    q.pop();
    for(int k=0;k<4;k++){
      int l =dx[k] + cur.ff;
      int c = dy[k] +cur.ss;
      if(ok(l,c)){
        if(v[l][c].vis == -1){
          v[l][c].t = v[cur.ff][cur.ss].t + 1;
          v[l][c].vis = 1;
          q.push(pii(l,c));
        }
      }
    }
 }

 while(t--){
  int a,b,c;
  cin>>a>>b>>c;

  int tempo = v[a][b].t;
  tempo ++ ;

  if(v[a][b].vis == -1){
    cout << v[a][b].ini<<endl;
  }else if(c < tempo){
    cout<< v[a][b].ini<<endl;
  }else{
    c-=tempo-1;
    cout << (v[a][b].ini^(c%2))<<endl;
  }

 }
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}