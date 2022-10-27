#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
vector<int> g[N];
int d[N];

int dfs(int v, int p, int __d = 0){
	d[v] = __d;
	int ret = 0;
	int lcnt = 0;
	for(auto u : g[v]){
		if(u != p){
			ret += dfs(u, v, __d + 1);
			if(g[u].size() > 1)ret++;
			else lcnt++;
		}
	}
	if(lcnt)ret++;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	int u, v;
	for(int i = 1; i < n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = -1;
	for(int i = 1; i <= n; i++){
		if(g[i].size() > 1){
			root = i;
			break;
		}
	}
	int mx = dfs(root, -1);
	set<int> st;
	for(int i = 1; i <= n; i++){
		if(g[i].size() == 1)st.insert(d[i]&1);
	}
	if(st.size() > 1)cout<<3;
	else cout<<1;
	cout<<" "<<mx<<endl;

	return 0;
}