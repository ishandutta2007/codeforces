#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
template<class T>
struct BIT{
	int n;
	T c[N*2];
	void clear(int m){
		n=m;
		for(int i=0;i<=m;++i) c[i]=0;
	}
	T operator[](int x){
		T r=0;
		for(;x;x-=x&-x) r+=c[x];
		return r;
	}
	void add(int x,T v){
		for(;x<=n;x+=x&-x) c[x]+=v;
	}
	int kth(T k){
		int p=0;
		for(int j=19;j>=0;--j)
			if(p+(1<<j)<=n&&c[p+(1<<j)]<k){
				p+=1<<j;
				k-=c[p];
			}
			return p+1;
	}
} ;
BIT<int> t1;
BIT<long long> t2;
int n;
string s;
ll ans;
const int INF=~0u>>2;
int sum[N];
namespace SGT{
int a[N];
int mx[N << 2], se[N << 2], cn[N << 2], tag[N << 2];
long long sum[N << 2];

inline void pushup(int u) {  // 
  const int ls = u << 1, rs = u << 1 | 1;
  sum[u] = sum[ls] + sum[rs];
  if (mx[ls] == mx[rs]) {
    mx[u] = mx[rs];
    se[u] = max(se[ls], se[rs]);
    cn[u] = cn[ls] + cn[rs];
  } else if (mx[ls] > mx[rs]) {
    mx[u] = mx[ls];
    se[u] = max(se[ls], mx[rs]);
    cn[u] = cn[ls];
  } else {
    mx[u] = mx[rs];
    se[u] = max(mx[ls], se[rs]);
    cn[u] = cn[rs];
  }
}

inline void pushtag(int u, int tg) {  // 
  if (mx[u] <= tg) return;
  sum[u] += (1ll * tg - mx[u]) * cn[u];
  mx[u] = tag[u] = tg;
}

inline void pushdown(int u) {  // 
  if (tag[u] == -INF) return;
  pushtag(u << 1, tag[u]), pushtag(u << 1 | 1, tag[u]);
  tag[u] = -INF;
}

void build(int u = 1, int l = 1, int r = n) {  // 
  tag[u] = -INF;
  if (l == r) {
    sum[u] = mx[u] = a[l], se[u] = -INF, cn[u] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void modify_min(int L, int R, int v, int u = 1, int l = 1, int r = n) {
  //dbg(L, R, v, u, l, r);
  if (mx[u] <= v) return;
  if (L <= l && r <= R && se[u] < v) return pushtag(u, v);
  int mid = (l + r) >> 1;
  pushdown(u);
  if (L <= mid) modify_min(L, R, v, u << 1, l, mid);
  if (mid < R) modify_min(L, R, v, u << 1 | 1, mid + 1, r);
  pushup(u);
}

int query_max(int L, int R, int u = 1, int l = 1, int r = n) {  // 
  if (L <= l && r <= R) return mx[u];
  int mid = (l + r) >> 1, r1 = -INF, r2 = -INF;
  pushdown(u);
  if (L <= mid) r1 = query_max(L, R, u << 1, l, mid);
  if (mid < R) r2 = query_max(L, R, u << 1 | 1, mid + 1, r);
  return max(r1, r2);
}

long long query_sum(int L, int R, int u = 1, int l = 1, int r = n) {  // 
  if (L <= l && r <= R) return sum[u];
  int mid = (l + r) >> 1;
  long long res = 0;
  pushdown(u);
  if (L <= mid) res += query_sum(L, R, u << 1, l, mid);
  if (mid < R) res += query_sum(L, R, u << 1 | 1, mid + 1, r);
  return res;
}

/*void go() {  // 
  n = rd(), m = rd();
  for (int i = 1; i <= n; i++) a[i] = rd();
  build();
  for (int i = 1; i <= m; i++) {
    int op, x, y, z;
    op = rd(), x = rd(), y = rd();
    if (op == 0)
      z = rd(), modify_min(x, y, z);
    else if (op == 1)
      printf("%d\n", query_max(x, y));
    else
      printf("%lld\n", query_sum(x, y));
  }
}*/
}
ll solve(){
	cin>>n>>s;
	ans=0;
	t1.clear(2*n+1);
	t2.clear(2*n+1);
	For(i,1,n+1) sum[i]=sum[i-1] + (s[i-1]=='(' ? 1 : -1);
	for (int i=0;i<=n;++i) {
		int p = sum[i] + n + 1;
		int u = t1[p];
		ll v = t2[p];
		//dbg(i, u, v);
		ans += 1LL * sum[i] * u - v;
		t1.add(p, 1);
		t2.add(p, sum[i]);
	}
	dbg(ans);
	for(int i=1;i<=n;++i) SGT::a[i]=sum[i-1];
	SGT::build();
	ll su=0;
	for(int i=1;i<=n;++i){
		su+=sum[i-1];
		SGT::modify_min(1, i, sum[i]);
		ans += su - SGT::query_sum(1, i);
		//for (int j=1;j<=i;++j) debug(SGT::query_max(j,j) << " \n"[j==i]);
	}
	/*For(i,0,n) {
		int a=0;
		int sum=0;
		For(j,i,n) {
			if(s[j]=='('){
				sum+=1;
			}else{
				sum-=1;
			}
			a=max(a, -sum);
			//dbg(i,j,s.substr(i, j-i+1), max(a,b));
			ans+=max(a, a+sum);
		}
	}*/
	return ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<"\n";
	}
}