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
const int INF = 1E9;
const int MAXN = 10000;

int n, m, x, y, p, r;
vector<pii> q, ans;
vi w;

int main() {

	cin >> n >> m >> x >> y;
	forn(i, n) {
		cin >> p;
		q.push_back(make_pair(p - x, p + y));
	}
	forn(i, m) {
		cin >> p;
		w.push_back(p);
	}

	p = 0;
	r = 0;
	while (p < n && r < m) {
		if (q[p].first <= w[r] && w[r] <= q[p].second) {
			ans.push_back(make_pair(p, r));
			p++;
			r++;
		} else {
			if (w[r] < q[p].first)
				r++;
			else
				p++;
		}
	}
	cout << ans.size() << endl;
	forn(i, ans.size()) 
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;

    return 0;
}