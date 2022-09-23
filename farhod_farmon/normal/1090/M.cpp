#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <math.h>
#include <cmath>
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <queue>
#include <iomanip>
#include <istream>
#include <list>
#include <stack>
#include <numeric>
#include <ostream>
#include <cassert>
#include <sstream>
#include <string>
#include <utility>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <random>

using namespace std;

#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int((x.size())))
#define fi first
#define se second

typedef long double 	ld;
typedef long long 		ll;
typedef vector<int> 	VI;
typedef pair<int, int>	PII;
typedef pair<ll, ll> 	PLL;
typedef vector<ll>		VL;
typedef vector<PLL> 	VPL;
typedef vector<PII> 	VPI;

#define dbb(x)		 { cerr << #x << " = " << x << "\t";      }
#define db(x)        { dbb(x); cerr << endl; }
#define db2(x,y)     { dbb(x); dbb(y); cerr << endl; }
#define db3(x,y,z)   { dbb(x); dbb(y); dbb(z); cerr << endl; }

const ll  MOD = 1000000007ll;

ll powmod(ll a, ll b) { ll res = 1; a %= MOD; assert(b >= 0); for (; b; b >>= 1) { if (b & 1) res = res * a%MOD; a = a * a%MOD; }return res; }
template <typename t1, typename t2> inline bool upmax(t1 &a, t2 b) { if (a < (t1)b) { a = (t1)b; return true; } else return false; }
template <typename t1, typename t2> inline bool upmin(t1 &a, t2 b) { if (a > (t1)b) { a = (t1)b; return true; } else return false; }
template <typename T> inline T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template <typename T> inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template <typename T> inline T sqr(T a) { return a * a; }

int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

const int INF = 1000000404;
const ll  LINF = 4000000000000000404ll;
const ld  PI = 3.14159265358979323846;
const ld  EPS = 1e-9;

int SQ = 318;
int timer = 0;

#define N 100100

int a[N];
void solve() {

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int len = 1;
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			len = 1;
		}
		else len ++;
		upmax(ans, len);
	}
	cout << ans << endl;





}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t = 1;
	//cin >> t;

	while (t--) {

		solve();

	}

	getchar();
	getchar();
	return 0;
}