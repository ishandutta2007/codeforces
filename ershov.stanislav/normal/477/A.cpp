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

long long a, b;
const long long mod = 1e9+7;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> a >> b;
	long long c = ((((a*(a+1)/2)%mod)*b)%mod+a)%mod;
	c=(((c*(b-1))%mod)*b)  %mod;
	if (c%2) c=(c+mod)/2;
	else c/=2;
	cout << c;
	return 0;
}