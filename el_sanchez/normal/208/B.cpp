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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 60;

int n, a[MAXN], b[MAXN], c1, c2, c3, c4;
bool dp[MAXN][13][4][13][4][13][4];
string s;

int get1(char c) {
	if ('2' <= c && c <= '9') return (c - '2');
	if (c == 'T') return 8;
	if (c == 'J') return 9;
	if (c == 'Q') return 10;
	if (c == 'K') return 11;
	if (c == 'A') return 12;
}

int get2(char c) {
	if (c == 'S') return 0;
	if (c == 'D') return 1;
	if (c == 'H') return 2;
	if (c == 'C') return 3;
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	scanf("%d\n", &n);
	forn(i, n) {
		cin >> s;
		a[i] = get1(s[0]);
		b[i] = get2(s[1]);
	}
	if (n == 1) {
		cout << "YES";
		return 0;
	}
	if (n == 2) {
		if (a[0] == a[1] || b[0] == b[1])
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}
	dp[n - 1][a[n - 3]][b[n - 3]][a[n - 2]][b[n - 2]][a[n - 1]][b[n - 1]] = 1;

	FORD(i, n - 1, 1)
		forn(a1, 13)
			forn(a2, 4)
				forn(a3, 13)
					forn(a4, 4)
						forn(a5, 13)
							forn(a6, 4)
								if (dp[i][a1][a2][a3][a4][a5][a6]) {
									//i -> i - 1
									if (a3 == a5 || a4 == a6) {
										c1 = ((i > 2) ? a[i - 3] : 0);
										c2 = ((i > 2) ? b[i - 3] : 0);
										dp[i - 1][c1][c2][a1][a2][a5][a6] = 1;
									}
									//i -> i - 3
									if (i > 2 && (a[i - 3] == a5 || b[i - 3] == a6)) 
										dp[i - 1][a5][a6][a1][a2][a3][a4] = 1;
								}
	forn(a1, 13)
		forn(a2, 4)
			if (dp[0][0][0][0][0][a1][a2]) {
				cout << "YES";
				return 0;
			}
	cout << "NO";

	return 0;
}