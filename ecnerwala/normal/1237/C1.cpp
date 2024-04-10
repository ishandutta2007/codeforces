#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
struct pt {
	int x, y, z, i;
} P[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i].x >> P[i].y >> P[i].z;
		P[i].i = i;
	}
	sort(P, P + N, [](pt i, pt j) {
		return tie(i.x, i.y, i.z, i.i) < tie(j.x, j.y, j.z, j.i);
	});

	while (N > 0) {
		assert(N % 2 == 0);
		int cur = N-2;
		if (P[cur].x != P[cur+1].x && cur >= 1 && P[cur-1].x == P[cur].x) {
			cur--;
		}
		if (P[cur].x == P[cur+1].x) {
			if (P[cur].y != P[cur+1].y && cur >= 1 && P[cur-1].y == P[cur].y) {
				cur--;
			}
			if (P[cur].y == P[cur+1].y) {
				if (P[cur].z != P[cur+1].z && cur >= 1 && P[cur-1].z == P[cur].z) {
					cur--;
				}
			}
		}
		cout << P[cur].i+1 << ' ' << P[cur+1].i+1 << '\n';
		for (int i = cur; i+2 < N; i++) {
			P[i] = P[i+2];
		}
		N -= 2;
	}

	return 0;
}