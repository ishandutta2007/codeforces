#pragma comment(linker, "/STACK:16777216")

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

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

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

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 1111;

struct pt {
	long double x, y;
};

int h, r, ans;
int ch, rest;
pt p1, p2;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> r >> h;
	ans = 0;
	ans += 2 * int(h / r);
	ch = (h / r) * r;	
	rest = h - ch;
	if (2 * rest >= r) {
		ans += 2;
		ch += r;
	}

	if (ans == 0)
		ans = 1;
	else {
		p1.x = (long double)r / 2;
		p1.y = ch - (long double)r / 2;
		p2.x = r;
		p2.y = h + (long double)r / 2;
		if (sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y)) >= r - eps)
			ans++;
	}
	cout << ans;

	return 0;
}