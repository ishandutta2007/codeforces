#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const int MAXN = 2e5;

int N;
int A[MAXN];
ll V[MAXN];

const int S = 1 << 19;
pii seg[2 * S]; // makes max queries

// inclusive
pii query(int a, int b) {
	assert(a <= b);
	pii res = seg[S + a];
	for(a += S, b += S; a <= b; a /= 2, b /= 2) {
		if(a % 2 == 1) {
			res = max(res, seg[a]);
			a++;
		}
		if(b % 2 == 0) {
			res = max(res, seg[b]);
			b--;
		}
	}
	return res;
}

int main() {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		if(i < N) cin >> A[i];
		else A[i] = i + 1;
		seg[S + i] = pii(A[i], i);
	}
	for(int i = S - 1; i > 0; i--) {
		seg[i] = max(seg[2 * i], seg[2 * i + 1]);
	}

	V[N] = 0;
	for(int i = N - 1; i >= 1; i--) {
		int nxt = query(i + 1, A[i]).second;
		assert(A[nxt] > A[i]);
		V[i] = (N - i) + (V[nxt] - (A[i] - nxt));
	}

	ll res = 0;
	for(int i = 1; i <= N; i++) {
		res += V[i];
	}
	cout << res << '\n';
	return 0;
}