#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e6;
const int MAXQ = 100;

int N;
int Q;

ll A[MAXN];

ll S; // sum

ll B[MAXQ];

int nxt[MAXN];

int vis[MAXN];

int query(ll v) {
	if(v >= S) return 1;

	for(int l = 0, r = 0; l < N; l++) {
		while(v >= A[r]) {
			v -= A[r];
			r++;
		}
		assert(r > l);
		assert(r < l + N);

		nxt[l] = r - l;

		assert(nxt[l] > 0);
		assert(nxt[l] < N);

		v += A[l];
	}

	int res = N;

	memset(vis, 0, sizeof(vis));
	
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		if(vis[i]) continue;

		int st = cnt;
		int cur = i;
		while(!vis[cur]) {
			cnt++;
			vis[cur] = cnt;
			cur += nxt[cur];
			if(cur >= N) cur -= N;
		}

		if(vis[cur] > st) {
			// cur is part of a cycle
			int l = cur;
			int r = cur;

			int d = 0;
			do {
				while(r - l < N) {
					r += nxt[r % N];
					d++;
				}
				res = min(res, d);
				d--;
			} while(l % N != cur);
		}
	}

	assert(cnt == N);

	return res;
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 0; i < N; i++) {
		scanf("%I64d", &A[i]);
		A[i + N] = A[i];
		S += A[i];
	}
	for(int q = 0; q < Q; q++) {
		scanf("%I64d", &B[q]);
	}


	for(int q = 0; q < Q; q++) {
		printf("%d\n", query(B[q]));
	}
	return 0;
}