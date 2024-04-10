#include<bits/stdc++.h>
using namespace std;

const int MAXN = 800;
int N;
int A[MAXN];
bitset<MAXN> l[MAXN], r[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) l[i][i] = r[i][i] = true;
	for (int z = 0; z < 3; z++) { // I don't think this is correct
		for (int d = 1; d < N; d++) {
			for (int i = 0, j = d; j < N; i++, j++) {
				if (__gcd(A[i], A[j]) == 1) continue;
				if (l[j][i+1]) r[i] |= r[j];
				if (r[i][j-1]) l[j] |= l[i];
			}
		}
	}
	bool good = false;
	for (int i = 0; i < N; i++) if (l[i][0] && r[i][N-1]) good = true;
	cout << (good ? "Yes" : "No") << '\n';
	return 0;
}