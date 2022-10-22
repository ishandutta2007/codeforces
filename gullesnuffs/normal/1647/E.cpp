#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> compose(vector<int> p, vector<int> q) {
	vector<int> r(sz(p));
	rep(i,0,sz(p)) {
		r[i]=p[q[i]];
	}
	return r;
}

vector<int> toPower(vector<int> p, int x) {
	vector<int> r(sz(p));
	rep(i,0,sz(p))
		r[i] = i;
	rep(i,0,31) {
		if (x&(1<<i)) {
			r = compose(r, p);
		}
		p = compose(p, p);
	}
	return r;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> a(n);
	rep(i,0,n) {
		cin >> p[i];
		--p[i];
	}
	int maxA = 0;
	rep(i,0,n) {
		cin >> a[i];
		--a[i];
		maxA = max(maxA, a[i]);
	}
	set<int> s;
	for (int x : p)
		s.insert(x);
	int different = sz(s);
	int removedPerLesson = n-different;
	int lessons = (maxA-(n-1))/removedPerLesson;
	vector<int> q = toPower(p, lessons);
	map<int, vector<int>> qinv;
	rep(i,0,n)
		qinv[q[i]].push_back(i);
	vector<int> b(n);
	set<int> unused;
	rep(i,0,n)
		unused.insert(i);
	rep(i,0,n) {
		if (a[i] < n) {
			unused.erase(a[i]);
			b[qinv[i][0]] = a[i] + 1;
		}
	}
	rep(i,0,n) {
		if (b[i] == 0) {
			int lo = a[q[i]];
			b[i] = *unused.lower_bound(lo) + 1;
			unused.erase(b[i]-1);
		}
	}
	for (int x : b)
		cout << x << " ";
	cout << endl;
}