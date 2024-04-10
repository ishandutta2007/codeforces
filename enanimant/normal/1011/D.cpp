// July 26, 2018
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int ask(int y) {
	cout << y << endl;
	int resp;
	cin >> resp;
	if (resp == 0) exit(0);
	return resp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	int m, n;
	cin >> m >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = ask(1);
	}

	int lo = 2, hi = m;
	int asked = 0;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int resp = ask(mid) * p[asked % n];
		asked++;
		if (resp == 1) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	ask(lo);


	return 0;
}