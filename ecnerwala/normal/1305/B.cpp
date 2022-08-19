#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S; cin >> S;
	vector<int> opens;
	vector<int> closes;
	for (int i = 0; i < int(S.size()); i++) {
		if (S[i] == '(') opens.push_back(i);
		else if (S[i] == ')') closes.push_back(i);
		else assert(false);
	}
	reverse(closes.begin(), closes.end());
	opens.push_back(int(S.size()));
	closes.push_back(-1);
	int i = 0;
	while (opens[i] < closes[i]) i++;
	opens.resize(i);
	closes.resize(i);
	vector<int> ans = std::move(opens);
	ans.insert(ans.end(), closes.rbegin(), closes.rend());

	if (i == 0) {
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n';
		cout << 2*i << '\n';
		for (int v : ans) {
			cout << v+1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}