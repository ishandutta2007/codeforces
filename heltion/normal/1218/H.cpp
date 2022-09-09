//Author: Heltion
//Date: 09-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
bool vis[maxn], inc[maxn], ins[maxn];
int A[maxn], ans[maxn], st[maxn], cn;
vector<int> c[maxn], G[maxn];
vector<pair<LL, int>> q[maxn];
vector<int> dn[maxn];
void DFS(int rt, int u, int d){
	if(d >= (int)dn[rt].size()) dn[rt].resize(d + 1);
	dn[rt][d] += 1; 
	if(u != rt) for(auto p : q[u]) if(d + p.first < (int)dn[rt].size())
		ans[p.second] -= dn[rt][d + p.first];
	for(int v : G[u]) if(not inc[v]) DFS(rt, v, d + 1);
	if(u != rt) for(auto p : q[u]) if(d + p.first < (int)dn[rt].size())
		ans[p.second] += dn[rt][d + p.first];
}
vector<int> BIT[maxn];
void add(vector<int> &v, LL p, int x){
	for(; p < (int)v.size(); p += p & -p) v[p] += x;
}
int sum(vector<int> &v, LL p){
	int res = 0;
	for(p = min(p, (LL)v.size() - 1); p; p -= p & -p) res += v[p];
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> A[i];
		G[A[i]].push_back(i);
	}
	int Q;
	cin >> Q;
	for(int i = 1, y; i <= Q; i += 1){
		LL m;
		cin >> m >> y;
		q[y].push_back({m, i});
	}
	for(int i = 1; i <= n; i += 1) if(not vis[i]){
		int stn = 0;
		for(int p = i; not vis[p]; p = A[p]){
			st[stn += 1] = p;
			ins[p] = true;
			vis[p] = true;
			if(ins[A[p]]){
				cn += 1;
				for(int j = 1, ok = 0; j <= stn; j += 1){
					if(st[j] == A[p]) ok = 1;
					if(ok){
						c[cn].push_back(st[j]);
						inc[st[j]] = true;
					}
				}
				break;
			}
		}
		for(int i = 1; i <= stn; i += 1) ins[st[i]] = false;
	}
	for(int i = 1; i <= n; i += 1) if(inc[i]) DFS(i, i, 0);
	for(int i = 1; i <= cn; i += 1){
		int sz = 0, B = c[i].size();
		for(int u : c[i]) sz = max(sz, (int)dn[u].size());
		sz = sz / c[i].size() + 5;
		for(int j = 0; j < (int)c[i].size(); j += 1){
			BIT[j].resize(sz);
			fill(BIT[j].begin(), BIT[j].end(), 0);
		}
		for(int u : c[i]){
			for(int j = 0; j < (int)dn[u].size(); j += 1)
				add(BIT[(B + j) % c[i].size()], (B + j) / c[i].size() + 1, dn[u][j]);
			for(auto p : q[u])
				ans[p.second] += sum(BIT[(B + p.first) % c[i].size()], (B + p.first) / c[i].size() + 1);
			B -= 1;
		}
		for(int j = 0; j < (int)c[i].size(); j += 1) fill(BIT[j].begin(), BIT[j].end(), 0);
		B = 1;
		for(int x = c[i].size() - 1; ~x; x -= 1){
			int u = c[i][x];
			for(auto p : q[u])
				ans[p.second] += sum(BIT[(B + p.first) % c[i].size()], (B + p.first) / c[i].size() + 1);
			for(int j = 0; j < (int)dn[u].size(); j += 1)
				add(BIT[(B + j) % c[i].size()], (B + j) / c[i].size() + 2, dn[u][j]);
			B += 1;
		}
	}
	for(int i = 1; i <= Q; i += 1) cout << ans[i] << "\n";
	return 0;
}