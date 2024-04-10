//Author: Heltion
//Date: 2019-05-15
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 540000;
vector<int> G[maxn];
bool vis[maxn];
int ans[maxn];
stack<int> s;
void DFS(int u){
	vis[u] = true;
	s.push(u);
	for(int v : G[u]) if(not vis[v]) DFS(v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1, k, last, cur; i <= m; i += 1){
		cin >> k;
		for(int j = 0; j < k; j += 1){
			cin >> cur;
			if(j){
				G[last].push_back(cur);
				G[cur].push_back(last);
			}
			last = cur;
		}
	}
	for(int i = 1; i <= n; i += 1) if(not vis[i]) {
		DFS(i);
		for(int sz = s.size(); not s.empty(); s.pop())
			ans[s.top()] = sz;
	}
	for(int i = 1; i <= n; i += 1) cout << ans[i] << " ";
	return 0;
}