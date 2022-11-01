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
#include <tr1/unordered_map>
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

int n, m;

int BIT[300007];

void add(int x, int y) {
	++x;
	while (x <= n + 10) {
		BIT[x] += y;
		x += x & -x;
	}
}

int sum(int x) {
	++x;
	int ret = 0;
	while (x) {
		ret += BIT[x];
		x -= x & -x;
	}

	return ret;
}

struct Query {
	int l, r, at;
	Query(int l, int r) : l(l), r(r) {}
	Query() {}
	bool operator < (const Query &o) const {
		return r < o.r;
	}
};

Query queries[300007];
int a[300007];

tr1::unordered_map<int, int> indexes;
vector<int> candidate[300007];

int ans[300007];

int main() {
	cin >> n >> m;
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) indexes[a[i]] = i;
	REP(i, m) {
		scanf("%d%d", &queries[i].l, &queries[i].r);
		--queries[i].l;
		--queries[i].r;
		queries[i].at = i;
	}
	sort(queries, queries + m);
	int ptr = 0;
	REP(i, n) {

		TR(it, candidate[i]) {
			add(*it, 1);
		}

		vector<int> divisor;
		int x = a[i];
		for (int k = 1; k * k <= x; ++k) {
			if (x % k == 0) {
				divisor.PB(k);
				if (k * k != x) {
					divisor.PB(x / k);
				}
			}
		}

		TR(it, divisor) {

			int at = indexes[*it];

			if (at > i) {
				candidate[at].PB(i);
			} else {
				add(at, 1);
			}
		}

		while (ptr < m && queries[ptr].r == i) {
			ans[queries[ptr].at] = sum(i) - sum(queries[ptr].l - 1);
			++ptr;
		}
	}

	REP(i, m) {
		cout << ans[i] << endl;
	}
	return 0;
}