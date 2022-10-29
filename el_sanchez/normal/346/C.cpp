#pragma comment(linker, "/STACK:67108864")

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
const int MAXN = 111111;
const int MAXM = 1011111;

int n, m, ans, cr, nxtr, a, b, l;
int p[MAXN], maxd[MAXM];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	forn(i, n)
		scanf("%d", &p[i]);
	cin >> b >> a;
	
	sort(p, p + n);
	l = 0;
	forab(i, 1, n) {
		if (p[i] != p[l]) {
			l++;
			p[l] = p[i];
		}
	}
	n = l + 1;
	//cerr << n << '\n';
	//forn(i, n)
	//	cerr << p[i] << '\n';
	
	forn(i, n) {
		int start = a;
		if (start % p[i] > 0)
			start = (a + p[i] - (a % p[i]));
		for (start; start <= b; start += p[i])
			maxd[start - a] = max(maxd[start - a], p[i]);
	}
	
	ans = 0;
	cr = a;
	nxtr = a + 1;
	for (int cur = a; cur <= b; cur++) {
		if (cr < cur) {
			ans++;
			cr = nxtr;
			nxtr = cr + 1;
		}
		if (cur == b) {
			cout << ans;
			return 0;
		}
		if (maxd[cur - a] > 0) {
			nxtr = max(nxtr, cur + maxd[cur - a] - 1);
		}
	}
	assert(false);
	
    return 0;
}