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
	int n, ansmin = -(2e9), ansmax = 2e9;
	cin >> n;
	string s1, s2;
	int k;
	REP(i, n) {
		int flag;
		cin >> s1 >> k >> s2;
		if (s1 == "<") flag = 0;
		else if (s1 == "<=") flag = 1;
		else if (s1 == ">") flag = 2;
		else flag = 3;
		if (s2[0] == 'N')
			flag = 3 - flag;
		if (flag == 0)
			ansmax = min(ansmax, k - 1);
		else if (flag == 1)
			ansmax = min(ansmax, k);
		else if (flag == 2)
			ansmin = max(ansmin, k + 1);
		else
			ansmin = max(ansmin, k);
	}
	if (ansmax < ansmin)
		cout << "Impossible" << endl;
	else
		cout << ansmin << endl;
	return 0;
}