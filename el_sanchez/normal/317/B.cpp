#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <stack>
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
const int MAXN = 100;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int a[2 * MAXN][2 * MAXN], b[2 * MAXN][2 * MAXN];
int li, lj, aa, bb, add;
bool done;
int n, t;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> t;
	a[MAXN][MAXN] = n;
	li = lj = 0;
	while (true) {
		done = 0;

		add = 0;
		for (int i = -li; i <= li; i++)
			for (int j = -lj; j <= lj; j++)
				b[MAXN + i][MAXN + j] = 0;

		for (int i = -li; i <= li; i++)
			for (int j = -lj; j <= lj; j++) {
				b[MAXN + i][MAXN + j] += a[MAXN + i][MAXN + j];
				if (a[MAXN + i][MAXN + j] >= 4) {
					aa = a[MAXN + i][MAXN + j] / 4;
					done = 1;
					if (i == li)
						add = 1;
					forn(d, 4)
						b[MAXN + i + dx[d]][MAXN + j + dy[d]] += aa;
					b[MAXN + i][MAXN + j] -= aa * 4; 
				}
			}
		
		if (!done)
			break;

		li += add;
		lj += add;
		for (int i = -li; i <= li; i++)
			for (int j = -lj; j <= lj; j++)
				a[MAXN + i][MAXN + j] = b[MAXN + i][MAXN + j];

	}

	forn(i, t) {
		cin >> aa >> bb;
		cout << ((abs(aa) >= MAXN - 1 || abs(bb) >= MAXN - 1) ? 0 : a[MAXN + aa][MAXN + bb]) << '\n';
	}

	return 0;
}