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
int n,K,w;
using VI=vector<pa>;
using vi=vector<int>;
vi solve(VI);
vi f(VI a,int k){
  //if(!a.size()) return vi{};
  for(auto& [x,i]:a) x^=1<<k;
  auto r=solve(a);
  //if(r.size()<1) r=vi{a[0].se};
  return r;
}
const int N=1e7;
int c[N][2];
int val[N];
int cnt;
int rt;
int newnode(){
  c[cnt][0]=c[cnt][1]=0;
  return cnt++;
}
void insert(int x,int v){
  int p=rt;
  for(int i=w-1;i>=0;--i){
    int w=x>>i&1;
    if(!c[p][w]){
      c[p][w]=newnode();
    }
    p=c[p][w];
  }
  val[p]=v;
}
pair<int,int> chk(VI u,VI v){
  if(!u.size()||!v.size()) return pa(0,0);
  cnt=1;
  rt=newnode();
  for(auto [x,i]:v) {
    assert(~x>>w&1);
    insert(x,i);
  }
  for(auto [x,i]:u){
    //assert(x>>w&1);
    int p=rt;
    int ans=1<<w;
    for(int j=w-1;j>=0;--j){
      int w=~x>>j&1;
      if(c[p][w])p=c[p][w],ans|=1<<j;
      else p=c[p][w^1];
    }
    if(ans>=K) return pa(val[p],i);
  }
  return pa(0,0);
}
vi solve(VI a){
  sort(a.begin(),a.end());
  vi r;
  if(!K||a.size()<=1){
    for(auto [x,i]:a)r.pb(i);
  }else if(K==1){
    int lst=-1;
    for(auto [x,i]:a){
      if(x==lst)continue;
      r.pb(i);
      lst=x;
    }
  }else{
    //dbg(a.size());
    //assert(w>1);
    VI b[31];
    //vi ans[30];
    for(auto [x,i]:a){
      VI tmp;
      int j;
      for(j=30;j>=w;--j)
        if(x>>j&1)break;
      //dbg(j);
      b[j].pb(x,i);
    }
    //dbg("ok");
    for(int i=30;i>w;--i) {
      //dbg(i);
      vi tmp=f(b[i],i);
      for(auto x:tmp)r.pb(x);
    }
    //dbg("ok");
    VI u=b[w],v=b[w-1];
    pair<int,int> s=chk(u,v);
    if(s.fi&&s.se){
      r.pb(s.fi);
      r.pb(s.se);
    }else{
      if(u.size()) r.pb(u[0].se);
      else if(v.size()) r.pb(v[0].se);
    }
  }
  //dbg(r.size());
  return r;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>K;
  w=30;
  while(w&& (~K>>w&1))--w;
  VI a(n);
  For(i,0,n){
    cin>>a[i].fi;
    a[i].se=i+1;
  }
  vi r=solve(a);
  int m=r.size();
  if(m<2){
    cout<<"-1\n";
  }else{
    cout<<m<<"\n";
    sort(r.begin(),r.end());
    For(i,0,m)cout<<r[i]<<" \n"[i+1==m];
  }
}