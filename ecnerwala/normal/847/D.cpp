#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int N;
int L;
int T[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> L;
	vector<int> vals;
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		t = max(i+1, t);
		if (L > t) {
			// we eat this if he ends between i and (L-t) + i (inclusive)
			T[i] ++;
			if ((L-t)+i <= N) T[(L-t) + i] --;
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, T[i]);
		T[i+1] += T[i];
	}
	cout << res << '\n';

	return 0;
}