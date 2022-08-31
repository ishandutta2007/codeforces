#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;
int N;
char S[MAXN];
int M;

char T[MAXN];

int A[MAXN];

bool vis[MAXN];

void shuffle(int k, int d) {
	int pos = 0;
	for(int i = 0; i < d; i++) {
		for(int v = i; v < k; v += d) {
			A[pos++] = v + 1;
		}
	}
	assert(pos == k);
	for(int i = k; i < N; i++) {
		A[i] = i + 1;
	}
	A[N] = 0; // make it a cycle, we should never reach N

	for(int i = 0, p = 0; i + k < N; i++) {
		p = A[p];
		T[i] = S[p - 1];
	}
	for(int i = 0; i <= N; i++) {
		vis[i] = false;
	}
	int dist = N - k + 1;
	for(int i = 0; i < k; i++) {
		if(vis[i]) continue;
		vector<int> vals;
		vals.push_back(i);
		vis[i] = true;
		for(int cur = A[i]; cur != i; cur = A[cur]) {
			assert(!vis[cur]);
			vis[cur] = true;
			vals.push_back(cur);
		}
		int len = int(vals.size());
		for(int v = 0; v < len; v++) {
			if(vals[v] < k) {
				T[vals[v] + (N - k)] = S[vals[(v + dist) % len] - 1];
			}
		}
	}

	memcpy(S, T, N);
}

int main() {
	scanf("%s", S);
	N = strlen(S);
	scanf("%d", &M);
	for(int q = 0; q < M; q++) {
		int k, d; scanf("%d %d", &k, &d);
		shuffle(k, d);
		printf("%s\n", S);
	}
	return 0;
}