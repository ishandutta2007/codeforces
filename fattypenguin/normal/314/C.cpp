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

const int MOD = 1000000007;
const int MAXN = 300007;

long long BIT[2000007];

int n;
int a[MAXN];
int last[2000007];
int dp[MAXN];

void fix(int &x) {
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

void add(int x, int y) {
	fix(y);
	while (x <= 1000000) {
		BIT[x] += y;
		if (BIT[x] >= MOD) BIT[x] -= MOD;
		x += x & -x;
	}
}

int sum(int x) {
	int ret = 0;
	while (x) {
		ret += BIT[x];
		if (ret >= MOD) ret -= MOD;
		x -= x & -x;
	}

	return ret;
}

int main() {
	cin >> n;
	REP(i, n) scanf("%d", &a[i]);
	FILL(last, -1);
	REP(i, n) {
		dp[i] = sum(a[i]) * (ll)a[i] % MOD;
		dp[i] = (dp[i] + a[i]) % MOD;
		fix(dp[i]);
		add(a[i], dp[i] - dp[last[a[i]]]);
		last[a[i]] = i;
		// cout << "i = " << i << "dp[i] = " << dp[i] << endl;
	}

	int ans = 0;
	REP(i, n) {
		if (last[a[i]] == i) {
			ans += dp[i];
			if (ans >= MOD) ans -= MOD;
		}
	}

	cout << ans << endl;
	return 0;
}