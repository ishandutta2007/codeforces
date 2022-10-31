#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long long n, h;
	cin >> n >> h;
	vector<long long>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int val=-1;
	for (int k = 1; k <= n; k++)
	{
		vector<long long> bv;
		for (int i = 0; i < k; i++)
		{
			bv.push_back(a[i]);
		}
		sort(bv.begin(), bv.end());
		reverse(bv.begin(), bv.end());
		long long ans = 0;
		for (int i = 0; i < k; i += 2)
		{
			ans += bv[i];
		}
		if (ans <= h)
		{
			val = k;
		}
	}
	cout << val << endl;
	//cin >> n;
}