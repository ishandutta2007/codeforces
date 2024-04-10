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
#define int long long
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

const int N = 200100;
vi g[N],gr[N];
int grau[N];
int out[N],in[N];
void solve(){
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    g[i].clear();
    gr[i].clear();
    out[i] = in[i] = 0;
  }
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    g[x].pb(y);
    gr[y].pb(x);
  }
  int can = (4 * n) / 7;
  queue<int> q;
  for(int i=1;i<=n;i++){
      in[i]= 0;
      out[i] = 0;
      grau[i] = gr[i].size();
    if(gr[i].size() == 0)q.push(i),in[i] = -1;
  }


  while(!q.empty()){
    int cur = q.front();
    q.pop();
    grau[cur] = -n;
    
    int f1=0,f2=0;
    for(int prv : gr[cur]){
      if(in[prv] == 1){
        out[cur] = 1;
        in[cur] = 2;
        f1 = 1;
        break;
      }
    }
    for(int prv : gr[cur]){
      if(in[prv] == -1){
        in[cur] = 1;
        f2 = 1;
        break;
      }
    }
    if(f1){
      in[cur] = 2;
    }else if(f2){
      in[cur] = 1;
    }else{
      in[cur] = -1;
    }
    
    if(out[cur])in[cur]=2;

    for(int to : g[cur]){
      if(in[cur] == 2){
        
        in[to] = -1;
        grau[to]--;
        if(grau[to]==0){
   //       cout<<"push "<<to<<endl;
          q.push(to);
        }

      }else if(in[cur] == -1){
        
        in[to] = 1;
        grau[to]--;
        
        if(grau[to] == 0){
        //  cout<<"push "<<to<<endl;
          q.push(to);
        }

      }else{
        out[to] = 1;
        grau[to]--;
        if(grau[to]==0){
  //        cout <<"push "<<to<<endl;
          q.push(to);
        }
      }
    }
  }

  vi ans;
  for(int i=1;i<=n;i++){
    if(out[i])ans.pb(i);
  }
  
  assert(sz(ans)<=can);

  cout << sz(ans) << endl;
  for(int x : ans)cout<<x<<" ";
    cout << endl;


}


int32_t main(){
  fastio;
  int T;
  cin>>T;
  while(T--){
    solve();
  } 

  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}