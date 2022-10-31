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

int main()
{
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++)
	{
		int n;
		cin >> n;
		vector<int>v(10);
		int val = 0;
		for (int j = 0; j < 10; j++)
		{
			v[j] = n % 10;
			val = max(val, v[j]);
				n /= 10;
		}
		cout << val << endl;
	}
}