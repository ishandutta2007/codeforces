#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 
#include <iomanip>

using namespace std;

long long n,m;
long long x,d;
long long sum;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> x >> d;
		sum += x * n;
		if (d < 0)
			sum += ((1 + n / 2) * (n / 2) / 2 + (1 + (n - 1) / 2) * ((n - 1) / 2) / 2) * d;
		else
			sum += (n * (n - 1) / 2) * d;
	}
	cout << fixed << setprecision(7) << (double)sum / n << endl;
	return 0;
}