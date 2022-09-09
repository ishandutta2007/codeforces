#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 720000;
int x[maxn], y[maxn], dx[maxn], dy[maxn], mx, my;
LL ans[maxn];
vector<pair<int, int> > v[maxn * 2], back[maxn * 2];
int par[maxn], numx[maxn], numy[maxn];
map<pair<int, int>, int> mp;
int getpar(int u){
	return par[u] == u ? u : getpar(par[u]);
}
LL pans;
void DFS(int o, int l, int r){
	for(auto p : v[o]){
		int x = p.first, y = p.second;
		x = getpar(x), y = getpar(y);
		if(x == y) continue;
		if(numx[x] + numy[x] > numx[y] + numy[y]) swap(x, y);
		//cout << o << " " << x << " " << y << endl;
		pans -= 1LL * numx[x] * numy[x] + 1LL * numx[y] * numy[y];
		par[x] = y;
		numx[y] += numx[x];
		numy[y] += numy[x];
		pans += 1LL * numx[y] * numy[y];
		back[o].push_back(make_pair(x, y));
	}
	if(l == r) ans[l] = pans;
	else{
		int m = (l + r) >> 1;
		DFS(o * 2, l, m);
		DFS(o * 2 + 1, m + 1, r);
		
	}
	reverse(back[o].begin(), back[o].end());
	for(auto p : back[o]){
		int x = p.first, y = p.second;
		pans -= 1LL * numx[y] * numy[y];
		numx[y] -= numx[x];
		numy[y] -= numy[x];
		par[x] = x;
		pans += 1LL * numx[x] * numy[x] + 1LL * numx[y] * numy[y];
	}
}
void add(int o, int l, int r, int L, int R, pair<int, int> p){
	if(l >= L and r <= R) v[o].push_back(p);
	else {
		int m = (l + r) >> 1;
		if(L <= m) add(o * 2, l, m, L, R, p);
		if(R > m) add(o * 2 + 1, m + 1, r, L, R, p);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> x[i] >> y[i];
		dx[i] = x[i];
		dy[i] = y[i];
	}
	sort(dx + 1, dx + n + 1);
	sort(dy + 1, dy + n + 1);
	mx = unique(dx + 1, dx + n + 1) - dx - 1,
	my = unique(dy + 1, dy + n + 1) - dy - 1;
	for(int i = 1; i <= mx + my; i += 1){
		par[i] = i;
		if(i <= mx) numx[i] += 1;
		else numy[i] += 1;
	}
	for(int i = 1; i <= n; i += 1){
		pair<int, int> p = make_pair(
			lower_bound(dx + 1, dx + mx + 1, x[i]) - dx,
			lower_bound(dy + 1, dy + my + 1, y[i]) - dy + mx);
		//cout << "?" << p.first << " " << p.second << endl;
		if(mp.count(p)){
			add(1, 1, n, mp[p], i - 1, p);
			mp.erase(p);
		}
		else mp[p] = i;
	}
	for(auto pp : mp) add(1, 1, n, pp.second, n, pp.first);
	DFS(1, 1, n);
	for(int i = 1; i <= n; i += 1) cout << ans[i] << " ";
}