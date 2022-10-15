// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  CodeForces Round #440 (Div. 1)  |
+----------------------------------+
|             Problem B            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

bool valid(vector<int> v) {
	vector<char> used(v.size(), false);
	for (int i = 0; i < (int)v.size(); i++) {
		if (!(0 <= v[i] && v[i] < (int)v.size()) || used[v[i]]) {
			return false;
		}
		used[v[i]] = true;
	}
	return true;
}

vector<int> rev(vector<int> v) {
	vector<int> r(v.size());
	for (int i = 0; i < (int)v.size(); i++) {
		r[v[i]] = i;
	}
	return r;
}

vector< vector<int> > genMatrix(vector<int> v) {
	vector< vector<int> > mat(v.size(), vector<int>(v.size()));
	vector<int> r = rev(v);
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			mat[i][j] = v[i] ^ r[j];
		}
	}
	return mat;
}

inline pair< vector<int>, vector<int> > build(vector<int> p) {
	int n = p.size();
	vector<int> r = rev(p);
	vector<int> r1(n), r2(n);
	for (int i = 0; i < n; i++) {
		r1[i] = p[0] ^ r[i];
	}
	for (int i = 0; i < n; i++) {
		r2[i] = p[i] ^ r[0];
	}
	return {r1, r2};
}

signed main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> r1(n), r2(n);
	for (int i = 0; i < n; i++) {
		cout << "? " << 0 << " " << i << endl;
		cin >> r1[i];
		cout << "? " << i << " " << 0 << endl;
		cin >> r2[i];
	}
	vector<int> a(n);
	int ans = 0;
	pair< vector<int>, vector<int> > qur = {r1, r2};
	for (int i = 0; i < n; i++) {
		vector<int> p(n);
		for (int j = 0; j < n; j++) {
			p[j] = r2[j] ^ i;
		}
		if (valid(p)) {
			if (build(p) == qur) {
				ans++;
				if (ans == 1) {
					a = p;
				}
			}
		}
	}
	if (ans == 0) {
		return 256;
	}
	cout << "!" << endl << ans << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}