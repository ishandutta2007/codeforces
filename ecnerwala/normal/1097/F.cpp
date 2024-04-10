#include<bits/stdc++.h>
using namespace std;

const int MAXV = 7060;
const int V = 7000;
using bs = bitset<V>;

bool isSquareFree[MAXV];

bs mobs[MAXV];
bs facs[MAXV];

const int MAXN = 1.1e5;
int N;
bs A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= V; i++) {
		isSquareFree[i-1] = true;
	}
	for (int i = 2; i * i <= V; i++) {
		for (int j = i * i; j <= V; j += i * i) {
			isSquareFree[j] = false;
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = i; j <= V; j += i) {
			if (isSquareFree[j / i]) mobs[i-1].set(size_t(j-1));
			facs[j-1].set(size_t(i-1));
		}
	}
	cin >> N;
	int Q;
	cin >> Q;
	string ans;
	for (int q = 0; q < Q; q++) {
		int t; cin >> t;
		if (t == 1) {
			int x, v; cin >> x >> v;
			A[x-1] = facs[v-1];
		} else if (t == 2) {
			int x, y, z; cin >> x >> y >> z;
			A[x-1] = A[y-1] ^ A[z-1];
		} else if (t == 3) {
			int x, y, z; cin >> x >> y >> z;
			A[x-1] = A[y-1] & A[z-1];
		} else if (t == 4) {
			int x, v; cin >> x >> v;
			bool val = (A[x-1] & mobs[v-1]).count() & 1;
			ans += char('0' + val);
		}
	}
	cout << ans << '\n';

	return 0;
}