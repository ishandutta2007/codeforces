#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
pair<int, int> A[MAXN];

vector<pair<int, int>> edges[MAXN * 2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	int cfirst = 0;
	int csecond = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i].first > A[i].second) {
			cfirst++;
		} else {
			csecond++;
		}
	}
	bool flipped = false;
	if (cfirst < csecond) {
		flipped = true;
		for (int i = 1; i <= N; i++) {
			swap(A[i].first, A[i].second);
		}
		swap(cfirst, csecond);
	}

	vector<pair<int, int>> v;
	for (int i = 1; i <= N; i++) {
		if (A[i].first > A[i].second) {
			v.emplace_back(A[i].first, i);
		}
	}
	sort(v.begin(), v.end());
	if (flipped) reverse(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto it : v) {
		cout << it.second << '\n';
	}

	return 0;
}