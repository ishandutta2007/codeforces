#include <bits/stdc++.h>
using namespace std;

long long h[3010][3010];
int n, m;

int main(){
	int a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
	int g, x, y, z; scanf("%d%d%d%d", &g, &x, &y, &z);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			h[i][j] = g;
			g = (1ll * g * x + y) % z;
		}
	}
	for (int i = 1; i <= n; i++){
		deque <int> q;
		for (int j = 1; j <= b; j++){
			while (q.size() && q.back() > h[i][j]) q.pop_back();
			q.push_back(h[i][j]);
		}
		int last = h[i][1];
		h[i][1] = q.front();
		for (int j = 2; j <= m - b + 1; j++){
			if (q.front() == last) q.pop_front();
			while (q.size() && q.back() > h[i][j + b - 1]) q.pop_back();
			q.push_back(h[i][j + b - 1]);
			last = h[i][j], h[i][j] = q.front();
		}
	}
	long long ans = 0;
	for (int j = 1; j <= m - b + 1; j++){
		deque <int> q;
		for (int i = 1; i <= a; i++){
			while (q.size() && q.back() > h[i][j]) q.pop_back();
			q.push_back(h[i][j]);
		}
		ans += q.front();
		for (int i = 2; i <= n - a + 1; i++){
			if (q.front() == h[i - 1][j]) q.pop_front();
			while (q.size() && q.back() > h[i + a - 1][j]) q.pop_back();
			q.push_back(h[i + a - 1][j]);
			ans += q.front();
		}
	}
	printf("%I64d\n", ans);
	return 0;
}