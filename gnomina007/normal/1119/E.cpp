#include <iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	long long ans = 0, zapas=0;
	for (int j = 0; j < n; j++)
	{
		//cout << j << ' ' << zapas << ' ' << v[j] << endl;
		if (2 * zapas < v[j])
		{
			ans += zapas;
			long long bv = v[j] - 2 * zapas;
			zapas = bv % 3;
			ans += bv / 3;
		}
		else
		{
			ans += v[j] / 2;
			zapas -= v[j]/2;
			zapas += v[j] % 2;
		}
	}
	cout << ans << endl;
	//cin >> n;
}