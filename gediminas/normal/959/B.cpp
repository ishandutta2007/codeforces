/*input
5 4 4
i loser am the second
100 20 1 5 10
1 1
1 3
2 2 5
1 4
i am the second
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	string zod[n];
	long long a[n];

	for (int i = 0; i < n; i++) {
		cin >> zod[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long mina[k];
	int kuri[n];

	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		mina[i] = 1000000000;

		for (int j = 0; j < t; j++) {
			int x;
			cin >> x;
			x--;
			kuri[x] = i;
			mina[i] = min(mina[i], a[x]);
		}
	}

	map<string, int> aaa;

	for (int i = 0; i < n; i++) {
		aaa[zod[i]] = mina[kuri[i]];
	}

	long long ats = 0;

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		ats += aaa[a];
	}

	cout << ats << endl;

	return 0;
}