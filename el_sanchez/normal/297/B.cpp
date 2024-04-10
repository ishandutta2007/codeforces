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

int n[2], k, c, p1, p2, bal;
vi a[2];
vi v;
map<int, int> w[2];
set<int> lib;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n[0] >> n[1] >> k;
	forn(i, 2) {
		a[i].resize(n[i]);
		forn(j, n[i]) {
			scanf("%d", &a[i][j]);
			if (lib.find(-a[i][j]) == lib.end())
				lib.insert(-a[i][j]);
		}
	}

	forn(i, n[0]) {
		if (w[0].find(a[0][i]) == w[0].end())
			w[0][a[0][i]] = 0;
		w[0][a[0][i]]++;
	}

	forn(i, n[1]) {
		if (w[1].find(a[1][i]) == w[1].end())
			w[1][a[1][i]] = 0;
		w[1][a[1][i]]++;
	}

	bal = 0;
	for (set<int>::iterator it = lib.begin(); it != lib.end(); it++) {
		c = *it;
		c = -c;
		if (w[0].find(c) == w[0].end())
			p1 = 0;
		else
			p1 = w[0][c];
		if (w[1].find(c) == w[1].end())
			p2 = 0;
		else
			p2 = w[1][c];

		bal += p1 - p2;
		if (bal > 0) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";

    return 0;
}