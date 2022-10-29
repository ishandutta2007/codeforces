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
const int MAXN = 1000500;

int n, a[MAXN];
ll ans;

void get(int n) {
	if (n < 0)
		return;
	if (n == 0) {
		a[0] = 0;
		return;
	}
	if (n == 1) {
		ans += 2;
		a[0] = 1;
		a[1] = 0;
		return;
	}

	int maxst = 1;
	while (maxst <= n)
		maxst <<= 1;
	maxst >>= 1;

	int l = maxst - (n - maxst + 1);
	for (int i = l; i < maxst; i++) {
		ans += 2ll * (i ^ (n - i + l));
		a[i] = n - i + l;
		a[n - i + l] = i;
	}
	get(l - 1);
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	ans = 0;
	get(n);
	cout << ans << '\n';
	forn(i, n + 1)
		printf("%d ", a[i]);

    return 0;
}