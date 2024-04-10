#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef pair<int,int> pii;
#define nl '\n'

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

ostream& operator << (ostream& os, const pii& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

bool cmp(const pii& a, const pii& b) {
	return a.first > b.first || (a.first == b.first && a.second > b.second);
}

int n;
const int N = 3017;
pii a[N];
int rmq[N][20];
int diff[N];

void build_rmq() {
	for (int i = 1; i <= n; i++) {
		rmq[i][0] = i;
	}
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i + (1<<j) - 1 <= n; i++) {
			int prev = rmq[i][j-1];
			int next = rmq[i+(1<<(j-1))][j-1];
			if (diff[prev] > diff[next])
				rmq[i][j] = prev;
			else
				rmq[i][j] = next;
		}
	}
}

int query_rmq(int a, int b) {
	int jump = 31 - __builtin_clz(b-a+1);
	int first = rmq[a][jump];
	int second = rmq[b-(1<<jump)+1][jump];
	if (diff[first] > diff[second])
		return first;
	else
		return second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	a[n].first = 0;
	sort(a, a+n, cmp);
	for (int i = 1; i <= n; i++) {
		diff[i] = a[i-1].first - a[i].first;
	}

	build_rmq();

	int first, second, third;
	int c1, c2, c3;
	first = second = third = -1;
	c1 = c2 = c3 = -1;
	for (int i = 1; i < n; i++) {
		int tf = diff[i];
		if (tf < first) 
			continue;
		for (int j = (i+1)/2; j <= 2*i; j++) {
			int ts = diff[i+j];
			if (tf == first && ts < second)
				continue;
			int lower = max((i+1)/2, (j+1)/2) + i + j;
			int upper = min(n, min(2*i, 2*j) + i + j);
			if (upper < lower)
				continue;
			int ttid = query_rmq(lower, upper);
			int tt = diff[ttid];
			if (tf == first && ts == second && tt < third)
				continue;
			first = tf, second = ts, third = tt;
			c1 = i, c2 = j, c3 = ttid;
		}
	}

	int ans[n];
	for (int i = 0; i < c1; i++) 
		ans[a[i].second] = 1;
	for (int i = c1; i < c1+c2; i++)
		ans[a[i].second] = 2;
	for (int i = c1+c2; i < c3; i++)
		ans[a[i].second] = 3;
	for (int i = c3; i < n; i++) 
		ans[a[i].second] = -1;

	for (int i = 0; i < n; i++) 
		cout << ans[i] << " ";
	cout << nl;

	return 0;
}