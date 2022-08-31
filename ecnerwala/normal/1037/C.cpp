#include<bits/stdc++.h>
using namespace std;

// operations are swap two adjacent bits, or flip any bit
// swapping adjacent bits only helps if they're opposites and both flip
const int MAXN = 1.1e6;
int N;
char A[MAXN];
char B[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> A >> B;
	bool lastflip = false;
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) {
			if (lastflip && A[i-1] != A[i]) {
				// don't add one
				lastflip = false;
			} else {
				res++;
				lastflip = true; 
			}
		} else {
			lastflip = false;
		}
	}
	cout << res << '\n';

	return 0;
}