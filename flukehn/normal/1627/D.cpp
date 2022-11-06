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
inline int reduce(int x){return x+(x>>31&mo);}
inline int& inc(int &x,int y){return x=reduce(x+y-mo);}
inline int& dec(int &x,int y){return x=reduce(x-y);}
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
const int N=1e6+1;
int a[N];
int n;
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i){
    int x;
    cin>>x;
    a[x]=1;
  }
  int tot=0;
  for(int i=N-1;i>=1;--i){
    if(a[i]) continue;
    int g=0;
    for(int j=2;i*j<N&&g!=1;++j)
      if(a[j*i]) g=__gcd(g,j);
    if(g==1) {
      a[i]=1;
      tot+=1;
    }
  }
  cout<<tot<<"\n";
}