#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;

template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}

#define sz 205
int par[sz],ran[sz];
void init(){ for(int i=0;i<sz;i++) par[i] = i, ran[i] = 0; }
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
void solve(){
	int n; cin >> n;
	init();
	vc<int>rp(n+1), p(n+1);
	repn(i, n){
		int x;
		cin >> x;
		rp[x] = i;
		p[i] = x;
		unite(i, x);
	}
	vc<vc<int>>L;
	repn(i, n){
		if(find(i) != i) continue;
		vc<int>mem;
		repn(j, n){
			if(find(j) == i) mem.pb(j);
		}
		L.pb(mem);
	}
	auto feasible = [&](vc<P>ed){
		vc<int>slf(n+1, 0);
		rep(i, ed.size()) if(ed[i].a == ed[i].b) slf[ed[i].a] = 1;
		rep(i, ed.size()){
			if(ed[i].a != ed[i].b){
				int mn = min(ed[i].a, ed[i].b);
				int mx = max(ed[i].a, ed[i].b);
				for(int j=mn;j<=mx;j++){
					if(slf[j]) return false;
				}
			}
		}
		rep(i, ed.size()) rep(j, i){
			if(ed[i].a < ed[i].b and ed[j].a < ed[j].b){
				int mn = max(ed[i].a, ed[j].a);
				int mx = min(ed[i].b, ed[j].b);
				if(mn < mx) return false;
			}
			else if(ed[i].a > ed[i].b and ed[j].a > ed[j].b){
				int mn = max(ed[i].b, ed[j].b);
				int mx = min(ed[i].a, ed[j].a);
				if(mn < mx) return false;
			}
			else if(ed[i].a != ed[i].b and ed[j].a != ed[j].b){
				int mn = max(min(ed[i].a, ed[i].b), min(ed[j].a, ed[j].b));
				int mx = min(max(ed[i].a, ed[i].b), max(ed[j].a, ed[j].b));
				if(mn+1 < mx) return false;
			}
		}
		init();
		repn(i, n) unite(i, p[i]);
		vc<int>ex(n+1, 0);
		rep(i, ed.size()){
			int mn = min(ed[i].a, ed[i].b);
			int mx = max(ed[i].a, ed[i].b);
			for(int j=mn;j<mx;j++) ex[j] = 1;
		}
		repn(i, n-1) if(ex[i]){
			if(same(i, i+1)) return false;
			unite(i, i+1);
		}
		
		init();
		repn(i, n) unite(i, p[i]);
		vc<int>cntL(n+1, 0), cntR(n+1, 0);
		rep(i, ed.size()){
			int mn = min(ed[i].a, ed[i].b);
			int mx = max(ed[i].a, ed[i].b);
			if(mn < mx){
				cntL[mn] ++;
				cntR[mx] ++;
			}
		}
		repn(i, n-1) if(!slf[i] and !slf[i+1]){
			if(cntR[i] == 2 or cntL[i+1] == 2) continue;
			unite(i, i+1);
		}
		repn(i, n) if(!same(1, i)) return false;
		return true;
	};
	int zan = 1;
	vc<int>ans(1, 1);
	vc<int>rem;
	for(int i=2;i<=n;i++) rem.pb(i);
	
	vc<P>ed;
	rep(_, n-1){
		for(auto a:rem){
			//zan -> p[a]
			ed.eb(zan, p[a]);
			if(feasible(ed)){
				zan = a;
				ans.pb(a);
				vc<int>nw_rem;
				for(auto b:rem) if(a != b) nw_rem.pb(b);
				swap(rem, nw_rem);
				goto nxt;
			}
			else ed.pop_back();
		}
		assert(false);
		nxt:;
	}
	rep(i, ans.size()) cout << ans[i] << (i+1==ans.size()?'\n':' ');
}
int main(){
	int t; cin >> t;
	while(t--) solve();
}