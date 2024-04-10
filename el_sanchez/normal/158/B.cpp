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
const int MAXN = 101000;

int n, k, ans, s[10];

int main() {

	cin >> n;
	FORN(i, 1, 4)
		s[i] = 0;
	forn(i, n) {
		cin >> k;
		s[k]++;
	}
	
	ans = s[4] + s[3];
	s[1] = max(0, s[1] - s[3]);
	ans += s[2] / 2;
	if (s[2] % 2) {
		ans++;
		s[1] = max(0, s[1] - 2);
	}
	ans += (s[1] + 3) / 4;
	cout << ans << endl;

    return 0;
}