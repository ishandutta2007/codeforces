#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;
LL K;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K >> S;

	LL cost = 0;
	for (int rem = 0; rem <= N; rem++) {
		unordered_set<string> s;
		s.insert("");
		LL cnt;
		for (int i = 0; i < N; i++) {
			unordered_set<string> sn;
			for (string st : s) {
				sn.insert(st + S[i]);
				if (i - st.length() < rem)
					sn.insert(st);
			}
			s = sn;
			cnt = 0;
			for (string st : s)
				cnt += (i + 1 - st.size() == rem);
			if (cnt >= K)
				break;
		}
		cnt = min(cnt, K);
		cost += cnt * rem;
		K -= cnt;
		if (!K)
			break;
	}

	cout << (K ? -1 : cost) << endl;
	return 0;
}