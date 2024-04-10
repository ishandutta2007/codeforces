#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
int L;
int A;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> N >> L >> A;
	int cur = 0;
	int res = 0;
	for (int i = 0; i < N; i++) {
		int t, l; cin >> t >> l;
		res += (t - cur) / A;
		cur = t + l;
	}
	res += (L - cur) / A;
	cout << res << '\n';

	return 0;
}