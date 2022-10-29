#pragma comment(linker, "/STACK:67108864")

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
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 1111;

int n, k, f;
vector<pii> a;
vi ans[2];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cout << "YES\n";

	cin >> n;
	a.resize(n);
	ans[0].resize(n);
	ans[1].resize(n);
	forn(i, n) {
		cin >> a[i].ff;
		a[i].ss = i;
	}
	sort(all(a));
	if (n == 1) {
		cout << 0 << '\n' << a[0].ff << '\n';
		return 0;
	}

	k = n / 3;
	if (n % 3 != 0) k++;
	for (int i = 0; i < k; i++) {
		ans[0][a[i].ss] = 0;
		ans[1][a[i].ss] = a[i].ff;
	}
	for (int i = k; i < 2 * k; i++) {
		ans[0][a[i].ss] = a[i].ff;
		ans[1][a[i].ss] = 0;
	}
	f = 0;
	for (int i = n - 1; i >= 2 * k; i--) {
		ans[0][a[i].ss] = f;
		ans[1][a[i].ss] = a[i].ff - f;
		f++;
	}

	forn(i, 2) {
		forn(j, n)
			printf("%d ", ans[i][j]);
		cout << '\n';
	}

    return 0;
}