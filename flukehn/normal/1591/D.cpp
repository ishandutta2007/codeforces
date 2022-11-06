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
const int N=5e5+11;
ll tot;
void foo(int n, int *a) {
	if (n <= 1) return;
	int m = n / 2;
	foo(m, a);
	foo(n - m, a + m);
	static int b[N];
	for (int i = 0; i < n; ++i) b[i] = a[i];
	int p = 0, q = m, i = 0;
	while (p < m && q < n)
		a[i++] = b[p] <= b[q] ? b[p++] : (tot+=m-p,b[q++]);
	while (p < m) a[i++] = b[p++];
	while (q < n) a[i++] = b[q++];
}
int a[N];
int n;
int work(){
  cin>>n;
  For(i,0,n)cin>>a[i];
  tot=0;
  foo(n,a);
  For(i,1,n)if(a[i]==a[i-1])return 1;
  return tot%2^1;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)cout<<(work()?"YES":"NO")<<'\n';
}