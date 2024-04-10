#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	long long n,m,a,b,p;
	cin >> n >> m >> a >> b;
	p = n / m * m;
	long long ans1 = (n - p) * b;
	p = (n / m + 1) * m;
	long long ans2 = (p - n) * a;
	cout << min(ans1,ans2) << endl;
	return 0;
}