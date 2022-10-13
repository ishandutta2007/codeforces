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

int n, a[200200];
long long k;

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	
	long long D = 0;
	for (int i = 1, rank = 1, unrated = 0; i <= n; i++)	
		if (D - (rank - 1LL) * a[i] * (n - unrated - rank) < k) cout << i << endl, unrated++;
		else D += a[i] * (rank++ - 1LL);
}