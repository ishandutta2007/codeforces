#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int P[MAXN];
int L[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> P[i];
	}
	for (int i = N; i >= 1; i--) {
		if (L[i] == 0) {
			L[i] = 1;
		}
		if (i > 1) {
			L[P[i]] += L[i];
		}
	}
	sort(L+1, L+1 + N);
	for (int i = 1; i <= N; i++) {
		cout << L[i] << " \n"[i==N];
	}

	return 0;
}