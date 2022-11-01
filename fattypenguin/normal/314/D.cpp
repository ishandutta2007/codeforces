#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MAXN = 100007;

ll x[MAXN], y[MAXN];
int n;

ll minl[MAXN], minr[MAXN];
ll maxl[MAXN], maxr[MAXN];

bool ok(ll d) {
	int ptr = 0;
	for (int i = 0; i < n; ++i) {

		while (ptr < i && x[i] - x[ptr] > d) {
			++ptr;
		}

		ll ymax = -0x3f3f3f3f3f3f3f3fll, ymin = 0x3f3f3f3f3f3f3f3fll;
		
		if (ptr > 0) {
			ymax = max(ymax, maxl[ptr - 1]);
			ymin = min(ymin, minl[ptr - 1]);
		}

		if (i + 1 < n) {
			ymax = max(ymax, maxr[i + 1]);
			ymin = min(ymin, minr[i + 1]);
		}

		if (ymax - ymin <= d) return true;
	}

	return false;
}

pair<ll, ll> points[MAXN];

int main() {
	cin >> n;
	REP(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		x[i] = a + b;
		y[i] = a - b;

		points[i] = MP(x[i], y[i]);

	}

	sort(points, points + n);

	REP(i, n) {
		x[i] = points[i].first;
		y[i] = points[i].second;
	}

	REP(i, n) {
		minl[i] = y[i];
		maxl[i] = y[i];
		if (i != 0) {
			minl[i] = min(minl[i], minl[i - 1]);
			maxl[i] = max(maxl[i], maxl[i - 1]);
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		minr[i] = maxr[i] = y[i];
		if (i != n - 1) {
			minr[i] = min(minr[i], minr[i + 1]);
			maxr[i] = max(maxr[i], maxr[i + 1]);
		}
	}

	ll low = 0, high = 2000000000ll;
	while (low < high) {
		ll mid = (low + high) / 2;
		if (ok(mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	printf("%.10f\n", (double)(low / 2.0));
	return 0;
}