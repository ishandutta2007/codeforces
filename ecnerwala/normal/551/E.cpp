#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6;
const int MAXB = 1000;

const int S = 600;
int B;

int N;
ll A[MAXN];
ll V[MAXB];
ll vals[MAXN];
int L[MAXB];
int R[MAXB];

void fill_bucket(int b) {
	memcpy(vals + L[b], A + L[b], sizeof(A[0]) * (R[b] - L[b]));
	sort(vals + L[b], vals + R[b]);
}

int Q;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> Q;
	B = (N + S - 1) / S;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		vals[i] = A[i];
	}
	for(int i = 0; i < B; i++) {
		L[i] = i * S;
		R[i] = min((i + 1) * S, N);
		if(i) assert(L[i] == R[i - 1]);
		sort(vals + L[i], vals + R[i]);
	}

	for(int q = 0; q < Q; q++) {
		int t; cin >> t;
		if(t == 1) {
			int l, r; ll x;
			cin >> l >> r >> x;
			l--, r--;
			assert(l <= r);
			assert(0 <= l && l < N);
			assert(0 <= r && r < N);
			int bl = l / S;
			int br = r / S;
			assert(0 <= bl && bl < B);
			assert(0 <= br && br < B);
			assert(bl <= br);
			assert(L[bl] <= l && l < R[bl]);
			assert(L[br] <= r && r < R[br]);
			if(bl == br) {
				for(int i = l; i <= r; i++) {
					A[i] += x;
				}
				fill_bucket(bl);
				continue;
			}
			for(int i = l; i < R[bl]; i++) {
				A[i] += x;
			}
			fill_bucket(bl);
			for(int i = L[br]; i <= r; i++) {
				A[i] += x;
			}
			fill_bucket(br);
			for(int i = bl + 1; i < br; i++) {
				V[i] += x;
			}
		} else if(t == 2) {
			ll v; cin >> v;
			int l = -1;
			int r = -1;
			for(int b = 0; b < B; b++) {
				if(binary_search(vals + L[b], vals + R[b], v - V[b])) {
					for(int i = L[b]; i < R[b]; i++) {
						if(A[i] + V[b] == v) {
							l = i;
							break;
						}
					}
					break;
				}
			}
			for(int b = B - 1; b >= 0; b--) {
				if(binary_search(vals + L[b], vals + R[b], v - V[b])) {
					for(int i = R[b] - 1; i >= L[b]; i--) {
						if(A[i] + V[b] == v) {
							r = i;
							break;
						}
					}
					break;
				}
			}
			if(l == -1) {
				cout << -1 << '\n';
			} else {
				cout << r - l << '\n';
			}
		} else assert(false);
	}

	return 0;
}