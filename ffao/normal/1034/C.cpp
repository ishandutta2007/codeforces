#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;

const int mod = 1000000007;

int n;
int vv[1100000];

vector<int> g[1100000];
int can[1100000];
int cnt[1100000];
unsigned long long has[1100000];

void dfs(int v, int p) {
	has[v] = vv[v];
	for (int x : g[v]) if (x != p) {
		dfs(x,v);
		has[v] += has[x];
	}
}

ull gcd(ull a, ull b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	scanf("%d", &n);

	ull tot = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &vv[i]);
		tot += vv[i];
	}

	for (int i = 0; i < n-1; i++) {
		int p;
		scanf("%d", &p); p--;
		g[p].push_back(i+1);
	}

	dfs(0,-1);
	for (int i = 0; i < n; i++) {
		ull d = tot / gcd(tot, has[i]);
		if (d <= n) cnt[d]++;
	}

	for (int i = n; i >= 1; i--) {
		for (int j = i+i; j <= n; j+=i) cnt[j] += cnt[i];
	}

	for (int i = n; i >= 1; i--) {
		can[i] = (cnt[i] == i);
	}

	for (int i = n; i >= 1; i--) {
		int ot = 1;
		for (int j = i+i; j <= n; j+=i) {
			ot += can[j];
			if (ot >= mod) ot -= mod;
		}
		can[i] = (can[i] * 1ll * ot) % mod; 
	}

	printf("%d\n", can[1]);
}