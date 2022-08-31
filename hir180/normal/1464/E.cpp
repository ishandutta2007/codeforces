//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
template<class T>
T mul(T a, T b){
	return (T) ((ll)(a) * b % mod);
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
template<class T>
vector<T>BerlekampMassey(vector<T>x){
	vector<T>ls,cur;
	T lf,ld;
	rep(i,x.size()){
		T t = 0;
		for(int j=0;j<cur.size();j++){
			t = (t+(ll)x[i-j-1]*cur[j])%mod;
		}
		if( ((t-x[i])%mod+mod)%mod == 0 ) continue;
		if(!cur.size()){
			cur.resize(i+1); lf = i; ld = (t-x[i])%mod;
			continue;
		}
		T k = (ll) -(x[i]-t)*modpow(ld,mod-2)%mod;
		vector<T>c(i-lf-1);
		c.pb(k);
		rep(j,ls.size()) c.pb((ll)-ls[j]*k%mod);
		if(c.size() < cur.size()) c.resize(cur.size());
		rep(j,cur.size()){
			c[j]=(c[j]+cur[j]);
			while(c[j] < 0) c[j] += mod;
			while(c[j] >= mod) c[j] -= mod;
		}
		if(i-lf+(int)(ls.size()) >= (int)(cur.size())){
			ls = cur, lf = i, ld = (t-x[i])%mod;
		}
		cur = c;
	}
	rep(i,cur.size()) cur[i] = (cur[i]%mod+mod)%mod;
	return cur;
}
 
vector<int>rand_vec(int n, int seed = -1){
	if(seed == -1) seed = n;
	mt19937 mt(seed);
	vector<int>ret(n);
	rep(i, n) ret[i] = mt() % (mod-1) + 1;
	return ret;
}
int dot(vector<int>&a, vector<int>&b){
	int ret = 0;
	rep(i, a.size()) add(ret, mul(a[i], b[i]));
	return ret;
}
vector<int>find_min_poly(int n, vector<P1>mat){
	srand((unsigned)time(NULL));
	vector<int>M = rand_vec(n), R = rand_vec(n, rand());
	vector<int>test(2*n);
	rep(i, 2*n){
		test[i] = dot(M, R);
		vector<int>nw(n);
		rep(j, mat.size()){
			int r = mat[j].sc.fi, c = mat[j].sc.sc;
			add(nw[r], mul(mat[j].fi, M[c]));
		}
		swap(nw, M);
	}
	vector<int>ret = BerlekampMassey(test);
	for(int i=0;i<ret.size();i++){
		if(ret[i]) ret[i] = mod-ret[i];
	}
	reverse(all(ret));
	ret.pb(1);
	return ret;
}
int calc_det(int n, vector<P1>mat){
	srand((unsigned)time(NULL));
	while(1){
		vector<int>M = rand_vec(n, rand());
		vector<P1>cp = mat;
		rep(j, mat.size()){
			int r = mat[j].sc.fi, c = mat[j].sc.sc;
			cp[j].fi = mul(cp[j].fi, M[c]);
		}
		vector<int>ret = find_min_poly(n, cp);
		if(ret[0] == 0) return 0;
		if(ret.size() != n+1) continue;
		int ans = (n%2 == 0 ? ret[0] : mod-ret[0]);
		int d1 = 1;
		for(auto a:M) d1 = mul(d1, a);
		d1 = modpow(d1, mod-2);
		return (mul(ans, d1)%mod+mod)%mod;
	}
}
//det(A) = 0vector
//det(A) != 01
vector<int>AxB(int n, vector<P1>mat, vector<int>b){
	vector<int>c = find_min_poly(n, mat);
	if(c[0] == 0) return vector<int>();
	
	int k = c.size();
	int coef = modpow(c[0], mod-2);
	if(coef) coef = mod-coef;
	
	vector<int>ans(n);
	for(int i=1;i<k;i++){
		int CC = mul(c[i], coef);
		rep(j, n) add(ans[j], mul(b[j], CC));
		vector<int>nw(n);
		rep(j, mat.size()){
			int r = mat[j].sc.fi, c = mat[j].sc.sc;
			add(nw[r], mul(mat[j].fi, b[c]));
		}
		swap(nw, b);
	}
	return ans;
}

void solve(int n, vector<int>vec){
	vector<int>b;
	vector<P1>mat;
	int m = 512;
	rep(i, m){
		if(i == 0) b.pb(0);
		else b.pb(modpow(n+1, mod-2));
	}
	rep(i, m) rep(j, m){
		int x = vec[i ^ j];
		if(i == j){
			x += mod-1;
			if(x >= mod) x -= mod;
		}
		mat.pb(mp(x, mp(i, j)));
	}
	auto kaede = AxB(m, mat, b);
	ll ans = mod - kaede[0];
	if(ans >= mod) ans -= mod;
	cout << ans << endl;
}
vector<int>edge[100005], redge[100005];
int out[100005], gr[100005];
int n, m;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
		int u, v; cin >> u >> v;
		redge[v].pb(u);
		edge[u].pb(v);
		out[u] ++;
	}
	queue<int>que;
	repn(i, n) if(out[i] == 0){
		gr[i] = 0;
		que.push(i);
	}
	while(!que.empty()){
		int q = que.front(); que.pop();
		rep(i, redge[q].size()){
			int to = redge[q][i];
			out[to] --;
			if(out[to] == 0){
				set<int>S;
				rep(j, edge[to].size()) S.insert(gr[edge[to][j]]);
				rep(k, INF){
					if(S.find(k) == S.end()){
						gr[to] = k; break;
					}
				}
				que.push(to);
			}
		}
	}
	vector<int>A(512, 0);
	repn(i, n){
		A[gr[i]] += modpow(n+1, mod-2);
		if(A[gr[i]] >= mod) A[gr[i]] -= mod;
	}
	solve(n, A);
}