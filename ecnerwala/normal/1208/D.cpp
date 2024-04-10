#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2.1e5;
int N;
ll A[MAXN];
ll P[MAXN];

const int S = 1 << 18;
ll seg[2 * S];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		seg[S+i] = i+1;
	}
	for (int i = S-1; i; i--) {
		seg[i] = seg[2*i] + seg[2*i+1];
	}

	for (int i = N-1; i >= 0; i--) {
		ll v = A[i];
		int ind = 1;
		while (ind < S) {
			ind *= 2;
			if (seg[ind] <= v) {
				v -= seg[ind];
				ind ++;
			}
		}
		P[i] = seg[ind];
		for (; ind; ind /= 2) {
			seg[ind] -= P[i];
		}
	}
	for (int i = 0; i < N; i++) {
		cout << P[i] << " \n"[i+1==N];
	}

	return 0;
}