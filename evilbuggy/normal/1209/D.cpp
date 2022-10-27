#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int x[N], y[N], p[N];

int find(int v){
	return (p[v] < 0)?v:(p[v] = find(p[v]));
}

bool combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return false;
	if(p[u] > p[v])swap(u, v);
	p[u] += p[v]; p[v] = u;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int answer = k;
	memset(p, -1, sizeof(p));
	for(int i = 1; i <= k; i++){
		cin >> x[i] >> y[i];
		if(combine(x[i], y[i]))answer--;
	}
	cout << answer << '\n';

	return 0;
}