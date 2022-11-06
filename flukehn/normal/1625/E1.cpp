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
const int N=3e5+11;

int n,Q;
struct BIT{
  ll c[N];
  void add(int x, ll v){
    for(;x<=n+1;x+=x&-x)c[x]+=v;
  }
  ll qry(int x){
    ll r=0;
    for(;x;x-=x&-x)r+=c[x];
    return r;
  }
};

char s[N];
int p[N];
int f[N],fa[N];
BIT t1,t2;

//int lv[N];
int dg[N];
ll su[N];
int vv[N];
int ls[N],rs[N];
int dep[N], ff[N];
int st[N],ed[N];
vector<int> e[N];
int find(int x){
  return f[fa[x]]?fa[x]:fa[x]=find(fa[x]);
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>Q>>s+1;
  f[0]=n+1;
  s[0]='(';
  int t=0;
  for(int i=1;i<=n;++i){
    if(s[i]==')'){
      if(t) {
        int x=p[t];
        f[x]=i;
        f[i]=x;
        //dg[fa[x]]+=1;
        //lv[x]=t;
        --t;
      }
    }else{
      int y=p[t];
      int x=i;
      p[++t]=i;
      fa[x]=y;
    }
  }
  for(int i=1;i<=n;++i)
    if(f[i]&&s[i]=='(') {
      int y=find(i);
      dg[y]+=1;
      e[y].pb(i);
    }
  for(int i=0;i<=n;++i){
    if(!f[i]||s[i]!='(')continue;
    int x=-1;
    for(int y:e[i]){
      if(x<0){
        ls[i]=y;
        ff[y]=i;
      }else{
        ff[y]=x;
        rs[x]=y;
      }
      dep[y]=dep[ff[y]]+1;
      x=y;
    }
  }
  for(int i=n;i>=1;--i){
    if(!f[i]||s[i]!='(')continue;
    su[i]+=1ll*dg[i]*(dg[i]-1)/2+1;
    su[ff[i]]+=su[i];
  }
  for(int i=n;i>=0;--i){
    if(!f[i]||s[i]!='(')continue;
    st[i]=i;
    if(ls[i])ed[i]=ed[ls[i]];
    if(rs[i])ed[i]=ed[rs[i]];
  }
  for(int i=0;i<=n;++i)dbg(i,ls[i],rs[i],st[i],ed[i],dg[i],su[i]);
  For(i,1,Q+1){
    int t;
    int l,r;
    cin>>t>>l>>r;
    if(t==1){
      t2.add(st[l]+1,-1);
      t2.add(ed[l]+1,1);

      l=fa[l];
      //dbg(l,dg[l]);
      t1.add(l+1,-dg[l]);
      dg[l]-=1;
    }else{
      auto qry=[&](int x){
        return su[x]+t1.qry(ed[x]+1)-t1.qry(st[x]);
      };
      r=f[r];
      //dbg(l,r,rs[r]);
      ll ans=qry(l);
      dbg(l,r,rs[r],su[rs[r]]);
      //dbg(ans);
      if(rs[r]) ans-=qry(rs[r]);
      int w=dep[r]-t2.qry(r+1);
      w-=dep[ff[l]]-t2.qry(ff[l]+1);
      dbg(ans,qry(l),w);
      ans+=1ll*w*(w-1)/2;
      cout<<ans<<"\n";
    }
  }
}