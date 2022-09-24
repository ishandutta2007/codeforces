#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef __int128 l2;
//typedef long long l2;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<db,db,db,db> td4;
typedef vector<vector<ll>> mat;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
uniform_int_distribution<> gen(1,100); //gen(rng)
//https://codeforces.com/contest/1264/submission/66344993 +     
ll modinv(ll a,ll m){
	if(m==1) return 0;
	a%=m;
	if(a<0) a+=m;
	if(a==1) return 1;
	return m-modinv(m,a)*m/a;
}
template <int MOD_> struct modnum{
private:
	int v;
public:
	static const int MOD = MOD_;
 
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
	friend bool operator < (const modnum& a, const modnum& b) { return a.v < b.v; }
	friend bool operator <= (const modnum& a, const modnum& b) { return a.v <= b.v; }
	friend bool operator > (const modnum& a, const modnum& b) { return a.v > b.v; }
	friend bool operator >= (const modnum& a, const modnum& b) { return a.v >= b.v; }
 
	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}
 
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= (~o);
	}

	
	modnum operator-() const { return modnum(-v); }
	modnum& operator++() { return *this += 1; }
	modnum operator++(int){ modnum tmp=*this; ++*this; return tmp; }
	modnum& operator--() { return *this -= 1; }
	modnum operator--(int){ modnum tmp=*this; --*this; return tmp; }
 
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
	friend modnum pow(modnum a, ll p) {
		modnum ans = 1;
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend ostream& operator<<(std::ostream& os, const modnum& o)
	{
		os << o.v;
		return os;
	}
	friend istream& operator>>(std::istream& is, modnum& o)
	{
		is >> o.v;
		return is;
	}
};
const ll mod=1e9+7,inf=1e15;
using mi=modnum<1000000007>;
const int N=1e5+5;
//https://github.com/koosaga/DeobureoMinkyuParty/blob/master/teamnote.tex
vector<int> gph[N];
int dis[N], l[N], r[N], vis[N];
void clear(){ for(int i=0; i<N; i++) gph[i].clear();	}
void add_edge(int l, int r){ gph[l].push_back(r); }
bool bfs(int n){
	queue<int> que;
	bool ok = 0;
	memset(dis, 0, sizeof(dis));
	for(int i=0; i<n; i++){
		if(l[i] == -1 && !dis[i]){
			que.push(i);
			dis[i] = 1;
		}
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(auto &i : gph[x]){
			if(r[i] == -1) ok = 1;
			else if(!dis[r[i]]){
				dis[r[i]] = dis[x] + 1;
				que.push(r[i]);
			}
		}
	}
	return ok;
}
bool dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	for(auto &i : gph[x]){
		if(r[i] == -1 || (!vis[r[i]] && dis[r[i]] == dis[x] + 1 && dfs(r[i]))){
			l[x] = i; r[i] = x;
			return 1;
		}
	}
	return 0;
}
int match(int n){
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	int ret = 0;
	while(bfs(n)){
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++) if(l[i] == -1 && dfs(i)) ret++;
	}
	return ret;
}
int n,m;
tii e[N];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	int l,r,ans;
	l=n; r=m; ans=-1;
	for(int u,v,d,i=1;i<=m;i++){
		cin>>u>>v>>d;
		e[i]=tii(d,u,v);
	}
	sort(e+1,e+1+m);
	while(l<=r){
		int mid=(l+r)>>1;
		clear();
		for(int i=1;i<=mid;i++) add_edge(get<1>(e[i])-1,get<2>(e[i])-1);
		if(match(n)==n){
			ans=mid; r=mid-1;
		} else l=mid+1;
	}
	if(ans==-1) cout<<-1;
	else cout<<get<0>(e[ans]);
	return 0;
}