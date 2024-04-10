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

ll dp[101][100007];
pair<ll, ll> convex[100007];

ll dis[100007];

int main() {


	int n, m, p;
	cin >> n >> m >> p;
	REP(i, n - 1) {
		int x;
		scanf("%d", &x);
		dis[i + 1] = dis[i] + x;
	}

	vector<ll> time(m);
	REP(i, m) {
		int h, t;
		scanf("%d%d", &h, &t);
		--h;
		time[i] = t - dis[h];
	}
	SORT(time);

	vector<ll> sum(m + 1);
	sum[0] = 0;
	REP(i, m) sum[i + 1] = sum[i] + time[i];
	for (int i = 0; i < m; ++i) {
		dp[0][i] = (i + 1) * time[i] - sum[i + 1];
	}

	// REP(i, m) cout << time[i] << " ";
	// cout << endl;

	for (int i = 1; i < p; ++i) {
		int total = 0;
		int left = 0;
		REP(j, m) {
			dp[i][j] = dp[0][j];
			ll t = time[j];
			while (left + 1 < total && (convex[left + 1].second - convex[left].second) <= t * (convex[left + 1].first - convex[left].first)) {
				++left;
			}

			if (left < total) {
			//	for (int k = max(0, left - 3); k < max(total, left + 3); ++k) {
					int at = convex[left].first;
					// cout << "i = " << i << " j = " << j << " at = " << left << endl;
					dp[i][j] = min(dp[i][j], dp[i - 1][at] + ((j - at) * t - sum[j + 1] + sum[at + 1]));
			//	}
			}

			while (total > 1 && (dp[i - 1][j] + sum[j + 1] - convex[total - 1].second) * (convex[total - 1].first - convex[total - 2].first) <= (convex[total - 1].second - convex[total - 2].second) * (j - convex[total - 1].first)) {
				--total;
			}


			convex[total++] = MP(j, dp[i - 1][j] + sum[j + 1]);
			left = min(left, total - 1);
		}
	}

	// REP(i, p) { REP(j, m) cout << dp[i][j] << " "; cout << endl;}

	ll ans = 0x3f3f3f3f3f3f3f3fll;
	REP(i, p) ans = min(ans, dp[i][m - 1]);
	cout << ans << endl;
	return 0;
}