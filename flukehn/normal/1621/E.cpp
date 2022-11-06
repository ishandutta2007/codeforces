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
int a[N];
int n,m;
vector<int> c[N];int st[N];
struct P{
  int b,id;
  bool operator<(const P&t)const{
    return b<t.b;
  }
};
P p[N];
int f[N];
namespace sgt{
  const int M=N<<2;
  int mn[M], t[M];
  int pos[M];
#define m ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
  void build(int x,int l,int r){
    mn[x]=n-r+1;
    pos[x]=r-1;
    t[x]=0;
    if(l+1==r){
    }else{
      build(ls,l,m);
      build(rs,m,r);
    }
  }
  void pt(int x,int v){
    t[x]+=v;
    mn[x]+=v;
  }
  void pd(int x){
    if(t[x]){
      pt(ls,t[x]);
      pt(rs,t[x]);
      t[x]=0;
    }
  }
  int qr,qv;
  void pu(int x){
    mn[x]=mn[ls];
    pos[x]=pos[rs];
    if(upmn(mn[x],mn[rs]))pos[x]=pos[rs];
  }
  void upd(int x,int l,int r){
    if(r<=qr){
      pt(x,qv);
    }else{
      pd(x);
      upd(ls,l,m);
      if(qr>m)upd(rs,m,r);
      pu(x);
    }
  }
  int qry(int x,int l,int r){
    if(mn[x]<0) return -1;
    if(mn[x]) return r;
    if(l+1==r) return l;
    pd(x);
    if(!mn[ls]) return qry(ls,l,m);
    return qry(rs,m,r);
  }
#undef m
#undef ls
#undef rs
}
int ch[N];
string solve(){
  cin>>n>>m;
  For(i,0,n)cin>>a[i];
  sort(a,a+n);
  For(i,0,m){
    int k;
    cin>>k;
    st[i+1]=st[i]+k;
    ll sum=0;
    //int mn=1e9;
    vector<int> d(k);
    For(j,0,k){
      cin>>d[j];
      sum+=d[j];
    }
    int b=(sum+k-1)/k;
    c[i].resize(k);
    For(j,0,k) c[i][j]=(sum-d[j]+k-2)/(k-1);
    p[i]=(P){b,i};
  }
  sort(p,p+m);
  using namespace sgt;
  sgt::build(1,0,n);

  /*int r=n-1;
  for(int i=m-1;i>=0;--i){
    if(p[i].b>a[n-1]){
      f[i]=-1;
    }else if(mn[1]<0){
      f[i]=-1;
    }else if(mn[1]>0){
      f[i]=n-1;
    }else{
      f[i]=qry(1,0,n)-1;
    }
    while(r&&a[r-1]>=p[i].b)--r;
    sgt::qr=r+1;
    sgt::upd(1,0,n);
    if(f[i]<0){
      For(j,0,i+1) f[i]=-1;
      break;
    }
  }*/
  string ans(st[m],'0');
  int l=0;
  int tot=0;
  For(i,0,m){
    while(l<n&&a[l]<p[i].b)++l;
    f[i]=l;
    if(l<n) {
      sgt::qr=l+1;
      sgt::qv=-1;
      sgt::upd(1,0,n);
    }else{
      tot+=1;
    }
  }
  dbg(mn[1]);
  dbg(tot);
  if(tot<=1){
    For(i,0,m){
      if(tot&&f[i]<n)continue;
      if(f[i]<n){
        sgt::qr=f[i]+1;
        sgt::qv=1;
        sgt::upd(1,0,n);
      }
      int w=sgt::qry(1,0,n);
      dbg(i,f[i],mn[1],w);
      if(w>0){
        
        int id=p[i].id;
        For(j,0,SZ(c[id])) {
          if(c[id][j] <= a[w-1]) ans[j+st[id]]='1';
        }
      }
      if(f[i]<n){
        sgt::qr=f[i]+1;
        sgt::qv=-1;
        sgt::upd(1,0,n);
      }
    }
  }
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