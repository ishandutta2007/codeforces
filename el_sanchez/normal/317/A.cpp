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
const int MAXN = 100500;

ll x, y, m;
ll ans, d;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> x >> y >> m;
	if (x >= m || y >= m) {
		cout << 0;
		return 0;
	}
	if (x <= 0 && y <= 0) {
		cout << -1;
		return 0;
	}
	if (x > y)
		swap(x, y);

	ans = 0;
	if (x <= 0) {
		d = abs(x) / y + 1;
		x += d * y;
		ans += d;
	}
	while (x < m && y < m) {
		if (x > y)
			swap(x, y);
		x += y;
		ans++;
	}
	cout << ans;

	return 0;

}