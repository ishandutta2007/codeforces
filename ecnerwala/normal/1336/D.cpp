#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N; cin >> N;
	int curTriple, curStraight; cin >> curTriple >> curStraight;

	vector<int> queries; queries.reserve(N);
	for (int i = N-2; i >= 2; i--) {
		queries.push_back(i);
	}
	queries.push_back(0);
	queries.push_back(1);
	queries.push_back(0);

	vector<pair<int, int>> responses(N);
	for (int z = 0; z < N; z++) {
		cout << '+' << ' ' << queries[z]+1 << '\n' << flush;

		int nxtTriple, nxtStraight; cin >> nxtTriple >> nxtStraight;

		responses[z] = {nxtTriple - curTriple, nxtStraight - curStraight};

		curTriple = nxtTriple, curStraight = nxtStraight;
	}

	reverse(responses.begin(), responses.end());
	reverse(queries.begin(), queries.end());

	vector<int> A(N);
	A[0] = 2;
	while ((A[0]-1) * (A[0]-2) / 2 != responses[0].first) {
		A[0] ++;
	}

	A[2] = responses[0].second - responses[2].second;
	A[1] = responses[0].second / A[2];

	for (int z = 0; z < N; z++) {
		int i = queries[z];
		A[i] --;
		if (3 <= i+2 && i+2 < N) {
			int prod = responses[z].second;
			if (i >= 2) {
				prod -= A[i-2] * A[i-1];
			}
			if (i >= 1) {
				prod -= A[i-1] * A[i+1];
			}

			assert(A[i+1]);

			A[i+2] = prod / A[i+1];
		}
	}

	cout << '!' << ' ';
	for (int i = 0; i < N; i++) cout << A[i] << " \n"[i+1==N];
	cout << flush;

	return 0;
}