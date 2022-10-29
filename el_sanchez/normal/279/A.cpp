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

using namespace std;

typedef long long ll;

const double pi = 3.1415926535897932384626433832795;
const double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 333333;

int x, y, cx, cy;
int dist, dir, ans;
int minx, miny, maxx, maxy;

void ifequal() {
	if (x == cx && y == cy) {
		cout << ans;
		exit(0);
	}
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> x >> y;
	if (x == 0 && y == 0) {
		cout << 0;
		return 0;
	}
	minx = miny = maxx = maxy = 0;
	cx = cy = 0;
	dir = 0;
	ans = 0;
	while (1) {
		if (dir == 0) {
			while (cx <= maxx) {
				cx++;
				ifequal();
			}
			maxx++;
		} else if (dir == 1) {
			while (cy <= maxy) {
				cy++;
				ifequal();
			}
			maxy++;
		} else if (dir == 2) {
			while (cx >= minx) {
				cx--;
				ifequal();
			}
			minx--;
		} else {
			while (cy >= miny) {
				cy--;
				ifequal();
			}
			miny--;
		}
		dir = (dir + 1) % 4;
		ans++;
	}

	return 0;
}