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
const int mo=1e9+7;
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
const int N=2e5+9;
int l[N],r[N],c[N<<1];
int k,n;
int f[N<<1];
int jc[N],jcv[N];
int C(int a,int b){
  return a<b?0:1ll*jc[a]*jcv[b]%mo*jcv[a-b]%mo;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  jc[0]=1;
  For(i,1,N)jc[i]=1ll*jc[i-1]*i%mo;
  jcv[N-1]=Pow(jc[N-1],mo-2);
  for(int i=N-1;i>=1;--i)jcv[i-1]=1ll*jcv[i]*i%mo;
  cin>>n>>k;
  For(i,0,n){
    cin>>l[i]>>r[i];
    ++r[i];
    c[i*2]=l[i];
    c[i*2+1]=r[i];
  }
  sort(c,c+2*n);
  int m=unique(c,c+2*n)-c;
  For(i,0,n){
    int x=lower_bound(c,c+m,l[i])-c;
    int y=lower_bound(c,c+m,r[i])-c;
    f[x]+=1;
    f[y]+=-1;
  }
  For(i,1,m)f[i]+=f[i-1];
  int ans=0;
  For(i,0,m-1)
    inc(ans,1ll*C(f[i],k)*(c[i+1]-c[i])%mo);
  cout<<ans<<"\n";
}