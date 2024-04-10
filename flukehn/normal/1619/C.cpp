#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
using ll=long long;
using pa=pair<int,int>;
template<class A,class B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<class A,class B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
const int mo=998244353;
constexpr int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
constexpr int reduce(int x){return x+(x>>31&mo);}
constexpr int& inc(int &x,int y){return x=reduce(x+y-mo);}
constexpr int& dec(int &x,int y){return x=reduce(x-y);}
#ifdef flukehn
void debug_out(){cerr<<endl;}
template <typename Head,typename... Tail>
void debug_out(Head H,Tail... T){
  cerr<<" "<<H;//to_string(H);
  debug_out(T...);
}
#define dbg(...) cerr<<"L"<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
#define debug(...) cerr<<__VA_ARGS__//fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
int f[22][22];
ll solve(){
  ll a,s;
  cin>>a>>s;
  vector<int> x,y;
  while(a)x.pb(a%10),a/=10;
  while(s)y.pb(s%10),s/=10;
  int n=SZ(x),m=SZ(y);
  while(SZ(x)<SZ(y)) x.pb(0);
  memset(f,0,sizeof f); 
  f[0][0]=1;
  For(i,0,m)For(j,0,m){
    if(!f[i][j])continue;
    dbg(i,j,f[i][j]);
    if(y[j]>=x[i]){
      f[i+1][j+1]=1;
    }
    if(j<m-1){
      int w=y[j+1]*10+y[j];
      if(y[j+1]&&w-x[i]<=9&&w-x[i]>=0) f[i+1][j+2]=2;
    }
  }

  ll b=0;
  int p=m,q=m;
  while(p>n&&!f[p][q])--p;
  if(p<0||!f[p][q])return -1;
  while(p){
    dbg(p,q,f[p][q]);
    b=b*10-x[p-1];
    if(f[p][q]==1)b+=y[q-1];
    else b+=y[q-1]*10+y[q-2];
    q-=f[p][q];
    p-=1;
  }
  return b;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)cout<<solve()<<"\n";
}