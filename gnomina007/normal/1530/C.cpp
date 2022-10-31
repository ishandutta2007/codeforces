#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<map>
#include<fstream>
#include<set>
#include <functional>
#include <queue>
using namespace std;
int fun(int n)
{
	return n - n / 4;
}
int main()
{
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++)
	{
		int n;
		cin >> n;
		vector<int>v1(n), v2(n);
		int s1 = 0, s2 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> v2[i];
		}
		sort(v1.begin(), v1.end());
		reverse(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		reverse(v2.begin(), v2.end());
		vector<int>ps1(n + 1), ps2(n + 1);
		for (int i = 1; i<=n; i++)
		{
			ps1[i] = ps1[i - 1] + v1[i-1];
			ps2[i] = ps2[i - 1] + v2[i - 1];
		}
		for (int i = 0; i <= 10 * n; i++)
		{
			int val = fun(n+i);
			if (val <= i)
			{
				cout << i << endl;
				break;
			}
		//	cout << i << ' ' << val << endl;
			int s1 = ps1[val - i] + 100 * i;
			int c = min(n, val);
			int s2 = ps2[c];
		//	cout << s1 << ' ' << s2 << endl;
			if (s1 >= s2)
			{
				cout << i << endl;
				break;
			}
		}
	}
}