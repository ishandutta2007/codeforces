#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string> > g[100005];

int f[100005][26], lps[100005];
long long int ans = 0;

void build(string &t){
	int n = int(t.size());
	int lps[n];
	lps[0] = 0;
	int i = 1, j = 0;
	while(i < n){
		if(t[i] == t[j]){
			lps[i] = j+1;
			i++;
			j++;
		}else if(j == 0){
			lps[i] = 0;
			i++;
		}else{
			j = lps[j-1];
		}
	}
	memset(f, -1, sizeof(f));
	for(i = 0; i < n; i++){
		f[i][t[i] - 'a'] = i+1;
	}
	for(i = 0; i < 26; i++){
		if(f[0][i] == -1)f[0][i] = 0;
	}
	for(i = 1; i <= n; i++){
		for(j = 0; j < 26; j++){
			if(f[i][j] != -1)continue;
			f[i][j] = f[lps[i-1]][j];
		}
	}
}

void dfs(int v, int s, int fs){
	for(int i = 0; i < g[v].size(); i++){
		int u = g[v][i].first;
		string str = g[v][i].second;
		int ns = s;
		for(int i = 0; i < str.size(); i++){
			ns = f[ns][str[i]-'a'];
			if(ns == fs)ans++;
		}
		dfs(u, ns, fs);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, u;
	string s;
	cin>>n;
	for(int i = 2; i <= n; i++){
		cin>>u>>s;
		g[u].push_back(make_pair(i, s));
	}
	string t;
	cin>>t;
	build(t);
	// for(int i = 0; i <= t.size(); i++){
	// 	for(int j = 0; j < 26; j++){
	// 		cout<<f[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	dfs(1, 0, t.size());
	cout<<ans<<endl;
}