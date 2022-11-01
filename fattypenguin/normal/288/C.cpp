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

int ans[2000000];

void solve(int n) {

	if (n <= 0) return;

	if (n == 1) {
		ans[0] = 0;
		return;
	}

	int t = 1;
	while (n >= t * 2) t *= 2;
	if (n == t) t /= 2;
	int rem = n - t;
	// cout << "n = " << n << " rem = " << rem << endl;
	for (int i = t - rem, j = 0; i < t; ++i, ++j) {
		ans[i] = n - 1 - j;
	}
	for (int i = t, j = 0; i < n; ++i, ++j) {
		ans[i] = t - 1 - j;
	}

	solve(n - 2 * rem);
}

int main() {
	int n;
	cin >> n;
	++n;
	solve(n);
	long long r = 0;
	REP(i, n) r += i ^ ans[i];
	cout << r << endl;
	REP(i, n) printf("%d ", ans[i]);
	cout << endl;
	return 0;
}