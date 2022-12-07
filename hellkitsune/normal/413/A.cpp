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

int n, m, mn, mx, curmn = 101, curmx = 0;

int main() {
	cin >> n >> m >> mn >> mx;
	REP(i, m) {
		int x;
		cin >> x;
		if (x < curmn) curmn = x;
		if (x > curmx) curmx = x;
	}
	if (curmn < mn || curmx > mx) {
		cout << "Incorrect" << endl;
		return 0;
	}
	if (curmn > mn)
		++m;
	if (curmx < mx)
		++m;
	if (m > n)
		cout << "Incorrect" << endl;
	else
		cout << "Correct" << endl;
	return 0;
}