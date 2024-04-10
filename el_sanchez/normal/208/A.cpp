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
const int MAXN = 111;

bool open, wrt;
int i, n;
string s;

bool wub(int v) {
	return (v + 2 < n && s[v] == 'W' && s[v + 1] == 'U' && s[v + 2] == 'B');
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> s;
	n = s.size();
	i = 0;
	wrt = 0;
	open = 0;
	while (i < n) {
		if (wub(i)) {
			open = 0;
			i += 3;
		} else {
			if (wrt && !open) cout << ' ';
			wrt = 1;
			open = 1;
			cout << s[i];
			i++;
		}
	}

	return 0;
}