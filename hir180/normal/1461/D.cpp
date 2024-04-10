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
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int n, m;
ll a[100005], b[100005], rui[100005];
set<ll>ok;
void solve(ll lb, ll ub){
	int x = lower_bound(b+1, b+n+1, lb)-b;
	int y = upper_bound(b+1, b+n+1, ub)-b;
	//[x, y)
	ok.insert(rui[y-1] - rui[x-1]);
	if(lb == ub) return;
	ll mid = (lb+ub)/2;
	x = upper_bound(b+1, b+n+1, mid)-b;
	x--;
	if(1 <= x && lb <= b[x]) solve(lb, b[x]);
	x++;
	if(x <= n && b[x] <= ub) solve(b[x], ub);
}
void solve(){
	cin >> n >> m;
	repn(i, n) cin >> a[i];
	ll mn = INF, mx = 0;
	repn(i, n){
		chmin(mn, a[i]);
		chmax(mx, a[i]);
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	repn(i, n) rui[i] = rui[i-1] + b[i];
	ok.clear();
	solve(mn, mx);
	rep(i, m){
		ll a; cin >> a;
		if(ok.find(a) != ok.end()) puts("Yes");
		else puts("No");
	}
}
int main(){
	int t; cin >> t;
	while(t--) solve();
}