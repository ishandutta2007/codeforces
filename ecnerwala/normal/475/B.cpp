#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	string S, T;
	cin >> S >> T;
	bool good = false;
	for(int i = 0; i < 2; i++) {
		good = good || (S.front() == '<' && S.back() == '>' && T.front() == 'v' && T.back() == '^');
		reverse(S.begin(), S.end());
		reverse(T.begin(), T.end());
	}
	cout << (good  ? "YES" : "NO") << '\n';
	return 0;
}