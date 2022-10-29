#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100000;

int ans, a[2], mn;
string s[2];
char c;
bool f[2];

int getn(char c) {
	return ('0' <= c && c <= '9') ? (c - '0') : (c - 'A' + 10);
}

int main() {

	c = getchar();
	while (c != ':') {
		s[0] += c;
		c = getchar();
	}
	cin >> s[1];

	forn(k, 2)
		forn(i, s[k].size() - 1)
			if (s[k][i] != '0')
				f[k] = 1;

	if (f[0] || f[1]) {
		f[0] = 1;
		FORN(i, 2, 60) {
			f[1] = 1;
			forn(j, 2) {
				mn = 1;
				a[j] = 0;
				ford(k, s[j].size()) {
					if (getn(s[j][k]) >= i) f[1] = 0;
					a[j] += mn * getn(s[j][k]);
					mn *= i;
				}
			}			
			if (f[1] && a[0] <= 23 && a[1] <= 59) {
				cout << i << ' ';
				f[0] = 0;
			}
		}			
		if (f[0]) cout << 0 << endl;
	} else {
		if (getn(s[0][s[0].size() - 1]) <= 23)
			cout << -1;
		else
			cout << 0;
	}

    return 0;
}