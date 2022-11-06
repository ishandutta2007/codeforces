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
int ask(int c){
  cout<<"+ "<<c<<endl;
  int x;
  cin>>x;
  return x;
}
int main(){
#ifdef flukehn
  //freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0);//cin.tie(0);
  int n;
  cin>>n;
  int lst=0;
  int i;
  int sum=0;
  int fl=0;
  for(i=10;i>=0;--i){
    int w=n-(1<<i)-fl;
    if(w<=0)continue;
    int x=ask(w);
    sum+=w;
    if(x==lst+1) {
      sum+=1<<i;
      fl=0;
    }else{
      fl+=w;
    }
    lst=x;
  }
  cout<<"! "<<sum<<endl;
}