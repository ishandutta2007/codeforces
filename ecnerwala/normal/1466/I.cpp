#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, B; cin >> N >> B;
	string S(B+N, '1');
	S[0] = '0';
	vector<int> Q(B+2*N-1);
	iota(Q.begin(), Q.begin()+N, 1);
	for (int a = 0, b = 0; a < B+N-1; ) {
		cout << Q[a] << ' ' << S.substr(0, B) << endl;
		string R; cin >> R;
		if (R == "yes") {
			while (S[b] == '1') b--;
			S[b] = '1';
		} else if (R == "no") {
			Q[b+++N] = Q[a++];
			S[b] = '0';
		} else assert(false);
	}
	cout << 0 << ' ' << S.substr(0, B) << endl;

	return 0;
}