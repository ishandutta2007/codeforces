#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
LL sum[maxn];
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i += 1)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i += 1) 
			sum[i] = sum[i - 1] + a[i];
		set<LL> s;
		function<void(int, int)> DFS = [&](int L, int R){
			s.insert(sum[R] - sum[L - 1]);
			if(a[L] == a[R]) return;
			int M = upper_bound(a + L, a + R + 1, (a[L] + a[R]) / 2) - a;
			DFS(L, M - 1);
			DFS(M, R);
		};
		DFS(1, n);
		for(int i = 1, q; i <= m; i += 1){
			cin >> q;
			cout << (s.count(q) ? "Yes\n" : "No\n");
		}
	}
	return 0;
}