#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb push_back
#define epb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using ll=long long;
using pa=pair<int,int>;
template<class A,class B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<class A,class B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<class A,class B>inline A gcd(A x,B y){for(;y;swap(x,y))x%=y;return x;}
const int mo=998244353;
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
inline void inc(int &x,int y){x=x+y>=mo?x+y-mo:x+y;}
inline void dec(int &x,int y){x=x-y<0?x-y+mo:x-y;}
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) cerr<<"L"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl;
#else
#define debug(...)
#define dbg(x)
#endif
const int inf=~0u>>2;
const int H=5;
struct mat{
  int a[H][H];
  mat(int t=inf){
    for(int i=0;i<H;++i)
      for(int j=0;j<H;++j)
        a[i][j]=i==j?t:inf;
  }
  mat operator*(const mat&t)const{
    mat r;
    for(int i=0;i<H;++i)
      for(int k=0;k<H;++k)
        for(int j=0;j<H;++j)
          upmn(r.a[i][j],a[i][k]+t.a[k][j]);
    return r;
  }
};
const int N=2e5+11;
char s[N];
int n;
int ans[H];
int ql,qr;
const int M=N<<2;
mat t[M];
#define m ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
void build(int x,int l,int r){
  if(l+1==r){
    const char p[]="2017";
    t[x]=mat(0);
    int i;
    for(i=0;i<4;++i)if(s[l]==p[i])break;
    if(i<4){
      t[x].a[i][i]=1;
      t[x].a[i][i+1]=0;
    }else if(s[l]=='6'){
      t[x].a[3][3]=t[x].a[4][4]=1;
    }
  }else{
    build(ls,l,m);
    build(rs,m,r);
    t[x]=t[ls]*t[rs];
  }
  debug("%d %d %d: \n",x,l,r);
  For(i,0,H)For(j,0,H)debug("%d%c",t[x].a[i][j]," \n"[j+1==H]);
}
void qry(int x,int l,int r){
  if(ql<=l&&r<=qr){
    static int tmp[H];
    memcpy(tmp,ans,sizeof tmp);
    memset(ans,0x3f,sizeof ans);
    for(int k=0;k<H;++k) 
      for(int j=0;j<H;++j)
        upmn(ans[j],tmp[k]+t[x].a[k][j]);
    return;
  }
  if(ql<m)qry(ls,l,m);
  if(qr>m)qry(rs,m,r);
}
#undef m
#undef ls
#undef rs
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int Q;
  cin>>n>>Q;
  cin>>s;
  build(1,0,n);
  dbg("------");
  while(Q--){
    cin>>ql>>qr;
    --ql;
    memset(ans,0x3f,sizeof ans);
    ans[0]=0;
    qry(1,0,n);
    For(i,0,H)debug("%d%c",ans[i]," \n"[i+1==H]);
    int w=ans[4];
    if(w>n)w=-1;
    cout<<w<<"\n";
  }
}