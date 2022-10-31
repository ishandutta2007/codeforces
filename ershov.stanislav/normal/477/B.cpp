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

long long n, k;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> k;
	cout << (n*6-1)*k << endl;
	for (int i=0; i<n; i++) {
		cout << (i*6+1)*k << ' ' << (i*6+2)*k << ' ' << (i*6+3)*k << ' ' << (i*6+5)*k << endl;
	}
	return 0;
}