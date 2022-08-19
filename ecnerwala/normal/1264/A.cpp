#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int N;
int P[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		int g = 1;
		while (g <= N && P[g-1] == P[g]) g++;
		int s = 2 * g + 1;
		while (s <= N && P[s-1] == P[s]) s++;
		int b = s + g + 1;
		while (b <= N && P[b-1] == P[b]) b++;
		if (b * 2 > N) {
			cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
		} else {
			for (int i = b; i <= N / 2; i++) {
				if (P[i-1] != P[i]) b = i;
			}
			cout << g << ' ' << s - g << ' ' << b - s << '\n';
		}
	}

	return 0;
}