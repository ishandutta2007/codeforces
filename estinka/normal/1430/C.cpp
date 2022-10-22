#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> num(n);
		for (int i = 0; i < n; i++)
		{
			num[i] = i + 1;
		}
		cout << 2 << "\n";
		while (num.size() > 1)
		{
			cout << num.back() << " " << num[num.size() - 2] << "\n";
			int a = num.back() + num[num.size() - 2] - (num.back() + num[num.size() - 2]) / 2;
			num.pop_back();
			num.pop_back();
			num.push_back(a);
		}
	}
	return 0;
}