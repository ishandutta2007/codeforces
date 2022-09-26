#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

long long n,k,a,b;
long long MIN = 1e18,MAX = -1e18;

void add(long long s,long long t)
{
	long long ans = n * k / __gcd(n * k,t - s + n * k);
	MIN = min(MIN,ans);
	MAX = max(MAX,ans);
}

int main()
{
	cin >> n >> k >> a >> b;
	for (int i = 0;i < n;i++)
	{
		add(a + 1,i * k + 1 + b);
		add(a + 1,i * k + 1 + k - b);
		add(k + 1 - a,i * k + 1 + b);
		add(k + 1 - a,i * k + 1 + k - b);
	}
	cout << MIN << ' ' << MAX << endl;
	return 0;
}