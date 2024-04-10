#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int N;
const int MAXV = 200;
int cnt[MAXV];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int R; cin >> R;
		for (int j = 0; j < R; j++) {
			int v; cin >> v;
			cnt[v] ++;
		}
	}
	for (int i = 0; i < MAXV; i++) {
		if (cnt[i] == N) {
			cout << i << ' ';
		}
	}
	cout << '\n';

	return 0;
}