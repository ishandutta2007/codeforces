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

using namespace std;

typedef unsigned long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;

int n, k, tmr, celem;
vi used;
vector<pii> a;
ll md, ans, cur, prs, mn, num;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n;
	used.resize(n);
	forn(ii, 2) {
		forn(i, n) {
			scanf("%d", &k);
			a.push_back(make_pair(k, i));
		}
	}
	a.push_back(make_pair(2 * INF, -1));
	cin >> md;
	sort(all(a));
	ans = 1;
	num = 1;
	prs = 0;
	tmr = 1;

	celem = a[0].ff;
	used[a[0].ss] = tmr;

	forab(i, 1, a.size()) {
		if (a[i].ff != celem) {

			cur = 1;
			forn(j, prs) {
				mn = (num - 1) * num / 2;
				mn %= md;
				cur = (cur * mn) % md;
				num -= 2;
			}
			while (num > 1) {
				cur = (cur * num) % md;
				num--;
			}
			ans = (ans * cur) % md;

			if (a[i].ss == -1)
				break;

			num = 1;
			tmr++;
			prs = 0;
			celem = a[i].ff;
			used[a[i].ss] = tmr;
		} else {
			if (used[a[i].ss] == tmr)
				prs++;
			used[a[i].ss] = tmr;
			num++;
		}
	}

	cout << ans;

    return 0;
}