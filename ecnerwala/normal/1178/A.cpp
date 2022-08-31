#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	int tot = A[0];
	int good = A[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		tot += A[i];
		if (A[0] >= A[i] * 2) {
			good += A[i];
			cnt++;
		}
	}
	if (good > tot - good) {
		cout << cnt << '\n';
		cout << 1;
		for (int i = 1; i < N; i++) {
			if (A[0] >= A[i] * 2) {
				cout << ' ' << i+1;
			}
		}
		cout << '\n';
	} else {
		cout << 0 << '\n';
	}


	return 0;
}