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

int sz[100000];
int n;
VI e[100000];

void dfs(int x, int fa) {
	sz[x] = 1;
	TR(it, e[x]) {
		if (*it != fa) {
			dfs(*it, x);
			sz[x] += sz[*it];
		}
	}
}

long long ans = 0;
int tmp[100000];
int num[100000];
int large[100000];

void dfs2(int x, int fa) {
	TR(it, e[x]) {
		if (*it != fa) {
			dfs2(*it, x);
		}
	}

	int total = 0;
	TR(it, e[x]) {
		if (*it != fa) {
			tmp[total++] = sz[*it];
		} else {
			tmp[total++] = n - sz[x];
		}
	}

	sort(tmp, tmp + total);
	REP(i, total) large[i] = tmp[i];
	int diff = unique(large, large + total) - large;
	REP(i, diff) num[i] = 0;
	int ptr = 0;
	REP(i, total) {
		while (large[ptr] != tmp[i]) ++ptr;
		++num[ptr];
	}

	long long sum = 0;
	REP(i, diff) {
		long long choose = large[i] * (long long)(large[i] - 1) / 2;
		sum += choose * num[i];
	}

	REP(i, diff) {
		REP(j, i) {
			long long now = sum - (large[i] * (long long)(large[i] - 1) / 2);
			now -= large[j] * (long long)(large[j] - 1) / 2;
			ans += now * large[i] * num[i] * large[j] * num[j];
		}

		long long now = sum - (large[i] * (long long)(large[i] - 1) / 2);
		ans += now * large[i] * num[i];

		now = sum - (large[i] * (long long)(large[i] - 1) / 2);
		now -= (large[i] * (long long)(large[i] - 1) / 2);

		if (num[i] > 1) {
			ans += num[i] * (num[i] - 1ll) / 2 * large[i] * large[i] * now;
		}
	}

}

int main() {
	cin >> n;
	REP(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		e[u].PB(v);
		e[v].PB(u);
	}

	dfs(0, -1);
	dfs2(0, -1);
	cout << ans << endl;
	return 0;
}