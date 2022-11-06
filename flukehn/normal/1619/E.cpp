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
const int N=2e5+11;
int n;
int a[N];
int b[N];
ll ans[N];
void solve(){
  cin>>n;
  For(i,0,n)cin>>a[i];
  For(i,0,n+1)b[i]=0;
  For(i,0,n)b[a[i]]+=1;
  multiset<int> s;
  ll now=0;
  For(i,0,n+1){
    ans[i]=now+b[i];
    if(b[i]){
      For(j,1,b[i]) s.insert(i);
    }else{
      if(s.empty()) {
        For(j,i+1,n+1) ans[j]=-1;
        break;
      }
      int p=*s.rbegin();
      now+=i-p;
      s.erase(s.lower_bound(p));
    }
  }
  For(i,0,n+1)cout<<ans[i]<<" \n"[i+1==i_end];
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