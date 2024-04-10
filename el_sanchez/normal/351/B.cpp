#pragma comment(linker, "/STACK:67108864")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
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
const int MAXN = 111;

int n, inv, iter;
int ans, st2, sum, slag, steps, cn, ck;
vi a;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];

	inv = 0;
	forn(i, n)
		forab(j, i + 1, n) {
			if (a[i] > a[j])
				inv++;
		}

	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n == 2) {
		cout << inv;
		return 0;
	}
	if (inv <= 1) {
		cout << 0;
		return 0;
	}

	if ((inv & 1) == 0)
		ans = inv * 2;
	else
		ans = inv * 2 - 1;
	cout << ans << '\n';

	return 0;
}