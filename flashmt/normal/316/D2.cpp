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

long long f[1000100];

int main()
{
	f[0] = f[1] = 1;
	for (int i = 2; i <= 1000000; i++) f[i] = (f[i - 1] + f[i - 2] * (i - 1)) % BASE;
	
	int d1 = 0, x, n;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &x);
		if (x == 1) d1++;
	}
	
	long long ans = f[d1];
	for (int i = d1 + 1; i <= n; i++) ans = ans * i % BASE;
	
	cout << ans << endl;
}