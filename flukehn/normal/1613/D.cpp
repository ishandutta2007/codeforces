#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=5e5+11;
int f[N][2];
int n;
int work(){
  cin>>n;
  For(i,0,n+3)f[i][0]=f[i][1]=0;
  f[0][0]=1;
  For(i,0,n){
    int x;
    cin>>x;
    inc(f[x+1][0],f[x+1][0]);
    inc(f[x+1][1],f[x+1][1]);
    inc(f[x+1][0],f[x][0]);
    if(x>=1){
      inc(f[x-1][1],f[x-1][1]);
      inc(f[x-1][1],f[x-1][0]);
    }
    //For(i,0,n+2)debug("%d%c",f[i]," \n"[i+1==i_end]);
  }
  int ans=0;
  For(i,0,n+3)For(j,0,2)inc(ans,f[i][j]);
  dec(ans,1);
  dbg(ans);
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)cout<<work()<<"\n";
}