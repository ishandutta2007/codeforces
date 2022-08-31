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
#define a first
#define b second
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
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
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
int col[300005];
vector<int>edge[300005];

void solve(){
	cin >> n >> m;
	repn(i, n) edge[i].clear();
	rep(i, m){
		int a, b; cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	queue<int>que;
	que.push(1);
	repn(i, n) col[i] = -1;
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(col[q] != -1) continue;
		col[q] = 1;
		
		for(const auto at:edge[q]){
			assert(col[at] != 1);
			if(col[at] == -1){
				col[at] = 0;
				for(const auto at2:edge[at]){
					que.push(at2);
				}
			}
		}
	}
	repn(i, n) if(col[i] == -1){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	{
		vc<int>ans;
		repn(i, n) if(col[i] == 1) ans.pb(i);
		cout << ans.size() << '\n';
		for(auto at:ans) cout << at << " ";
		cout << '\n';
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}