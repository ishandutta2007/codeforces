#include<bits/stdc++.h>
using namespace std;

int N;
int A[7];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < 7; j++) {
			A[j] += s[j] - '0';
		}
	}
	int res = 0;
	for (int i = 0; i < 7; i++) { res = max(res, A[i]); }
	cout << res << '\n';

	return 0;
}