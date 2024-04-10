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

char a[1000100], b[1000100];
int cntB[1000100][26];

int gcd(int x, int y)
{
	return x && y ? gcd(y, x % y) : x + y;
}

int main()
{
	long long copyA, copyB, m, n;
	cin >> copyA >> copyB;
	scanf("%s%s", a, b);
	m = strlen(a);
	n = strlen(b);
	long long g = gcd(m, n), lcm = 1LL * n / g * m, repeat = 1LL * m * copyA / lcm;
	
	long long ans = 0;
	for (int i = 0; i < n; i++) cntB[i % g][b[i] - 'a']++;
	for (int i = 0; i < m; i++) ans += n / g - cntB[i % g][a[i] - 'a'];
	
	ans *= repeat;
	cout << ans << endl;
}