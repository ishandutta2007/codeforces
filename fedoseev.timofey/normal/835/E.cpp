#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool query(vector <int> a, int x) {
	cout << "? " << (int)a.size() << ' ';
	for (auto i : a) {
		cout << i << ' ';
	}
	cout << endl;
	int res;
	cin >> res;
	if (res == x || res == 0) return false;
	return true;
}

int get(vector <int> a, int x) {
	while (a.size() > 1) {
		int m = a.size() >> 1;
		vector <int> b = vector <int> (a.begin(), a.begin() + m);
		vector <int> c = vector <int> (a.begin() + m, a.end());
		if (query(b, x)) {
			a = b;
		}
		else {
			a = c;
		}
	}
	assert(a.size() == 1);
	return a[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x, y;
    cin >> n >> x >> y;
    int mask = 0;
    for (int i = 0; (1 << i) <= n; ++i) {
    	vector <int> a;
    	for (int j = 1; j <= n; ++j) {
    		if (j & (1 << i)) a.push_back(j);
    	}
    	if (query(a, x)) mask |= (1 << i);
    }
    assert(mask != 0);
    vector <int> b, c;
    int A = -1, B = -1;
    for (int i = 0; i < 10; ++i) {
    	if (mask & (1 << i)) {
    		for (int j = 1; j <= n; ++j) {
    			if (j & (1 << i)) b.push_back(j);
    			else c.push_back(j);
    		}
    		if (b.size() > c.size()) swap(b, c);
    		A = get(b, x);
    		B = A ^ mask;
    		break;
    	}
    }
    if (A > B) swap(A, B);
    cout << "! " << A << ' ' << B << endl;
}