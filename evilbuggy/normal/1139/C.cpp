#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mod = 1000000007;

int p[N];

int find(int v){
	return (p[v] < 0)?v:(p[v] = find(p[v]));
}

void combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v){
		return;
	}
	if(p[u] > p[v]){
		swap(u, v);
	}
	p[u] += p[v];
	p[v] = u;
}

inline int power(int a, int b){
	int ret = 1;
	while(b){
		if(b&1)ret = ret*1LL*a%mod;
		a = a*1LL*a%mod;
		b >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	memset(p, -1, sizeof(p));
	for(int i = 0; i + 1 < n; i++){
		int u, v, x;
		cin >> u >> v >> x;
		if(x == 0)combine(u, v);
	}
	int answer = power(n, k);
	for(int i = 1; i <= n; i++){
		if(find(i) == i){
			answer += mod - power(-p[i], k);
			if(answer >= mod)answer -= mod;
		}
	}
	cout << answer << '\n';

	return 0;
}