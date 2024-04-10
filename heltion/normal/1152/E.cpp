//Author: Heltion
//Date: 2019-04-24
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120000;
int a[maxn], b[maxn];
void no(){
	cout << -1;
	exit(0);
}
//From HDU
namespace UndirectedGraph{
	const int N = 120000, M = 120000;
	int n, m, i, x, y, d[N], g[N], v[M << 1], w[M << 1], vis[M << 1], nxt[M << 1], ed;
	int ans[M], cnt;
	void add(int x, int y, int z){
		d[x] ++;
		v[++ed]=y;w[ed]=z;nxt[ed]=g[x];g[x]=ed;
	}
	void dfs(int x){
		for(int&i=g[x];i;){
			if(vis[i]){i=nxt[i];continue;}
			vis[i]=vis[i^1]=1;
			int j=w[i];
			dfs(v[i]);
			ans[++cnt]=x;
		}
	}
}
map<int, int> mp, ump;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; i += 1) cin >> a[i];
	for(int i = 1; i < n; i += 1) cin >> b[i];
	for(int i = 1; i < n; i += 1) if(b[i] < a[i]) no();
	for(int i = 1; i < n; i += 1){
		if(not mp.count(a[i])){
			mp[a[i]] = mp.size();
			ump[mp[a[i]]] = a[i];
		}
		if(not mp.count(b[i])){
			mp[b[i]] = mp.size();
			ump[mp[b[i]]] = b[i];
		}
	}
	set<int> s;
	for(int i = 1; i < n; i += 1){
		if(s.count(a[i])) s.erase(a[i]); else s.insert(a[i]);
		if(s.count(b[i])) s.erase(b[i]); else s.insert(b[i]);
	}
	if(s.size() != 2 and s.size() != 0) no();
	UndirectedGraph::ed = 1;
	for(int i = 1; i < n; i += 1){
		UndirectedGraph::add(mp[a[i]], mp[b[i]], i);
		UndirectedGraph::add(mp[b[i]], mp[a[i]], -i);
	}
	if(s.size() == 2){
		UndirectedGraph::add(mp[*s.begin()], mp.size() + 1, n);
		UndirectedGraph::add(mp.size() + 1, mp[*s.begin()], -n);
		UndirectedGraph::add(mp[*s.rbegin()], mp.size() + 1, n + 1);
		UndirectedGraph::add(mp.size() + 1, mp[*s.rbegin()], -n - 1);
	}
	else{
		s.insert(a[1]);
		UndirectedGraph::add(mp[*s.begin()], mp.size() + 1, n);
		UndirectedGraph::add(mp.size() + 1, mp[*s.begin()], -n);
		UndirectedGraph::add(mp[*s.rbegin()], mp.size() + 1, n + 1);
		UndirectedGraph::add(mp.size() + 1, mp[*s.rbegin()], -n - 1);
	}
	
	UndirectedGraph::dfs(mp.size() + 1);
	for(int i = 1; i <= mp.size() + 1; i += 1) if(UndirectedGraph::g[i]) no();
	for(int i = n; i; i -= 1) cout << ump[UndirectedGraph::ans[i]] << " ";
	return 0;
}