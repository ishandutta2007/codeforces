#include <bits/stdc++.h>
using namespace std;

const int K = 26;
int p[K];

int find(int v){
	return (p[v] < 0)?v:(p[v] = find(p[v]));
}

void combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(p[u] > p[v])swap(u, v);
	p[u] += p[v]; p[v] = u;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	string t;
	cin >> t;
	memset(p, -1, sizeof(p));
	for(int i = 0; i < n; i++){
		combine(s[i] - 'a', t[i] - 'a');
	}
	vector<pair<int, int> > ans;
	for(int i = 0; i < K; i++){
		if(find(i) != i){
			ans.emplace_back(i, find(i));
		}
	}
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout << char('a' + x.first) << " " << char('a' + x.second) << '\n';
	}


	return 0;
}