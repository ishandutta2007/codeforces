#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 100500;

int n, x, y, ans;
int64 d, a, b, cur;
pair<int64, int> w[MAXN];
vi cl;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n >> d >> a >> b;
	forn(i, n) {
		scanf("%d%d", &x, &y);
		cur = a * x + b * y;
		w[i].fi = cur;
		w[i].se = i;
	}
	sort(w, w + n);

	ans = 0;
	while (ans < n) {
		if (d - w[ans].fi < 0) break;
		d -= w[ans].fi;
		cl.push_back(w[ans].se);
		ans++;
	}

	printf("%d\n", ans);
	forn(i, ans)
		printf("%d ", cl[i] + 1);

	return 0;
}