#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N, K;
int first[MAXN];
int last[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		int x; cin >> x;
		if (!first[x]) {
			first[x] = i;
		}
		last[x] = i;
	}
	int res = 0;
	for (int a = 1; a <= N; a++) {
		if (first[a] == 0) {
			res++;
		}
		for (int b = a-1; b <= a+1; b += 2) {
			if (!(1 <= b && b <= N)) continue;
			if (first[a] == 0 || first[b] == 0 || last[b] < first[a]) {
				res++;
			}
		}
	}
	cout << res << '\n';

	return 0;
}