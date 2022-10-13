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

long long n, ans;

void update(long long a, long long b, long long c)
{
	if (c > b)
	{
		if (b > a) ans += 6;
		else ans += 3;
	}
	if (c == b) 
	{
		if (b > a) ans += 3;
		else ans++;
	}
}

int main()
{
	cin >> n;
	if (n % 3) 
	{
		puts("0");
		return 0;
	}
	
	n /= 3;
	
	vector <long long> divisor;
	for (long long i = 1; i * i * i <= n; i++)
		if (n % i == 0)
			divisor.push_back(i);
		
	for (int i = 0; i < divisor.size(); i++)
		for (long long a = 1; a + a <= divisor[i]; a++)
		{
			long long b = divisor[i] - a;
			long long B = a + b, C = a * b - n / B;
			long long D = B * B - C * 4;
			if (D < 0) continue;
			long long u = (long long)sqrt(D);
			if (u * u != D) continue;
			if (u % 2 != B % 2) continue;
			if (u >= B) update(a, b, (u - B) / 2);
		}
		
	cout << ans << endl;
}