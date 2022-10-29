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
const int MAXN = 5111;

int n, m, tmr;
int len[MAXN], open[MAXN], w[MAXN], used[MAXN];
string s;
bool a[MAXN][MAXN];
int ans, cur;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m;
	forn(i, n) {
		cin >> s;
		forn(j, m)
			a[i][j] = s[j] == '1';
	}

	tmr = 1;
	ans = 0;
	for (int i = m - 1; i >= 0; i--) {
		forn(j, n)
			if (a[j][i]) {
				if (open[j])
					len[j]++;
				else {
					open[j] = 1;
					len[j] = 1;
				}
			} else {
				open[j] = 0;
				len[j] = 0;
			}

		forn(j, m)
			w[j] = 0;
		forn(j, n)
			w[len[j]]++;

		cur = 0;
		for (int j = m; j >= 0; j--) {
			cur += w[j];
			ans = max(ans, cur * j);
		}
	}

	cout << ans;

	return 0;
}