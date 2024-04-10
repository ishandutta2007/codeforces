#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define MAX 1010101
lld C[MAX], K[MAX];
int main(void) {
	lld T;
	cin >> T;
	while (T-- > 0) {
		lld N, M;
		cin >> N >> M;
		lld i;
		for (i = 1; i <= max(N, M); i++) C[i] = K[i] = 0;
		for (i = 1; i <= N; i++) cin >> K[i];
		for (i = 1; i <= M; i++) cin >> C[i];
		sort(K + 1, K + N + 1);
		lld ptr = 1;
		lld sum = 0;
		for (i = N; i >= 1; i--) {
			if (K[i] < ptr) break;
			else sum += C[ptr++];
		}
		lld a = i;
		for (i = a; i >= 1; i--) sum += C[K[i]];
		cout << sum << endl;
	}
}