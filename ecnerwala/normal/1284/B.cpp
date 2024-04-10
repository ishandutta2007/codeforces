#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;

const int MAXV = 1.1e6;
int maxCnt[MAXV];
int minCnt[MAXV];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int l; cin >> l;
		int first; cin >> first;
		int last = first;
		bool isBad = false;
		for (int j = 1; j < l; j++) {
			int nxt; cin >> nxt;
			if (last < nxt) {
				isBad = true;
			}
			last = nxt;
		}
		if (isBad) continue;

		maxCnt[first] ++;
		minCnt[last] ++;
	}
	long long ans = 0;
	long long v = 0;
	for (int i = 0; i < MAXV; i++) {
		v += maxCnt[i];
		ans += v * minCnt[i];
	}
	cout << 1ll*N*N-ans << '\n';

	return 0;
}