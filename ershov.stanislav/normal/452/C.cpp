#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

long double n, m;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m;
	if (m==n&&n==1) {
		cout << 1;
		return 0;
	}
	cout << fixed << setprecision(10) << 1/n+(n-1)/n*(m-1)/(m*n-1);
	return 0;
}