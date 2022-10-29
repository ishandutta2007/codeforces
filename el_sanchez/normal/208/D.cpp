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
#include <bitset>
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
const int MAXN = 111;

int n, m, w[MAXN];
int64 cur, cnt[5];
pair<int64, int> a[5];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n;
	forn(i, n)
		scanf("%d", &w[i]);
	forn(i, 5) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a, a + 5);

	cur = 0;
	forn(i, n) {
		cur += w[i];
		ford(j, 5) {
			cnt[a[j].se] += cur / a[j].fi;
			cur %= a[j].fi;
		}
	}
	forn(i, 5)
		cout << cnt[i] << ' ';
	cout << '\n' << cur << '\n';

	return 0;
}