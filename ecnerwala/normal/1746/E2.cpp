#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> A; A.reserve(N);
	std::vector<int> B(N); std::iota(B.begin(), B.end(), 1);

	std::vector<int> NA; NA.reserve(N);
	std::vector<int> NB; NB.reserve(N);
	while (int(A.size()) + int(B.size()) > 2) {
		int LA = int(A.size()) / 2;
		int LB = (int(B.size()) + 1 + int(A.size())%2) / 2;
		assert(LB <= int(B.size()));

		cout << '?' << ' ' << LA + LB;
		for (int i = 0; i < LA; i++) {
			cout << ' ' << A[i];
		}
		for (int i = 0; i < LB; i++) {
			cout << ' ' << B[i];
		}
		cout << '\n' << flush;

		string resp; cin >> resp;

		NA.clear();
		NB.clear();
		if (resp == "YES") {
			NB.insert(NB.end(), A.begin(), A.begin() + LA);
			NB.insert(NB.end(), B.begin(), B.begin() + LB);
			NA.insert(NA.end(), B.begin() + LB, B.end());
		} else if (resp == "NO") {
			NB.insert(NB.end(), A.begin() + LA, A.end());
			NB.insert(NB.end(), B.begin() + LB, B.end());
			NA.insert(NA.end(), B.begin(), B.begin() + LB);
		} else assert(false);
		std::swap(A, NA);
		std::swap(B, NB);
	}

	std::vector<int> res;
	for (int v : A) res.push_back(v);
	for (int v : B) res.push_back(v);

	for (int v : res) {
		cout << '!' << ' ' << v << '\n' << flush;
		string resp; cin >> resp;
		if (resp == ":)") {
			break;
		} else if (resp == ":(") {
			continue;
		} else assert(false);
	}

	return 0;
}