#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120000;
constexpr int bsize = sqrt(maxn);
int a[maxn], cnt[maxn], many[maxn], many_n, f[maxn], g[maxn], ans[maxn];
int h[maxn];
priority_queue<int, vector<int>, greater<int> > q;
struct query{
	int l, r, id;
}Q[maxn];
bool operator < (const query &a, const query &b){
	return a.l / bsize != b.l / bsize ? a.l / bsize < b.l / bsize : a.r < b.r;
}
void add(int x){
	f[g[x]] -= 1;
	g[x] += 1;
	f[g[x]] += 1;
}
void del(int x){
	f[g[x]] -= 1;
	g[x] -= 1;
	f[g[x]] += 1;
}
int solve(){
	for(int i = 1; i <= many_n; i += 1) if(g[many[i]] > bsize)
		q.push(g[many[i]]);
	int res = 0, rest = 0;
	for(int i = 1; i <= bsize; i += 1) h[i] = f[i];
	for(int i = 1; i <= bsize; i += 1) if(h[i]){
		if(rest){
			res += i + rest;
			h[i] -= 1;
			if(i + rest <= bsize) h[i + rest] += 1;
			else q.push(i + rest);
			rest = 0;
		}
		if(h[i] & 1){
			rest = i;
			h[i] -= 1;
		}
		res += i * h[i];
		if(i * 2 <= bsize) h[i * 2] += h[i] / 2;
		else for(int j = 0; j < h[i]; j += 2) q.push(i * 2);
	}
	if(rest) q.push(rest);
	while(q.size() > 1){
		int u = q.top();
		q.pop();
		res += u += q.top();
		q.pop();
		q.push(u);
	}
	q.pop();
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		cnt[a[i]] += 1;
		if(cnt[a[i]] == bsize) many[many_n += 1] = a[i];
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i += 1){
		cin >> Q[i].l >> Q[i].r;
		Q[i].id = i;
	}
	sort(Q, Q + q);
	int l = 1, r = 0;
	for(int i = 0; i < q; i += 1){
		while(l > Q[i].l) add(a[-- l]);
		while(r < Q[i].r) add(a[++ r]);
		while(r > Q[i].r) del(a[r --]);
		while(l < Q[i].l) del(a[l ++]);
		ans[Q[i].id] = solve();
	}
	for(int i = 0; i < q; i += 1) cout << ans[i] << "\n";
}