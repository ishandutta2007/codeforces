#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int BASE = int(1e9) + 7;

int main()
{
	string x;
	cin >> x;
	int n = x.size(), p[222];
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % BASE;
	
	reverse(x.begin(), x.end());
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--)
		if (x[i] == '1') ans += 1LL * p[i] * p[i] % BASE * p[n - 1 - i] % BASE, ans %= BASE;
	
	cout << ans << endl;
}