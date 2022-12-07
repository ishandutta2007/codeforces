#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int main() {
	int n, k;
	cin >> n >> k;
	if (k >= (n + 1) / 2) {
		cout << -1 << endl;
		return 0;
	}
	printf("%d\n", n * k);
	for (int i = 1; i <= k; ++i)
		REP(j, n)
			printf("%d %d\n", j + 1, (j + i) % n + 1);
	return 0;
}