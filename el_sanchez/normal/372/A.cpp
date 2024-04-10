#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

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
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 100500;

int n, k, ans;
vi a, used;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	a.resize(n);
	used.resize(n, 0);
	forn(i, n)
		cin >> a[i];
	sort(all(a));

	ans = 0;
	int l = 0, r = n / 2 + 1, mid;
	bool f;
	while (r - l > 1) {
		mid = (l + r) >> 1;
		f = 1;
		
		k = 1;
		for (int i = 0, j = n - mid; i < mid; i++, j++) {
			if (a[i] * 2 > a[j]) {
				f = 0;
				break;
			}
		}

		if (f)
			l = mid;
		else
			r = mid;
	}
	ans = l;
	cout << n - ans;

	return 0;
}