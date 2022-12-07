#include <cstdio>
#include <cmath>
#include <cstring>
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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int a[10] = {};

int main() {
	ios_base::sync_with_stdio(false);
	REP(i, 6) {
		int x;
		cin >> x;
		++a[x];
	}
	REP(i, 10) if (a[i] >= 4) {
		if (a[i] == 5) cout << "Bear\n";
		else if (a[i] == 6) cout << "Elephant\n";
		else {
			REP(i, 10) if (a[i] == 1) {
				cout << "Bear\n";
				break;
			} else if (a[i] == 2) {
				cout << "Elephant\n";
				break;
			}
		}
		return 0;
	}
	cout << "Alien\n";
	return 0;
}