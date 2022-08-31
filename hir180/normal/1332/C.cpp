//Let's join Kaede Takagaki Fun Club !!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
struct k{
	int par[200005],ran[200005];
	void init(int sz){ for(int i=0;i<sz;i++) par[i] = i; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}kaede;

int num[200005][26];
void solve(){
	int n,k; string s; g(n); g(k); g(s);
	kaede.init(n + 2);
	
	rep(i,n){
		kaede.unite(i, n-1-i);
	}
	rep(i,n-k){
		kaede.unite(i, k+i);
	}
	rep(i,n+2)rep(j,26) num[i][j] = 0;
	rep(i,n) num[kaede.find(i)][s[i]-'a'] ++ ;
	int ans = 0;
	rep(i,n){
		if(kaede.find(i) != i) continue;
		int sum = 0, mx = 0;
		rep(j,26){
			sum += num[i][j];
			chmax(mx, num[i][j]);
		}
		ans += sum - mx;
	}
	o(ans);
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	g(t);
	while(t--) solve();
}