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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 100500;
const ll LINF = -1E18;

int n, id, k, l, t;
int m;
vi a;
vector<pair<ll, ll>> q;
ll last, d;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n;
	last = -1;
	forn(i, n) {
		cin >> id;
		if (id == 1) {
			cin >> k;
			if (a.size() < MAXN) {
				a.push_back(k);
				if (a.size() == MAXN) {
					forn(i, MAXN)
						q.push_back(mp(i, a[i]));
					last = a.size();
				}
			} else {
				q.push_back(mp(last, k));
				last++;
			}
		} else {
			cin >> k >> l;
			while (a.size() < MAXN && l > 0) {
				forn(i, k)
					a.push_back(a[i]);
				l--;
			}

			if (a.size() >= MAXN && last == -1) {
				forn(i, a.size())
					q.push_back(mp(i, a[i]));
				last = a.size();
			}

			if (a.size() >= MAXN) {
				q.push_back(mp(last, -k));
				last += 1ll * k * 1ll * l;
			}
		}
	}

	if (last == -1) {
		forn(i, a.size())
			q.push_back(mp(i, a[i]));
		last = a.size();
	}

	//cerr << q.back().ff << ' ' << q.back().ss << '\n';

	cin >> m;
	forn(i, m) {
		cin >> d;
		d--;
		t = lower_bound(q.begin(), q.end(), mp(d, LINF)) - q.begin();
		if (t == q.size() || q[t].ff > d)
			t--;

		if (q[t].ss > 0)
			printf("%d ", q[t].ss);
		else {
			ll f = d - q[t].ff;
			printf("%d ", a[f % (-q[t].ss)]);
		}
	}

	return 0;
}