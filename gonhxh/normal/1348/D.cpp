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

const int N = 150;
int a[N];
int b[N*N];
  int n,k;
int ok(){
  int sum=0;

  for(int i=1;i<=k;i++){
    sum+=b[i];
  }
  int s2=sum;
  int tam = n;
  for(int i=k+1;i<=tam;i++){
    s2-=a[i-k];
    s2+=a[i];
    if(s2!=sum)return false;
  }
  return true;
}
int T;
int go(int n,int m,int obj,int t){
  if(n==obj){
    T = min(T,t);
    return t;
  }
  if(n>obj)return 1e9;
  int has = 1e9;
  for(int x=m;x>=0;x--){
    has = min(has,go(n+x+m,m+x,obj,t+1));
  }
  return has;
}

//int it=0;
void go2(int n,int m,int obj,int t){
  if(n==obj){
    return;
  }
  for(int x=m;x>=0;x--){

    if(go(n+x+m,m+x,obj,t+1)==T){
      cout<<x<<" ";
      go2(n+x+m,m+x,obj,t+1);
      return;
    }
  }

}

void solve(ll coisa=0){
  int n,m;
   if(coisa==0)cin>>n;
   else n = coisa;
  if(n==3){
    cout<<1<<endl;
    cout<<1<<endl;
    return;
  }
  int t=0;
  for(int i=30;i>=0;i--){
    
    if(n&(1LL<<i)){
      t = i;
      break;
    }
  }
  cout<<t <<endl;
  T  =t ;

  if(n<10){
    go2(1,1,n,0);
    cout<<endl;

  }else if((1<<t)==n){
    // corner:

    int has = 1;

    for(int x=1;x<=t;x++){
      if(x==1)cout<<0<<" ";
      else{ 
        cout<<has<<" ";
        has = has + has;
      }
    }

    cout<<endl;
  }else{

    int has = 1;
    int m = 1;
    for(int x=1;x<t-1;x++){
      cout<<has<<" ";
      m = m + has + has;
      has = has + has;
    }

    int op1 = m + has + has;
    int has2 = has + has;
    op1 = op1 + has2;
    if(n < (op1)){

      for(int x=1;x<=has;x*=2){
        has2 = has + x;
        int m2 = m + has2;
        if(n-m2-has2<=has2 and n-m2-has2>=0){
          //ok
        }else continue;
      cout<<x<<" ";
      has +=x;
      m+=has;
      cout<<n-m-has <<endl;
       } 
    
    }else{
      //
      cout<<has<<" ";
      has+=has;
      m+=has;

      cout << n - m - has << endl;
     
    }

  }

}

int32_t main(){
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
 /*
  for(int i=(1<<27);i<(1<<28);i+=100000){
    solve(i);
  }*/

  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}