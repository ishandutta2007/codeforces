#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> A; A.reserve(N);
	std::vector<int> B; B.reserve(N);
	for (int i = 0; i < N; i++) {
		B.push_back(i+1);
	}

	std::vector<int> query; query.reserve(N);
	std::vector<int> NA; NA.reserve(N);
	std::vector<int> NB; NB.reserve(N);
	while (int(A.size()) + int(B.size()) > 2) {
		int LA = int(A.size()) / 2;
		int LB = int(B.size() + 1) / 2;
		if (int(A.size()) == 1 && int(B.size()) == 2) {
			LA = 1;
			LB = 0;
		}
		query.clear();
		for (int i = 0; i < LA; i++) {
			query.push_back(A[i]);
		}
		for (int i = 0; i < LB; i++) {
			query.push_back(B[i]);
		}
		cout << '?' << ' ' << query.size();
		for (int i = 0; i < int(query.size()); i++) {
			cout << ' ' << query[i];
		}
		cout << '\n' << flush;
		string resp; cin >> resp;
		NA.clear();
		NB.clear();
		if (resp == "YES") {
			for (int i = 0; i < LA; i++) {
				NB.push_back(A[i]);
			}
			for (int i = 0; i < LB; i++) {
				NB.push_back(B[i]);
			}
			for (int i = LB; i < int(B.size()); i++) {
				NA.push_back(B[i]);
			}
		} else if (resp == "NO") {
			for (int i = LA; i < int(A.size()); i++) {
				NB.push_back(A[i]);
			}
			for (int i = LB; i < int(B.size()); i++) {
				NB.push_back(B[i]);
			}
			for (int i = 0; i < LB; i++) {
				NA.push_back(B[i]);
			}
		} else assert(false);
		std::swap(A, NA);
		std::swap(B, NB);
	}
	std::vector<int> res; res.reserve(N);
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