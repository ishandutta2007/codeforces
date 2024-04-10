#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6;
char A[MAXN];
char B[MAXN];

int pref[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> A >> B;
	int N = int(strlen(A));
	pref[0] = 0;
	for (int i = 0; i < N; i++) {
		pref[i+1] = pref[i] ^ (A[i] - '0');
	}
	int M = int(strlen(B));
	int b = 0;
	for (int i = 0; i < M; i++) b ^= (B[i] - '0');
	int ans = 0;
	for (int i = 0; i+M <= N; i++) {
		ans += ((pref[i] ^ pref[i+M] ^ b) == 0);
	}
	cout << ans << '\n';

	return 0;
}