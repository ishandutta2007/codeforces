#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int dist(const pii& a, const pii& b) {
	return abs(a.first-b.first) + abs(a.second-b.second);
}

bool query(pii a, pii b) {
	cout << "? " << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
	string in;
	cin >> in;
	return in == "YES";
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	pii s(1,1);
	pii t(n,n);
	pii cur;
	vector<pii> path, connect;

	path.push_back(s);
	cur = s;
	while (dist(cur, s) < n-1) {
		pii right = pii(cur.first, cur.second+1);
		pii down = pii(cur.first+1, cur.second);
		if (query(right, t)) {
			cur = right;
		} else {
			cur = down;
		}
		path.push_back(cur);
	}

	int m = path.size();
	connect.push_back(t);
	cur = t;
	for (int i = 2; dist(cur, t) < n-2; i++) {
		pii up = pii(cur.first-1, cur.second);
		pii left = pii(cur.first, cur.second-1);
		if (query(path[m-i], up)) {
			cur = up;
		} else {
			cur = left;
		}
		connect.push_back(cur);
	}
	reverse(connect.begin(), connect.end());
	for (const pii& it : connect) {
		path.push_back(it);
	}

	cout << "! ";
	for (int i = 1; i < path.size(); i++) {
		if (path[i].first == path[i-1].first) {
			cout << "R";
		} else {
			cout << "D";
		}
	}
	cout << endl;

	return 0;
}