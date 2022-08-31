#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }

	vector<int> ans; ans.reserve(N);

	vector<int> curString; curString.reserve(N);
	vector<int> numSuffFolds; numSuffFolds.reserve(N+1);
	// stores midpoints
	vector<vector<int>> suffixPalindromes; suffixPalindromes.reserve(N+1);

	numSuffFolds.push_back(0);
	suffixPalindromes.emplace_back();

	int curFolds = 0;
	int pref_ind = 0;
	for (int v : A) {
		int r = int(curString.size())+1;
		vector<int> nSuffixPalindromes; nSuffixPalindromes.reserve(suffixPalindromes.back().size() + 1);
		if (r - pref_ind >= 2 && curString.back() == v) nSuffixPalindromes.push_back(r-1);
		for (int m : suffixPalindromes.back()) {
			if (2 * m - r >= pref_ind && v == curString[2 * m - r]) {
				nSuffixPalindromes.push_back(m);
			}
		}
		curString.push_back(v);
		suffixPalindromes.push_back(nSuffixPalindromes);
		numSuffFolds.push_back(nSuffixPalindromes.empty() ? 0 : numSuffFolds[nSuffixPalindromes[0]] + 1);

		if (suffixPalindromes.back().size() == 1) {
			int m = suffixPalindromes.back()[0];

			int l = m - (r-m);
			// First, check if there's a triple fold
			if (l - (r-m) >= pref_ind && !suffixPalindromes[m].empty() && suffixPalindromes[m][0] == l) {
				curFolds += 2;
				curString.resize(l);
				numSuffFolds.resize(l+1);
				suffixPalindromes.resize(l+1);
			} else if (l == pref_ind) {
				curFolds++;
				pref_ind = m;
				numSuffFolds.back() = 0;
			}
		}

		ans.push_back(curFolds + numSuffFolds.back());
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " \n"[i+1==N];
	}

	return 0;
}