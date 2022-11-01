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

int n, m;

inline int calc(int A, int B, int C, int low, int high) {

	int ret = 0;
	int res = B / (C - low);
	for (int i = low; i <= high; ++i) {
		while ((C - i) * (res + 1) <= B) ++res;
		ret += A + res;
	}

	return ret;
}

int main() {
	cin >> n >> m;

	long long ans = 0, center = 0;
	for (int i = m + 1; i <= n - i + 1; ++i) {

		int A = i - (n + 1);
		int B = (3 * i * (n + 1 - i) - 1);
		int C = i + n + 1;

		/*
		we need to count A + B / (C - X);
		*/

		int low = m + 1, high = n - m;
		if (low > high) continue;
		while (low < high) {
			int mid = ((low + high) >> 1);
			if (A + B / (C - mid) >= m + 1) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}

		if (i == n - i + 1) center = ans;

		if (A + B / (C - low) <= m) continue;

		int upperBound = low;
		low = upperBound; high = n - m;
		while (low < high) {
			int mid = ((low + high) >> 1) + 1;
			if (A + B / (C - mid) <= n - m) {
				low = mid;
			} else {
				high = mid - 1;
			}
		}

		if (A + B / (C - low) > n - m) {
			ans += (n - m - upperBound + 1) * (n - 2 * m);
			continue;
		}

		ans += (n - m - low) * (n - 2 * m);
		ans += calc(A, B, C, upperBound, low) - m * (low - upperBound + 1);
	}

	if (n % 2 == 1) {
		ans = center * 6 + (ans - center) * 3;
	} else {
		ans *= 6;
	}

	cout << ans << endl;

	return 0;
}