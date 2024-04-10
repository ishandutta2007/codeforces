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

int n, k, ans, m[2], id[2];
vi a;

int main() {

	cin >> n;
	forn(i, n) {
		cin >> k;
		a.push_back(k);
	}

	m[0] = INF;  //min
	m[1] = -INF; //max
	forn(i, n) {
		if (m[0] >= a[i]) {
			m[0] = a[i];
			id[0] = i;
		}
		if (m[1] < a[i]) {
			m[1] = a[i];
			id[1] = i;
		}
	}

	ans = (n - 1 - id[0]) + (id[1]);
	if (id[0] < id[1])
		ans--;
	cout << ans << endl;

    return 0;
}