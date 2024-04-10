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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.00000001;
const int INF = 1E9;
const int MAXN = 5000;

vector<int64> lucky;
int64 l, r;
int pl, pr;
int64 ans;

void get(int64 c, int l) {
	if (l != 0)
		lucky.push_back(c);
	if (l < 10) {
		get(c * 10 + 4, l + 1);
		get(c * 10 + 7, l + 1);
	}
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	get(0, 0);
	sort(all(lucky));
	cin >> l >> r;
	pl = lower_bound(all(lucky), l) - lucky.begin();
	pr = lower_bound(all(lucky), r) - lucky.begin();
	if (pl == pr)
		cout << (lucky[pl] * 1ll * (r - l + 1)) << endl;
	else {
		ans = lucky[pl] * (lucky[pl] - l + 1);
		if (pr > 0)
			ans += lucky[pr] * (r - lucky[pr - 1]);
		else
			ans += r * lucky[pr];
		for (int i = pl; i < pr - 1; i++)
			ans = ans + (lucky[i + 1] - lucky[i]) * lucky[i + 1];
		cout << ans;
	}

    return 0;
}