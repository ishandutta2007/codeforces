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
const int N=1511;
int l[N],r[N],p[N];



int calc(string s){
  int x=0;
  for(auto c:s)
    x=x*11+10-(c-'0');
  return x;
}
int f[N];
void solve(){
  memset(p,0,sizeof p);
  int n,m;
  cin>>n>>m;
  For(i,0,n){
    string s;
    cin>>s;
    For(j,0,m){
      For(l,2,4){
        if(j+l<=m) {
          int w=calc(s.substr(j,l));
          p[w]=i+1;
          ::l[w]=j+1;
          r[w]=j+l;
        }
      }
    }
  }
  string s;
  cin>>s;
  memset(f,0,sizeof f);
  f[0]=1;
  for(int i=0;i<m;++i){
    if(!f[i]) continue;
    For(l,2,4) {
      if(i+l>m)break;
      int w=calc(s.substr(i,l));
      if(!p[w])continue;
      f[i+l]=l;
    }
  }
  if(!f[m]){
    cout<<"-1\n";
  }else{
    using E=tuple<int,int,int>;
    vector<E> ans;
    int j=m;
    while(j) {
      int len=f[j];
      int w=calc(s.substr(j-len,len));
      ans.pb(l[w],r[w],p[w]);
      j-=len;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(auto [x,y,z]:ans)cout<<x<<" "<<y<<" "<<z<<"\n";
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
}