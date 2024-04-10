#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6;
int N;
int R;
int F[MAXN];

int main() {
	scanf("%d %d", &N, &R);
	N = (1 << N);
	ll tot = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &F[i]);
		tot += F[i];
	}
	printf("%.10f\n", double(tot) / N);
	for (int i = 0; i < R; i++) {
		int z, g;
		scanf("%d %d", &z, &g);
		tot -= F[z];
		F[z] = g;
		tot += F[z];
		printf("%.10f\n", double(tot) / N);
	}

	return 0;
}