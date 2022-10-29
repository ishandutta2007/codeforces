#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
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
const int MAXN = 31;

inline int bit(int v, int k) {
	return (v >> k) & 1;
}

int n, m, k;
ll a[MAXN], ta[MAXN];
int b[MAXN], tb[MAXN];

bool good(int x) {
	int l = 0, used = 0;
	ll mn;

	memset(ta, 0, sizeof(ta));
	memset(tb, 0, sizeof(tb));

	while (used < x) {
		if (used + b[l] > x)
			tb[l] = x - used;
		else
			tb[l] = b[l];
		used += tb[l];
		l++;
	}

	for (int i = 0; i < l; i++)
		ta[i] = a[i];
	mn = 2;
	for (int i = l; i < MAXN; i++) {
		ta[l - 1] += 1ll * mn * a[i];
		mn *= 2;
	}

	for (int i = l - 1; i >= 0; i--) {
		if (tb[i] > ta[i])
			return 0;
		ta[i] -= tb[i];
		if (i > 0)
			ta[i - 1] += ta[i] * 2;
	}
	return 1;
}

int binary() {
	int l = 0, r = m + 1, mid;
	while (r - l > 1) {
		mid = (l + r) >> 1;
		if (good(mid))
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m;
	forn(i, n) {
		scanf("%d", &k);
		forn(j, MAXN)
			if ((k >> j) & 1)
				a[j]++;
	}
	forn(i, m) {
		scanf("%d", &k);
		b[k]++;
	}

	cout << binary() << '\n';

	return 0;
}