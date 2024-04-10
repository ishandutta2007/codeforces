#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define repn(i, n) for(int i=1;i<=n;i++)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vector<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}


int n;
vector<int>edge[100005];
int col[100005], ans_max, cnt[100005];
void dfs(int v, int u, int c){
	col[v] = c;
	rep(i, edge[v].size()){
		if(u == edge[v][i]) continue;
		dfs(edge[v][i], v, c^1);
	}
}
void solve(){
	cin >> n;
	rep(i, n-1){
		int a, b; cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
		cnt[a] ++;
		cnt[b] ++;
	}
	dfs(1, -1, 0);
	bool ex[2] = {};
	repn(i, n){
		if(cnt[i] != 1) continue;
		ex[col[i]] = true;
	}
	if(ex[0] && ex[1]) cout << 3 << " ";
	else cout << 1 << " ";
	
	repn(i, n){
		if(cnt[i] == 1) continue;
		bool con = 0;
		for(auto at:edge[i]){
			if(cnt[at] == 1) con = 1;
			if(i <= at && cnt[at] >= 2) ans_max ++;
		}
		if(con) ans_max ++;
	}
	cout << ans_max << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	solve();
}