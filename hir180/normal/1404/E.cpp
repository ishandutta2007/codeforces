//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
//#define L __int128
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
 
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
 //https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	
	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};
//unordered_set -> dtype, null_type
//unordered_map -> dtype(key), dtype(value)
using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

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
//const ll mod = 1000000007;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
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
#define _sz 1
ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}
struct edge
{
	int to,cap,rev;
};
#define SZ 200005
vector<edge>G[SZ];
bool used[SZ];
int itr[SZ],level[SZ];
void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>q;
	level[s] = 0; q.push(s);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e = G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to] = level[v]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f)
{ 
	if(v==t) return f;
	for(int &i=itr[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0 && level[v] < level[e.to])
		{ 
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{ 
	int flow=0,f;
	while(bfs(s),level[t]>=0)
	{
		memset(itr,0,sizeof(itr));
		while( (f=dfs(s,t,INF)) > 0){
			flow += f;
		}
	}
	return flow;
}
void solve(){
	int n, m;
	cin>>n>>m;
	vc<string>v(n);
	rep(i,n)cin>>v[i];
	int gain = 0;
	int s = 110000, t = 110001;
	
	rep(i, n-1){
		rep(j, m){
			int x = i*m+j;
			if(v[i][j] == '.' or v[i+1][j] == '.') continue;
			//0->1 pts
			gain += 1;
			add_edge(s, x, 1);
		}
	}
	rep(i, n){
		rep(j, m-1){
			int x = i*m+j+50000;
			if(v[i][j] == '.' or v[i][j+1] == '.') continue;
			//1->1pts
			gain+=1;
			add_edge(x, t, 1);
		}
	}
	rep(i, n-1){
		rep(j, m){
			int x = i*m+j;
			if(v[i][j] == '.' or v[i+1][j] == '.') continue;
			for(int a=i;a<=i+1;a++){
				for(int b=max(0LL,j-1);b<=j;b++){
					if(v[a][b] == '.' or b == m-1 or v[a][b+1] == '.') continue;
					int y = a*m+b+50000;
					//x0 and y1 -> -1
					add_edge(x, y, 1);
				}
			}
		}
	}
	gain -= max_flow(s, t);
	int sum = 0;
	rep(i,n)rep(j,m) if(v[i][j]=='#')sum++;
	o(sum-gain);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t=1;//cin >> t;
	while(t--) solve();
}