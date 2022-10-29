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
const int MAXN = 100500;
const int MAXK = 262144 * 2;

int t[MAXK * 2 + 1];

void update(int i, int value) {
    int v = MAXK + i - 1;
    t[v] += value;
    while (v > 1) {
        v /= 2;
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int get(int v, int l, int r, int ll, int rr) {
    if ((r < ll) || (rr < l))
        return 0;
    if ((ll <= l) && (r <= rr))
        return t[v];
    return get(2 * v, l, (l + r) / 2, ll, rr) + get(2 * v + 1, (l + r) / 2 + 1, r, ll, rr);
}

int n, q, a, b;
vi st;
long double sum, ans;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	st.pb(0);
	sum = 0;
	scanf("%d", &n);
	cout.precision(10);
	forn(i, n) {
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d%d", &a, &b);
			sum += a * b;
			update(a, b);
		} else if (q == 2) {
			scanf("%d", &a);
			sum += a;
			a -= get(1, 1, MAXK, st.size() + 1, MAXK);
			st.pb(a);
		} else {
			b = st.size();
			sum -= get(1, 1, MAXK, b, MAXK);
			a = st.back();
			sum -= a;
			st.pop_back();
		}
		ans = sum / long double(st.size());
		cout << ans << '\n';
	}

    return 0;
}