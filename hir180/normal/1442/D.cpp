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
int n, k;
ll a[3005][3005];
pair<int,ll>all[3005];
ll ans;

void solve(int l, int r, vector<ll>zan){
	if(l == r){
		rep(i, zan.size()){
			chmax(ans, zan[i] + a[l][k-i]);
		}
		return ;
	}
	int m = (l+r)/2;
	vector<ll>cur, nxt;
	cur = nxt = zan;
	for(int i=m+1;i<=r;i++){
		rep(j, nxt.size()) nxt[j] = -1e18;
		rep(j, cur.size()){
			chmax(nxt[j], cur[j]);
			if(j+all[i].fi <= k) chmax(nxt[j+all[i].fi], cur[j] + all[i].sc);
		}
		swap(cur, nxt);
	}
	solve(l, m, cur);
	
	cur = nxt = zan;
	for(int i=l;i<=m;i++){
		rep(j, nxt.size()) nxt[j] = -1e18;
		rep(j, cur.size()){
			chmax(nxt[j], cur[j]);
			if(j+all[i].fi <= k) chmax(nxt[j+all[i].fi], cur[j] + all[i].sc);
		}
		swap(cur, nxt);
	}
	solve(m+1, r, cur);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	rep(i, n){
		int t; cin >> t;
		all[i].fi = min(t, k);
		repn(j, t){
			if(j <= k){
				cin >> a[i][j];
				all[i].sc += a[i][j];
			}
			else cin >> a[i][k+1];
		}
		repn(j, k) a[i][j] += a[i][j-1];
	}
	vector<ll>vec(k+1, -1e18); vec[0] = 0;
	solve(0, n-1, vec);
	cout << ans << '\n';
}