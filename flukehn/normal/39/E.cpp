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
int a,b,n;
map<pa,int> f;

int chk(int x,int y,int n){
  if(x==1) return 1>=n;
  int r=1;
  for(int i=0;i<y&&r<n;++i)r=min(1ll*n,1ll*x*r);
  return r>=n;
}
int F(int x,int y){
  auto w=pa(x,y);
  if(f.count(w)) return f[w];
  if(chk(x,y,n)) return f[w]=1;
  if(x==1){
    int u=F(x+1,y);
    if(u==0)return f[w]=1;
    if(u==1&&chk(x+1,y+1,n)){
      return f[w]=-1;
    }
    int v=F(x,y+1);
    if(!v) return f[w]=1;
    if(u==-1||v==-1) return f[w]=-1;
    return f[w]=0;
  }else{
    int v=F(x,y+1);
    if(!v) return f[w]=1;
    if(v==1&&y==1&&chk(x+1,y+1,n)){
      return f[w]=(n-x+1)%2;
    }
    return F(x+1,y)^1;
  }
}
int solve(){
  f.clear();
  return F(a,b);
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  const string s[]={"Missing","Stas","Masha"};
  while(cin>>a>>b>>n)cout<<s[solve()+1]<<"\n";
}