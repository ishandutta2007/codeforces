	#include<bits/stdc++.h>
	using namespace std;

	typedef long long ll;
	typedef pair<int, int> ii;
	typedef vector<int> vi;
	typedef vector<ii> vii;

	const int ms = (1<<20) + 1;
	const int inf = 0x3f3f3f3f;

	int par[ms];
	int impar[ms];

	int main() {
		cin.tie(0); ios::sync_with_stdio(0);
		int n;
		scanf("%d", &n);
		int cur = 0;
		long long ans = 0;
		par[0] = 1;
		for(int i = 0; i < n; i++) {
			int *a = (i & 1) ? par : impar;
			int x;
			scanf("%d", &x);
			cur ^= x;
			ans += a[cur]++;
		}
		printf("%lld\n", ans);
	}