#include "bits/stdc++.h"
using namespace std;

#define ar array
#define int long long

const int N = 3e5 + 5;
int l[N], r[N], a[N], p[N];
int res[N];
vector<int> qq[N], rx[N];

struct ST{
	int tree[N << 2];
	void sett(int i, int v, int lx = 0, int rx = N, int x = 1){
		if(lx == rx) { tree[x] = min(tree[x], v); return; }
		int m = (lx + rx) >> 1;
		if(i <= m) sett(i, v, lx, m, x<<1);
		else sett(i, v, m+1, rx, x<<1|1);
		tree[x] = min(tree[x<<1], tree[x<<1|1]);
	}
	
	int get(int l, int r, int lx = 0, int rx = N, int x = 1){
		if(lx > r || rx < l) return 4e18;
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) >> 1;
		return min(get(l, r, lx, m, x<<1), get(l, r, m+1, rx, x<<1|1));
	}
}tree;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, q; cin>>n>>q;
	vector<int> ss;
	for(int i=0;i<n;i++) cin>>p[i]>>a[i];
	
	for(int i=0;i<n;i++){
		while(!ss.empty() && a[ss.back()] >= a[i]){
			if(a[ss.back()] == a[i]) rx[ss.back()].push_back(i);
			ss.pop_back();
		}
		
		if(!ss.empty()) rx[ss.back()].push_back(i);
		ss.push_back(i);
	}
	
	ss.clear();
	for(int i=n-1;~i;i--){
		while(!ss.empty() && a[ss.back()] >= a[i]){
			if(a[ss.back()] == a[i]) rx[i].push_back(ss.back());
			ss.pop_back();
		}
		
		if(!ss.empty()) rx[i].push_back(ss.back());
		ss.push_back(i);
	}
	
	for(int j=0;j<q;j++){
		cin>>l[j]>>r[j];
		qq[--l[j]].push_back(j);
	}
	
	auto get = [&](int i, int j){
		return abs(p[i] - p[j]) * (a[i] + a[j]);
	};
	memset(tree.tree, 127, sizeof tree.tree);
	
	for(int i=n-1;~i;i--){
		for(auto j : rx[i]){
			tree.sett(j, get(i, j));
		}
		
		for(auto j : qq[i]){
			res[j] = tree.get(i, --r[j]);
		}
	}
	
	for(int i=0;i<q;i++) cout<<res[i]<<"\n";
}