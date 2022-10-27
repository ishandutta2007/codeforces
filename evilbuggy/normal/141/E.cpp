#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int p[maxn];

int find(int v){
	return (p[v] < 0)?v:(p[v] = find(p[v]));
}

bool combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v){
		return false;
	}
	if(p[u] > p[v])swap(u, v);
	p[u] += p[v]; p[v] = u;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int e; cin >> e;
	vector<array<int, 3> > s;
	vector<array<int, 3> > m;
	for(int i = 0; i < e; i++){
		int u; cin >> u;
		int v; cin >> v;
		char c; cin >> c;
		if(c == 'S'){
			s.push_back({u, v, i});
		}else{
			m.push_back({u, v, i});
		}
	}
	if(n%2 == 0){
		cout << -1 << '\n';
		exit(0);
	}
	{
		memset(p, -1, sizeof(p));
		vector<array<int, 3> > v;
		for(auto x : s){
			if(combine(x[0], x[1]))v.push_back(x);
		}
		s = v;
	}
	{
		memset(p, -1, sizeof(p));
		vector<array<int, 3> > v;
		for(auto x : m){
			if(combine(x[0], x[1]))v.push_back(x);
		}
		m = v;
	}
	int r = (n - 1)/2;
	if(s.size() < r || m.size() < r){
		cout << -1 << '\n';
		exit(0);
	}
	int cnt = 0;
	memset(p, -1, sizeof(p));
	for(auto x : s){
		if(combine(x[0], x[1]))cnt++;
	}
	vector<array<int, 3> > v;
	for(auto x : m){
		if(combine(x[0], x[1])){
			v.push_back(x);
			cnt++;
		}
	}
	if(cnt < n - 1){
		cout << -1 << '\n';
		exit(0);
	}
	memset(p, -1, sizeof(p));
	for(auto x : v){
		assert(combine(x[0], x[1]));
	}
	for(auto x : m){
		if(v.size() == r)break;
		if(combine(x[0], x[1])){
			v.push_back(x);
		}
	}
	assert(v.size() == r);
	for(auto x : s){
		if(combine(x[0], x[1])){
			v.push_back(x);
		}
	}
	assert(v.size() == n - 1);
	cout << n - 1 << '\n';
	for(auto x : v){
		cout << x[2] + 1 << ' ';
	}
	cout << '\n';

	return 0;
}