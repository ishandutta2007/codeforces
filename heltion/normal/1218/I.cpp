//Author: Heltion
//Date: 09-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 2400;
char s[maxn];
int a[maxn][maxn], b[maxn];
vector<int> G[maxn << 2];
vector<int> G_[maxn << 2];
stack<int> st;
bool vis[maxn << 2];
int scc[maxn << 2], sccn;
void DFS(int u){
	vis[u] = true;
	for(int v : G[u]) if(not vis[v]) DFS(v);
	st.push(u);
}
void DFS_(int u){
	vis[u] = true;
	scc[u] = sccn;
	for(int v : G_[u]) if(not vis[v]) DFS_(v);;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int N;
	cin >> N;
	for(int i = 0; i < N; i += 1){
		cin >> s;
		for(int j = 0; j < N; j += 1) a[i][j] = s[j] - '0';
	}
	for(int i = 0; i < N; i += 1){
		cin >> s;
		for(int j = 0; j < N; j += 1) a[i][j] ^= s[j] - '0';
	}
	cin >> s;
	for(int i = 0; i < N; i += 1) b[i] = s[i] - '0';
	for(int i = 0; i < N; i += 1)
		for(int j = 0; j < N; j += 1){
			if(a[i][j] == 0){
				if(b[i] == 0) if(b[j] == 1) G[i << 1 | 1].push_back(i << 1);
				if(b[i] == 1){
					if(b[j] == 0) G[(N + j) << 1 | 1].push_back((N + j) << 1);
					if(b[j] == 1){
						G[i << 1 | 1].push_back((N + j) << 1 | 1);
						G[(N + j) << 1 | 1].push_back(i << 1 | 1);
						G[i << 1].push_back((N + j) << 1);
						G[(N + j) << 1].push_back(i << 1);
					}
				}
			}
			if(a[i][j] == 1){
				if(b[i] == 0){
					if(b[j] == 0) no(-1);
					if(b[j] == 1) G[i << 1].push_back(i << 1 | 1);
				}
				if(b[i] == 1){
					if(b[j] == 0) G[(N + j) << 1].push_back((N + j) << 1 | 1);
					if(b[j] == 1){
						G[i << 1 | 1].push_back((N + j) << 1);
						G[(N + j) << 1].push_back(i << 1 | 1);
						G[i << 1].push_back((N + j) << 1 | 1);
						G[(N + j) << 1 | 1].push_back(i << 1);
					}
				}
			}
		}
	for(int i = 0; i < 4 * N; i += 1) for(int j : G[i]) G_[j].push_back(i);
	for(int i = 0; i < 4 * N; i += 1) if(not vis[i]) DFS(i);
	for(fill(vis, vis + 4 * N, false); not st.empty(); st.pop(), sccn += 1)
		if(not vis[st.top()]) DFS_(st.top());
	for(int i = 0; i < 4 * N; i += 2) if(scc[i] == scc[i | 1]) no(-1);
	vector<pair<string, int>> ans;
	for(int i = 0; i < 2 * N; i += 1) if(scc[i << 1 | 1] > scc[i << 1]){
		if(i >= N) ans.push_back({"col", i - N});
		else ans.push_back({"row", i});
	}
	cout << ans.size() << "\n";
	for(auto p : ans) cout << p.first << " " << p.second << "\n";
	return 0;
}