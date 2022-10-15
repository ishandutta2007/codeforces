#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 150013
int N;
int par[MAXN];
int rnk[MAXN];
vector<int> ch[MAXN];

int f(int v) {
	while (par[v] != v)
		v = par[v];
	return v;
}

void preorder(int v) {
	cout << v + 1 << ' ';
	for (int c : ch[v])
		preorder(c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		par[i] = i;
		rnk[i] = 0;
	}

	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		a = f(a), b = f(b);
		assert(a != b);
		if (rnk[a] < rnk[b]) // small-to-large
			swap(a, b);
		if (rnk[a] == rnk[b])
			++rnk[a];
		par[b] = a;
		ch[a].push_back(b);
	}

	preorder(f(0));

	cout << endl;
	return 0;
}