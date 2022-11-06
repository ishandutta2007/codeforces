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
#define debug(...) cerr<<__VA_ARGS__//fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e5+11;
constexpr double pi=acos(-1);
struct cir{
  int x,y,r;
};
cir a[N];
int X;
ll sqr(int x){return 1ll*x*x;}
bool is_in(int i,int j){// i in j?
  return a[j].r>a[i].r&&sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y)<=sqr(a[i].r-a[j].r);
}
double get_y(const cir&t){
  return t.y+sqrt(sqr(t.r)-sqr(X));
}
struct cmp{
  bool operator()(int i,int j)const{
    return get_y(a[i])<get_y(a[j]);
  }
};
double get_y2(const cir&t){
  return t.y-sqrt(sqr(t.r)-sqr(X));
}
struct cmp2{
  bool operator()(int i,int j)const{
    return get_y2(a[i])<get_y2(a[j]);
  }
};
int fa[N];
int dep[N];
int n;
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cout<<fixed<<setprecision(10);
  while(cin>>n){
    for(int i=1;i<=n;++i){
      cin>>a[i].x>>a[i].y>>a[i].r;
    }
    sort(a+1,a+n+1,[](cir u,cir v){
        return u.r>v.r;
        });
    for(int i=1;i<=n;++i){
        fa[i]=0;
        for(int j=i-1;j>=1;--j)
            if(is_in(i,j)){
                fa[i]=j;
                break;
            }
    }
    double ans=0;
    For(i,1,n+1){
      //dbg(a[i].x,a[i].y,a[i].r,fa[i]);
      if(!fa[i])dep[i]=0;
      else dep[i]=dep[fa[i]]+1;
      double w=sqr(a[i].r)*pi;
      if(dep[i]==0||dep[i]%2)ans+=w;
      else ans-=w;
    }
    cout<<ans<<"\n";
  }
}