#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Segment {
	int x, a, b;
	bool operator < (const Segment& o) const {
		if (x != o.x) return x < o.x;
		else return abs(a-b) > abs(o.a-o.b);
	}
};

ll nc2(ll n) {
	return n*(n-1)/2;
}

const int N = 1e4+7;
const int OFF = 5000+2;
int bit[N];
int query(int x) {
	int res = 0;
	for ( ; x>0; x-=x&-x) {
		res += bit[x];
	}
	return res;
}
int query_range(int l, int r) {
	return query(OFF+r) - query(OFF+l-1);
}
void insert(int x, int cnt) {
	x += OFF;
	for ( ; x<N; x+=x&-x) {
		bit[x] += cnt;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<Segment> h, v;
	For(i,n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			v.push_back({x1,min(y1,y2),max(y1,y2)});
		} else {
			h.push_back({y1,min(x1,x2),max(x1,x2)});
		}
	}

	ll ans = 0;
	for (const Segment& left : v) {
		memset(bit, 0, sizeof bit);

		vector<Segment> o;
		for (const Segment& s : h) {
			if (left.a <= s.x && s.x <= left.b && s.a <= left.x && left.x < s.b) {
				o.push_back({s.b, s.x, s.x});
				insert(s.x, 1);
			}
		}
		for (const Segment& s : v) {
			if (left.x < s.x && max(left.a, s.a) < min(left.b, s.b)) {
				o.push_back({s.x, max(left.a, s.a), min(left.b, s.b)});
			}
		}
		sort(o.begin(), o.end());

		for (const Segment& s : o) {
			if (s.a == s.b) {
				insert(s.a, -1);
			} else {
				ans += nc2(query_range(s.a, s.b));
			}
		}
	}

	cout << ans << nl;

	return 0;
}