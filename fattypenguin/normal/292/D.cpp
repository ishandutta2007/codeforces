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

vector<PII> q[300000];
int l[300000], r[300000];
int ans[300000];

int fa[555];
int n, m;

int get(int x) {
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

inline bool same(int x, int y) {
	return get(x) == get(y);
}

inline void merge(int x, int y) {
	fa[get(x)] = get(y);
}

inline void init() {
	REP(i, n) fa[i] = i;
}

int main() {
	cin >> n >> m;
	REP(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		l[i] = u;
		r[i] = v;
	}
	REP(i, m) {
		l[i + m] = l[i];
		r[i + m] = r[i];
	}
	int qq;
	cin >> qq;
	REP(i, qq) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l; --r;
		int nr = l + m - 1;
		int nl = r + 1;
		if (nl <= nr) {
			q[nr].PB(MP(nl, i));
		} else {
			ans[i] = -1;
		}
	}
	REP(i, m * 2) SORT(q[i]);

	for (int i = 0; i < m * 2; ++i) {
		init();
		int *u = &l[i], *v = &r[i];
		int blocks = n;
		int ptr = (int)q[i].size() - 1;
		vector<PII> &s = q[i];
		for (int j = i; ptr >= 0 && j >= 0; --j) {
			if (!same(*u, *v)) {
				merge(*u, *v);
				--blocks;
			}
			while (ptr >= 0 && s[ptr].first == j) {
				ans[s[ptr].second] = blocks;
				--ptr;
			}
			--u; --v;
		}
	}
	REP(i, qq) if (ans[i] == -1) ans[i] = n;
	REP(i, qq) cout << ans[i] << endl;
	return 0;
}