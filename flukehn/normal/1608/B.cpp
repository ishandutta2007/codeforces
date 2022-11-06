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
const int N=1e5+11;
int n,a,b;
#define GG {dbg("md");cout<<"-1\n";return;}
int f[N<<2];
void work(){
  cin>>n>>a>>b;
  if(a+b>n-2)GG;
  if(abs(a-b)>1)GG;
  if(a==b){
    For(i,1,b+2){
      f[2*i-1]=i;
      f[2*i]=b+i+1;
    }
    For(i,2*b+3,n+1)f[i]=i;
  }else if(a>b){
    For(i,1,b+2){
      f[2*i-1]=i;
      f[2*i]=b+i+2;
    }
    f[2*b+3]=b+2;
    For(i,1,2*b+4)f[i]+=n-(2*b+3);
    For(i,2*b+4,n+1)
      f[i]=n-i+1;
  }else{
    swap(a,b);
    For(i,1,b+2){
      f[2*i-1]=i;
      f[2*i]=b+i+2;
    }
    f[2*b+3]=b+2;
    For(i,1,2*b+4)f[i]+=n-(2*b+3);
    For(i,2*b+4,n+1)f[i]=n-i+1;
    For(i,1,n+1)f[i]=n-f[i]+1;
    swap(a,b);
  }
  For(i,2,n)
    if(f[i]>f[i-1]&&f[i]>f[i+1])--a;
    else if(f[i]<f[i-1]&&f[i]<f[i+1])--b;
  if(a||b)GG;
  For(i,1,n+1)cout<<f[i]<<" \n"[i+1==i_end];
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)
    work();
}