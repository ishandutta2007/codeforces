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
const int N=23;
int n;
int f[N][26];
int g[1<<N][26];
int ans[1<<N];
ll solve(){
  memset(f,0,sizeof f);
  For(i,0,n){
    string s;
    cin>>s;
    for(auto c:s)f[i][c-'a']+=1;
  }
  memset(g,0x3f,sizeof g); 
  
  For(j,0,1<<n)
    For(i,0,n)if(j>>i&1){
      For(k,0,26)g[j][k]=min(g[j^(1<<i)][k],f[i][k]);
      break;
    }
  memset(ans,0,sizeof ans);
  ans[0]=1;
  For(i,1,1<<n){
    int t=1;
    For(j,0,26)t=1ll*t*(g[i][j]+1)%mo;
    dec(t,1);
    if(__builtin_popcount(i)%2 == 0)t=(mo-t)%mo;
    ans[i]=t;
    //dbg(i,ans[i]);
  }
  For(i,0,n){
    For(j,0,1<<n)if(~j>>i&1)inc(ans[j^(1<<i)],ans[j]);
  }
  ll ret=0;
  For(j,0,1<<n){
    int p=0;
    For(i,0,n)if(j>>i&1)p+=i+1;
    p*=__builtin_popcount(j);
    //dbg(j,ans[j]);
    ret ^= 1ll * p * ans[j];
  }
  return ret;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n){
    cout<<solve()<<"\n"; 
  }
}