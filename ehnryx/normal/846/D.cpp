#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

struct BIT {
	static const int size = 500;
	int freq[size+1][size+1];
	BIT() {
		memset(freq, 0, sizeof(freq));
	}
	void insert(int x, int yy) {
		for ( ; x <= size; x += x & -x)
			for (int y = yy ; y <= size; y += y & -y)
				freq[x][y]++;
	}
	int query(int x, int yy) {
		int sum = 0;
		for ( ; x > 0; x -= x & -x)
			for (int y = yy ; y > 0; y -= y & -y)
				sum += freq[x][y];
		return sum;
	}
	int query(int xl, int xr, int yl, int yr) {
		return query(xr, yr) - query(xl-1, yr) - query(xr, yl-1) + query(xl-1, yl-1);
	}
};

struct RMQ {
	static const int size = 512;
	int maxt[2*size][2*size];
	RMQ() {
		memset(maxt, -1, sizeof(maxt));
	}
	int queryx(int left, int right, int yl, int yr, int start, int end) {
		int i = (size+left-1)/(end-start+1);
		if (left == start && right == end)
			return queryy(i, yl, yr, 1, size);
		int mid = (start+end)/2;
		if (right <= mid) return queryx(left, right, yl, yr, start, mid);
		else if (left > mid) return queryx(left, right, yl, yr, mid+1, end);
		else {
			return max(queryx(left, mid, yl, yr, start, mid), queryx(mid+1, right, yl, yr, mid+1, end));
		}
	}
	int queryy(int yid, int left, int right, int start, int end) {
		int i = (size+left-1)/(end-start+1);
		if (left == start && right == end) {
			return maxt[yid][i];
		}
		int mid = (start+end)/2;
		if (right <= mid) return queryy(yid, left, right, start, mid);
		else if (left > mid) return queryy(yid, left, right, mid+1, end);
		else return max(queryy(yid, left, mid, start, mid), queryy(yid, mid+1, right, mid+1, end));
	}
	int query(int xl, int xr, int yl, int yr) {
		return queryx(xl, xr, yl, yr, 1, size);
	}
	void inserty(int yid, int y, int start, int end, int val) {
		int i = (size+y-1)/(end-start+1);
		maxt[yid][i] = max(maxt[yid][i], val);
		if (start == end) 
			return;
		int mid = (start+end)/2;
		if (y <= mid) inserty(yid, y, start, mid, val);
		else inserty(yid, y, mid+1, end, val);
	}
	void insertx(int x, int y, int start, int end, int val) {
		int i = (size+x-1)/(end-start+1);
		inserty(i, y, 1, size, val);
		if (start == end) 
			return;
		int mid = (start+end)/2;
		if (x <= mid) insertx(x, y, start, mid, val);
		else insertx(x, y, mid+1, end, val);
	}
	void insert(int x, int y, int val) {
		insertx(x, y, 1, size, val);
	}
};

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	RMQ dead;
	BIT pix;
	int a, b, t;
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> t;
		pix.insert(a, b);
		dead.insert(a, b, t);
	}

	int mintime = INF;
	int area = k*k;
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			if (pix.query(i-k+1, i, j-k+1, j) == area) {
				mintime = min(mintime, dead.query(i-k+1, i, j-k+1, j));
			}
		}
	}
	if (mintime == INF) cout << -1 << nl;
	else cout << mintime << nl;

	return 0;
}