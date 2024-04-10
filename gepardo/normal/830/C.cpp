// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  Codeforces Round #424 (Div. 1)  |
+----------------------------------+
|             Problem C            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(42);

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	ios_base::sync_with_stdio(false);
	const int RANGE1 = 3000;
	const int RANGE2 = 500000;
	
	int n; int64_t k; cin >> n >> k;
	vector<int64_t> v(n);
	vector<int64_t> qpts;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 1; j < RANGE1; j++) {
			qpts.push_back(v[i] / j + 1);
			qpts.push_back(v[i] / j);
			qpts.push_back(v[i] / j - 1);
		}
	}
	
	for (int i = 1; i < RANGE2; i++) {
		qpts.push_back(i);
	}
	sort(qpts.begin(), qpts.end());
	vector<int64_t> pts;
	pts.push_back(qpts[0]);
	for (int i = 1; i < (int)qpts.size(); i++) {
		if (qpts[i-1] != qpts[i]) {
			pts.push_back(qpts[i]);
		}
	}
	pts.push_back(123456789012345678LL);
	
	int64_t ans = 1;
	for (int i = 0; i + 1 < (int)pts.size(); i++) {
		if (pts[i] < 1) {
			continue;
		}
		int64_t consumed = 0;
		int64_t inc = 0;
		for (int j = 0; j < n; j++) {
			consumed += pts[i] - 1 - (v[j] + pts[i] - 1) % pts[i];
			inc += v[j] / pts[i] + 1;
		}
		int64_t left = k - consumed;
		if (left < 0) {
			continue;
		}
		int64_t newAns = min(pts[i+1]-1, pts[i] + left / inc);
		ans = max(ans, newAns);
	}
	
	cout << ans << endl;
	return 0;
}