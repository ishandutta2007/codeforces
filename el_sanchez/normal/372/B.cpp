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
const int MAXN = 42;

int n, m, q, ans;
int t[MAXN][MAXN], gd[MAXN];
int cnt[MAXN][MAXN][MAXN][MAXN];
int a, b, c, d, k;
string s;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m >> q;
	forn(i, n) {
		cin >> s;
		forn(j, m) {
			t[i][j] = (s[j] == '1');
		}
	}

	for (int l = 0; l < m; l++)
		for (int r = l; r < m; r++) {
			for (int h1 = 0; h1 < n; h1++) {
				memset(gd, 0, sizeof(gd));
				for (int h2 = h1; h2 < n; h2++) {

					if (l == 0 && h1 == 1 && r == 1 && h2 == 3)
						l = l;

					for (int i = l; i <= r; i++)
						gd[i] |= t[h2][i];

					ans = 0;
					k = 0;
					for (int i = l; i <= r; i++) {
						if (gd[i]) {
							ans += k * (k + 1) / 2;
							k = 0;
						} else
							k++;
					}
					ans += k * (k + 1) / 2;

					cnt[l][h1][r][h2] = ans;
				}
			}
		}

	forn(qq, q) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--, b--, c--, d--;

		ans = 0;
		for (int i = a; i <= c; i++)
			for (int j = i; j <= c; j++)	
				ans += cnt[b][i][d][j];
		printf("%d\n", ans);
	}

	return 0;
}