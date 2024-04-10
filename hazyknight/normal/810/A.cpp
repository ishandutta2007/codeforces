#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,k;

double sum,cnt;

int main()
{
	cin >> n >> k;
	for (int a,i = 1;i <= n;i++)
		cin >> a,sum += a;
	double cnt = n;
	for (int i = 1;;i++)
	{
		if (int(sum / cnt + 0.5) == k)
		{
			cout << i - 1 << endl;
			return 0;
		}
		sum += k;
		cnt++;
	}
	return 0;
}