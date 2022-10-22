#include <bits/stdc++.h>
using namespace std;

set<string> A;

int main() {
	{
		string S = "Timur";
		sort(S.begin(), S.end());
		do {
			A.insert(S);
		} while(next_permutation(S.begin(), S.end()));
	}

	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while(T--) {
		int N; string S;
		cin >> N >> S;
		puts(A.find(S) != A.end() ? "YES" : "NO");
	}
	return 0;
}