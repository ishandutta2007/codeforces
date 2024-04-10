#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const int INF = 0x7f7f7f7f;

struct BIT {
	int length;
	vector<int> freq;
	BIT(int n) {
		freq.resize(n+1);
		memset(&freq[0], 0, (n+1)*sizeof(freq[0]));
		length = n;
	}
	void insert(int x, int cnt=1) {
		for ( ; x <= length; x += x & -x)
			freq[x] += cnt;
	}
	void insert_range(int xl, int xr, int cnt=1) {
		insert(xl, cnt);
		insert(xr+1, -cnt);
	}
	int query(int x) {
		int sum = 0;
		for ( ; x > 0; x -= x & -x)
			sum += freq[x];
		return sum;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	map<int,int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m.insert(pair<int,int>(a[i], i));
	}
	int idx = 0;
	for (pair<int,int> it: m) {
		a[it.second] = ++idx;
	}
	//cerr;for(int i=0; i < n; i++) //cerr << a[i] << " "; //cerr << endl;

	BIT left(n), right(n);
	int l[n], r[n];
	for (int i = 0; i < n; i++) {
		l[i] = left.query(a[i]);
		left.insert_range(1, a[i], 1);
		r[n-1-i] = right.query(a[n-1-i]);
		right.insert_range(a[n-1-i], n, 1);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		//cerr << "left: " << l[i] << "  right: " << r[i] << endl;
		ans += 1LL*l[i]*r[i];
	} cout << ans << endl;

	return 0;
}