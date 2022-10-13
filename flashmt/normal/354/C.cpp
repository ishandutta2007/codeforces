#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int oo = 27081993;

int cnt[2000100];

int main()
{
	int n, k, x, minVal = oo, maxVal = -oo;
	cin >> n >> k;
	while (n--) 
	{
		scanf("%d", &x); 
		cnt[x] = 1;
		minVal = min(minVal, x);
		maxVal = max(maxVal, x);
	}
	
	for (int i = minVal; i <= 2000000; i++) cnt[i] += cnt[i - 1];
	
	for (int g = minVal; g; g--)
	{
		int can = 0;
		for (int i = g; i <= maxVal; i += g) can += cnt[i + min(k, g - 1)] - cnt[i - 1];
		if (can >= cnt[maxVal])
		{
			cout << g << endl;
			break;
		}
	}
}