#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

template<typename mint_type,typename mint_type2,mint_type mint_mod>
struct modint{
  
  using type=mint_type;
  using type2=mint_type2;
  
  static const type mod=mint_mod;
  
  using mint=modint<type,type2,mod>;
  
  type v;
  
  modint():v(){}
  modint(const type &_v):v(_v){}
  
  bool operator ! ()const{return !v;}
  friend bool operator == (const mint &a,const mint &b){return a.v==b.v;}
  friend bool operator != (const mint &a,const mint &b){return a.v!=b.v;}
  
  mint &operator += (const mint &p){v=v+p.v>=mod?v+p.v-mod:v+p.v;return *this;}
  mint &operator -= (const mint &p){v=v<p.v?v+mod-p.v:v-p.v;return *this;}
  mint &operator *= (const mint &p){v=type2(v)*p.v%mod;return *this;}
  mint &operator ++ (){v+1<mod?++v:v=0;return *this;}
  mint operator ++ (int){mint res=*this;v+1<mod?++v:v=0;return res;}
  mint &operator -- (){v?--v:v=mod-1;return *this;}
  mint operator -- (int){mint res=*this;v?--v:v=mod-1;return res;}
  mint operator + ()const{return *this;}
  mint operator - ()const{return mint()-=*this;}
  friend mint operator + (const mint &a,const mint &b){return mint(a)+=b;}
  friend mint operator - (const mint &a,const mint &b){return mint(a)-=b;}
  friend mint operator * (const mint &a,const mint &b){return mint(a)*=b;}
  
  friend istream &operator >> (istream &in,mint &p){return in>>p.v;}
  friend ostream &operator << (ostream &out,const mint &p){return out<<p.v;}
  
  template<typename pow_type>
  mint pow(pow_type k)const{
    mint a=*this,res=1;
    for (;k;k/=2,a*=a)
      if (k&1) res*=a;
    return res;
  }
  
  mint inv()const{
    mint x=1,y=0;
    type a=v,b=mod;
    for (;b;){
      type t=a/b;
      swap(a-=t*b,b);
      swap(x-=t*y,y);
    }
    return x;
  }
  
};

typedef modint<int,int64,998244353> mint;

const int N=1000000;

int n,m,a[N+9],b[N+9];
mint c[N+9];

void Add(int p,mint v){for (;p<=N;p+=p&-p) c[p]+=v;}
mint Query(int p){mint res=0;for (;p;p-=p&-p) res+=c[p];return res;}

void work(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i){
    int x;
    scanf("%d",&x);
    ++a[x];
    Add(x,1);
  }
  for (int i=1;i<=m;++i)
    scanf("%d",&b[i]);
  static mint fac[N+9];
  fac[0]=1;
  for (int i=1;i<=n;++i)
    fac[i]=fac[i-1]*i;
  mint ans=0,now=1;
  for (int i=1;i<=N;++i) now*=fac[a[i]];
  now=now.inv();
  for (int i=1;i<=n;++i){
    ans+=now*Query(b[i]-1)*fac[n-i];
    //printf("%d : %d %d %d %d\n",i,now.v,b[i],Query(b[i]-1).v,fac[n-i].v);
    if (!a[b[i]]) break;
    now*=a[b[i]];
    --a[b[i]];
    Add(b[i],mint::mod-1);
    //ans+=now*fac[n-i];
    if (i==m) break;
    if (i==n&&i<m) ans+=now*fac[n-i];
  }
  printf("%d\n",ans.v);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;) work();
  return 0;
}