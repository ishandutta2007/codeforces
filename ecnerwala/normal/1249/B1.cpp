#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500;
int N;
int P[MAXN];
int ans[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> P[i]; P[i] --;
			ans[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			if (ans[i]) continue;
			ans[i] = 1;
			for (int cur = P[i]; cur != i; cur = P[cur]) ans[i]++;
			for (int cur = P[i]; cur != i; cur = P[cur]) ans[cur] = ans[i];
		}
		for (int i = 0; i < N; i++) {
			cout << ans[i] << " \n"[i+1==N];
		}
	}

	return 0;
}