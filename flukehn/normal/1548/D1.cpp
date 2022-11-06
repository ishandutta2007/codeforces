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
int n;
ll C(int a,int b){
  b=min(b,a-b);
  if(b<0)return 0;
  ll t=1;
  for(int i=a-b+1;i<=a;++i)t*=i;
  for(int i=1;i<=b;++i)t/=i;
  return t;
}
ll solve(){
  int a[4]={0};
  for(int i=0;i<n;++i){
    int x,y;
    cin>>x>>y;
    x/=2;
    y/=2;
    a[x%2*2+y%2]+=1;
  }
  ll ans=0;
  for(int i=0;i<4;++i)
    for(int j=i;j<4;++j)
      for(int k=j;k<4;++k){
        int t=(j!=i)^(k!=j)^(k!=i)^1;
        if(!t)continue;
        int b[4]={0};
        b[i]+=1;
        b[j]+=1;
        b[k]+=1;
        ll tmp=1;
        for(int x=0;x<4;++x)tmp*=C(a[x],b[x]);
        if(tmp)dbg(i,j,k,tmp);
        ans+=tmp;
      }
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n)cout<<solve()<<"\n";
}