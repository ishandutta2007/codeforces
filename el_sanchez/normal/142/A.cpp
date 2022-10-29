#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int64 INF = 1E18;
const int MAXN = 9;

vector<pii> d;
int n, m;
int64 ans[3], a, b, c;

void go_b(int k) {
	if (k == d.size()) {
		c = n / a;
		if (c % b) return;
		c /= b;
		ans[0] = min(ans[0], 2 * (a + 1) * (b + 2) + 2 * c * (a + 1) + b * c);
		ans[1] = max(ans[1], 2 * (a + 1) * (b + 2) + 2 * c * (a + 1) + b * c);
		return;
	}
	go_b(k + 1);
	forn(i, d[k].se) {
		b *= d[k].fi;
		go_b(k + 1);
	}
	forn(i, d[k].se)
		b /= d[k].fi;
}

void go_a(int k) {
	if (k == d.size()) {
		go_b(0);
		return;
	}
	go_a(k + 1);
	forn(i, d[k].se) {
		a *= d[k].fi;
		go_a(k + 1);
	}
	forn(i, d[k].se)
		a /= d[k].fi;
}

int main() {

	ans[0] = INF;
	ans[1] = -1;
	cin >> n;
	m = n;
	for (int i = 2; i * i <= n; i++) {
		if (m % i == 0) {
			d.push_back(make_pair(i, 0));
			while (m % i == 0) {
				d.back().second++;
				m /= i;
			}
		}
	}
	if (m > 1) d.push_back(make_pair(m, 1));

	a = 1;
	b = 1;
	go_a(0);
	cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}