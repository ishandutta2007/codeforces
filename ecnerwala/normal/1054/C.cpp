#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int N;
int L[MAXN];
int R[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> R[i];
	}
	for (int i = 0; i < N; i++) {
		int cl = 0;
		for (int j = 0; j < i; j++) {
			if (L[j] + R[j] < L[i] + R[i]) {
				cl ++;
			}
		}
		int cr = 0;
		for (int j = i+1; j < N; j++) {
			if (L[j] + R[j] < L[i] + R[i]) {
				cr ++;
			}
		}
		if (cl == L[i] && cr == R[i]) {
			// we're good
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < N; i++) {
		cout << N - (L[i] + R[i]) << ' ';
	}
	cout << '\n';
	return 0;
}