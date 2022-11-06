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
constexpr int inv100=Pow(100,mo-2);
int n,m,r,c,u,v,p;
int solve(){
  cin>>n>>m>>r>>c>>u>>v>>p;
  int R,C,X,Y;
  int x=1,y=1;
  if(x==1&&r==n)x=-x;
  if(x==-1&&r==1)x=-x;
  if(y==1&&c==m)y=-y;
  if(y==-1&&c==1)y=-y;
  R=r,C=c,X=x,Y=y;
  int t=0;
  vector<int> a;
  
  p=1ll*p*inv100%mo;
  //using E=tuple<int,int,int,int>;
  do{
    if(r==u||c==v) a.pb(t);
    
    r+=x;
    c+=y;
    t++;
    if(x==1&&r==n)x=-x;
    if(x==-1&&r==1)x=-x;
    if(y==1&&c==m)y=-y;
    if(y==-1&&c==1)y=-y;
  }while(r!=R||c!=C||X!=x||Y!=y);
  int q=mo+1-p;
  int p1=1;
  dbg(SZ(a),t);
  int m=SZ(a);
  for(int i=0;i<m;++i) p1=1ll*p1*q%mo;
  int ans=1ll*(Pow(mo+1-p1,mo-2)-1)*t%mo;
  int tot=0;
  int a0=1ll*(q-1)*Pow(p1-1,mo-2)%mo;
  int w=a0;
  for(int c:a) {
    inc(tot,1ll*c*w%mo);
    w=1ll*w*q%mo;
  }
  inc(ans,tot);
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)cout<<solve()<<"\n";
}