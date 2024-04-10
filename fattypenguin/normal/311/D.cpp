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

const int MAXN = 110007;

ll powSum[50][MAXN * 4];
int delta[MAXN * 4];
ll a[MAXN];

const ll MOD = 95542721;

inline int p3(int x) { return x * (ll)x % MOD * x % MOD;}

inline void up(int x) {
	assert(!delta[x]);
	int l = delta[x * 2], r = delta[x * 2 + 1];
	for (int i = 0; i < 48; ++i) {
		powSum[i][x] = powSum[l][x * 2] + powSum[r][x * 2 + 1];
		if (powSum[i][x] >= MOD) powSum[i][x] -= MOD;
		++l; ++r;
		if (l >= 48) l -= 48;
		if (r >= 48) r -= 48;
	}
}

inline void down(int x) {
	if (delta[x]) {
		delta[x * 2] += delta[x];
		if (delta[x * 2] >= 48) delta[x * 2] -= 48;
		delta[x * 2 + 1] += delta[x];
		if (delta[x * 2 + 1] >= 48) delta[x * 2 + 1] -= 48;
		delta[x] = 0;
	}
}

void build(int left, int right, int x) {
	if (left < right) {
		int mid = (left + right) >> 1;
		build(left, mid, x * 2);
		build(mid + 1, right, x * 2 + 1);
		delta[x] = 0;
		up(x);
	} else {
		powSum[0][x] = a[left] % MOD;
		for (int i = 1; i < 48; ++i) {
			powSum[i][x] = p3(powSum[i - 1][x]);
		}
		delta[x] = 0;
	}
}

void setoff(int left, int right, int l, int r, int x) {
	if (l <= left && r >= right) {
		++delta[x];
		if (delta[x] >= 48) delta[x] -= 48;
		return;
	}

	int mid = (left + right) >> 1;
	down(x);
	if (l <= mid) setoff(left, mid, l, r, x * 2);
	if (r > mid) setoff(mid + 1, right, l, r, x * 2 + 1);
	up(x);
}

ll getSum(int left, int right, int l, int r, int x) {
	if (l <= left && r >= right) return powSum[delta[x]][x];

	int mid = (left + right) >> 1;
	int ret = 0;

	down(x);
	if (l <= mid) ret = getSum(left, mid, l, r, x * 2);
	if (r > mid) ret += getSum(mid + 1, right, l, r, x * 2 + 1);
	if (ret >= MOD) ret -= MOD;
	up(x);
	return ret;
}

int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	build(0, n - 1, 1);

	int m;
	cin >> m;
	while (m--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		--l; --r;
		if (op == 1) {
			int ans = getSum(0, n - 1, l, r, 1);
			cout << ans << endl;
		} else if (op == 2) {
			setoff(0, n - 1, l, r, 1);
		}
	}
	return 0;
}