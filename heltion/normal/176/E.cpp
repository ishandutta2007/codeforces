#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int maxn = 120000;
vector<PII> G[maxn];
int par[17][maxn], stamp[maxn], depth[maxn], dfs_time;
LL sum[17][maxn];
struct cmp{
	bool operator ()(const int &a, const int &b){
		return stamp[a] < stamp[b];
	}
};
set<int, cmp> s;
void DFS(int u){
	depth[u] = depth[par[0][u]] + 1;
	stamp[u] = dfs_time += 1;
	for(int i = 1; i < 17; i += 1){
		par[i][u] = par[i - 1][par[i - 1][u]];
		sum[i][u] = sum[i - 1][u] + sum[i - 1][par[i - 1][u]];
	}
	for(const PII &p : G[u]) if(p.first != par[0][u]){
		par[0][p.first] = u;
		sum[0][p.first] = p.second;
		DFS(p.first);
	}
}
LL path(int u, int v){
	LL res = 0;
	if(depth[u] < depth[v]) swap(u, v);
	for(int i = 16; ~i; i -= 1)
		if(depth[par[i][u]] >= depth[v]){
			res += sum[i][u];
			u = par[i][u];
		} 
	if(u == v) return res;
	for(int i = 16; ~i; i -= 1)
		if(par[i][u] != par[i][v]){
			res += sum[i][u];
			res += sum[i][v];
			u = par[i][u];
			v = par[i][v];
		}
	return res + sum[0][u] + sum[0][v];
	
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i += 1){
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}
	DFS(1);
	LL ans = 0;
	int q;
	cin >> q;
	while(q --){ 
		char op[2];
		cin >> op;
		if(*op == '+'){
			int x, L, R;
			cin >> x;
			auto it = s.insert(x).first;
			if(it == s.begin()) L = *s.rbegin();
			else{
				L = *--it;
				it++;
			}
			if(*it == *s.rbegin()) R = *s.begin();
			else R = *++it;
			ans += path(L, x) + path(x, R) - path(L, R);
		}
		else if(*op == '-'){
			int x, L, R;
			cin >> x;
			auto it = s.find(x);
			if(it == s.begin()) L = *s.rbegin();
			else{
				L = *--it;
				it++;
			}
			if(*it == *s.rbegin()) R = *s.begin();
			else{
				R = *++it;
				it--;
			}
			ans -= path(L, x) + path(x, R) - path(L, R);
			s.erase(it);
		}
		else cout << ans / 2 << "\n";
	}
}