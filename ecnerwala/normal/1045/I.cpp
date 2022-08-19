#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1.1e5;
int N;
pair<int, int> A[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	long long res = 0;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		int v = 0;
		for (char c : s) {
			v ^= 1 << (c - 'a');
		}
		A[i].first = v;
		A[i].second = 1;
	}
	sort(A, A+N);
	int M = 0;
	for (int j = 0; j < N;) {
		int v = A[j].first;
		int cnt = 0;
		while (j < N && A[j].first == v) {
			res += cnt;
			cnt++;
			j++;
		}
		A[M].first = v;
		A[M].second = cnt;
		M++;
	}
	N = M;
	for (int v = 0; v < 26; v++) {
		for (int i = 0, j = 0; i < N; i++) {
			if (A[i].first & (1 << v)) {
				j = i+1;
				continue;
			}
			int a = A[i].first ^ (1 << v);
			while (j < N && A[j].first < a) j++;
			if (j < N && A[j].first == a) {
				res += ll(A[i].second) * ll(A[j].second);
			}
		}
	}
	cout << res << '\n';
	return 0;
}