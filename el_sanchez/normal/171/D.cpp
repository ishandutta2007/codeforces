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
const long double eps = 0.0000000001;
const int INF = 1E9;
const int MAXN = 60;

int n;

int main() {

	//freopen("a.in", "r", stdin);
	//sfreopen("a.out", "w", stdout);

	cin >> n;
	if (n == 1) {
		cout << 2; //!
		//while (1)
		//	n = n;
	}
	if (n == 2) {
		cout << 3;
	}
	if (n == 3) {
		cout << 1; //!
	}
	if (n == 4) {
		cout << 2;
	}
	if (n == 5) {
		cout << 1;
	}

    return 0;
}