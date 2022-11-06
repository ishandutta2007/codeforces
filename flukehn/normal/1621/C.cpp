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
const int N=1e4+11;
int cnt;
int ask(int i){
  ++cnt;
  cout<<"? "<<i<<endl;
  cout.flush();
  //dbg(i);
  int q;
  cin>>q;
  if(!q) exit(0);
  return q;
}
int p[N];
int n;
void solve(){
  cin>>n;
  cnt=0;
  //ask(1);
  for(int i=1;i<=n;++i) p[i]=0;
  for(int i=1;i<=n;++i){
    if(!p[i]) {
      vector<int> a;
      set<int> s;
      int x;
      for(;;){
        x=ask(i);
        if(s.count(x))break;
        s.insert(x);
        a.pb(x);
      }
      int m=SZ(a);
      For(j,0,m) p[a[(j+m-1)%m]]=a[j];
      assert(p[i]);
    }
  }
  cout<<"!";
  for(int i=1;i<=n;++i)cout<<" "<<p[i];
  cout<<endl;
  cout.flush();
}
int main(){
#ifdef flukehn
  //freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--)solve();
}