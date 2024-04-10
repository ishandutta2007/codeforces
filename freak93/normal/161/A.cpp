#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int N, M, x, y; cin >> N >> M >> x >> y;
	vector< pair<int, int> > S;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		S.push_back(make_pair(a, i + 1));

	}

	sort(S.begin(), S.end());
	vector< pair<int, int> > A;
	for (int j = 0; j < M; ++j) {
		int a; cin >> a;
		A.push_back(make_pair(a, j + 1));
	}

	sort(A.begin(), A.end());

	vector<pair<int, int> > answer;
	int j = 0;
	multiset<pair<int, int> > E;
	for (int i = 0; i < M; ++i) {
		while (j < N && S[j].first - x <= A[i].first) {
			E.insert(make_pair(S[j].first + y, S[j].second));
			++j;
		}
		while (E.size() > 0 && E.begin() -> first < A[i].first)
			E.erase(E.begin());
		if (E.size()) {
			answer.push_back(make_pair(E.begin() -> second, A[i].second));
			E.erase(E.begin());
		}
	}
	cout << answer.size() << "\n";
	for (vector<pair<int, int> > ::iterator it = answer.begin(); it != answer.end() ;++it)
		cout << it -> first << " " << it -> second << "\n";
}