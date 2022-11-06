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
const int N=1e5+7;
char s[N];
int n;
vector<int> p[4];
int a[N];
ll tmp;
void merge_sort(int *a,int n){
  if(n<=1)return;
  int m=n/2;
  merge_sort(a,m);
  merge_sort(a+m,n-m);
  static int b[N];
  For(i,0,n)b[i]=a[i];
  int p=0,q=m;
  int i=0;
  while(p<m&&q<n)a[i++]=b[p]<b[q]?b[p++]:(tmp+=m-p,b[q++]);
  while(p<m)a[i++]=b[p++];
  while(q<n)a[i++]=b[q++];
}
void work(){
  cin>>s;
  n=strlen(s);
  const char t[]="ANTO";
  For(i,0,4)p[i].clear();
  For(i,0,n){
    int j=0;
    while(t[j]!=s[i])++j;
    s[i]=j;
    assert(j<4);
    p[j].push_back(i);
  }
  int q[4],oq[4];
  For(i,0,4)q[i]=i;
  ll ans=-1;
  do{
    int now=0;
    tmp=0;
    For(i,0,4){
      int x=q[i];
      For(j,0,SZ(p[x])){
        a[now++]=p[x][j];
      }
    }
    merge_sort(a,n);
    if(upmx(ans,tmp))For(i,0,4)oq[i]=q[i];
  }while(next_permutation(q,q+4));
  int z=0;
  For(i,0,4)For(j,0,SZ(p[oq[i]]))s[z++]=t[oq[i]];
  dbg(ans);
  cout<<s<<"\n";
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int T;
  cin>>T;
  while(T--)work();
}