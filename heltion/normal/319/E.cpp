#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 1;
int op[maxn], a[maxn], b[maxn], x[maxn << 3];
vector<int> tag[maxn << 5];
int par[maxn], ll[maxn], rr[maxn];
int getpar(int u){
	return par[u] == u ? u : par[u] = getpar(par[u]);
}
void insert(int o, int l, int r, int p, int y){
	for(int x : tag[o]){
		x = getpar(x);
		ll[y] = min(ll[y], ll[x]);
		rr[y] = max(rr[y], rr[x]);
		par[x] = y;
	}
	tag[o].clear();
	if(l < r){
		int m = (l + r) >> 1;
		if(p <= m) insert(o * 2, l, m, p, y);
		else insert(o * 2 + 1, m + 1, r, p, y);
	}
}
void update(int o, int l, int r, int L, int R, int y){
	//cout << o << " " << x[l] << " " << x[r] << " " << x[L] << " " << x[R] << endl;
	if(L > R) return;
	if(l >= L and r <= R) tag[o].push_back(y);
	else{
		int m = (l + r) >> 1;
		if(L <= m) update(o * 2, l, m, L, R, y);
		if(R > m) update(o * 2 + 1, m + 1, r, L, R, y);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n, m = 0, t = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> op[i] >> a[i] >> b[i];
		if(op[i] == 1){
			x[m += 1] = a[i];
			x[m += 1] = a[i] + 1;
			x[m += 1] = a[i] - 1;
			x[m += 1] = b[i];
			x[m += 1] = b[i] + 1;
			x[m += 1] = b[i] - 1;
		}
	}
	sort(x + 1, x + m + 1);
	m = unique(x + 1, x + m + 1) - x - 1;
	for(int i = 1; i <= n; i += 1) if(op[i] == 1){
		
	}
	for(int i = 1; i <= n; i += 1){
		if(op[i] == 1){
			t += 1;
			ll[t] = lower_bound(x + 1, x + m + 1, a[i]) - x;
			rr[t] = lower_bound(x + 1, x + m + 1, b[i]) - x;
			par[t] = t;
			int aa = ll[t], bb = rr[t];
			insert(1, 1, m, aa, t);
			insert(1, 1, m, bb, t);
			update(1, 1, m, ll[t] + 1, rr[t] - 1, t);
		}
		else{
			b[i] = getpar(b[i]);
			if(getpar(a[i]) == b[i])
				cout << "YES\n";
			else if(ll[a[i]] > ll[b[i]] and ll[a[i]] < rr[b[i]])
				cout << "YES\n";
			else if(rr[a[i]] > ll[b[i]] and rr[a[i]] < rr[b[i]])
				cout << "YES\n";
			else cout << "NO\n";	
		}
		//for(int i = 1; i <= n; i += 1) cout << i << " " << par[i] << endl;
	}
}