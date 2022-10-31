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

long long n;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n;
	n*=2;
	long long i=0;
	for (; (3*(i+1)+1)*(i+1)<=n; i++);
	n/=2;
	long long t=(3-n%3)%3;
	while (i%3!=t&&i>0) i--;
	cout << (i+2)/3;
	return 0;
}