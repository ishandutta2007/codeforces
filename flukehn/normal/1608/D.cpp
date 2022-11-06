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
const int N=2e5+11;
int jc[N],jcv[N];
int C(int a,int b){return a<b||b<0?0:1ll*jc[a]*jcv[b]%mo*jcv[a-b]%mo;}
int n;
namespace Poly{
#define clr(x) memset(x,0,sizeof x)
#define per(i,a,b) for(int i=b,i##_end=a;i>=i##_end;--i)
  const int N=1e6+11,mo=998244353,G=3;
  int Pow(int a,int b){
    int r=1;
    for(;b;b>>=1,a=1ll*a*a%mo)
      if(b&1)r=1ll*r*a%mo;
    return r;
  }
  void dft(int *a,int n){
    int i,j,l;
    for(i=j=0;i<n;++i){
      if(i>j)swap(a[i],a[j]);
      for(l=n>>1;(j^=l)<l;l>>=1);
    }
    for(l=1;l<n;l<<=1){
      int wn=Pow(G,(mo-1)/l/2);
      for(i=0;i<n;i+=l<<1){
        int w=1;
        for(j=0;j<l;++j,w=1ll*w*wn%mo){
          int x=a[i+j],y=1ll*w*a[i+j+l]%mo;
          a[i+j]=(x+y)>=mo?x+y-mo:x+y;;
          a[i+j+l]=x-y<0?x-y+mo:x-y;;
        }
      }
    }
  }
  void idft(int *a,int n){
    dft(a,n);
    reverse(a+1,a+n);
    int m=Pow(n,mo-2);
    For(i,0,n)a[i]=1ll*a[i]*m%mo;
  }
  void mul(int *a,int A,int *b,int B,int *c){
    int m=1;
    while(m<A+B)m<<=1;
    int x[m],y[m];
    clr(x),clr(y);
    For(i,0,A)x[i]=a[i];
    For(i,0,B)y[i]=b[i];
    dft(x,m),dft(y,m);
    For(i,0,m)c[i]=1ll*x[i]*y[i]%mo;
    idft(c,m);
  }
}
string s[N];
int tot,cnt;
void solve(int l,int r){
  dbg(l,r);
  if(l+1==r){
    if(s[l][0]=='?'&&s[l][1]=='?'){
      tot+=1;
      cnt+=2;
      //return vector<int>{1,2,1};
    }else if(s[l][0]!='?'&&s[l][1]!='?'){
      if(s[l]=="WW"){
        --tot;
        //return vector<int>{1};
      }if(s[l]=="BB"){
        ++tot;
        //return vector<int>{1};
      }
      //return vector<int>{1};
    }else if(s[l][0]=='W'||s[l][1]=='W'){
      cnt+=1;
      //return vector<int>{1,1};
    }else{
      tot+=1;
      cnt+=1;
      //return vector<int>{1,1};
    }
    return;
    //assert(0);
  }
  int m=(l+r)>>1;
  solve(l,m);
  solve(m,r);
  
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
  cin>>n;
  For(i,0,n)cin>>s[i];
  solve(0,n);
  //auto f=solve(0,n);
  int ans=C(cnt,tot);
  dbg(cnt,tot,ans);
  //dbg(f[tot]);
  int g[4]={1};
  For(i,0,n){
    int h[4];
    memcpy(h,g,sizeof h);
    memset(g,0,sizeof g);
    int t[2]={0};
    if(s[i]=="??"){
      t[0]=t[1]=1;
    }else if(s[i]=="WW"||s[i]=="BB"){
      //
    }else if(s[i]=="WB"||s[i]=="W?"||s[i]=="?B"){
      t[0]=1;
    }else{
      t[1]=1;
    }
    For(j,0,4)For(k,0,2){
      inc(g[j|1<<k],t[k]*h[j]);
    }//
  }
  dbg(g[3]);
  dec(ans,g[3]);
  cout<<ans<<'\n';
}