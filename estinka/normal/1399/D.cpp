#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <functional>
//#pragma optimize GCC("O3")
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
		vector<int>v(n);
		for (int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			v[i] = c - '0';
		}
		set<int> e0;
		set<int> e1;
		int tn = 0;
		vector<ll>wh(n);
		for (int i = 0; i < n; i++)
		{
			if (v[i])
			{
				if (!e0.empty())
				{
					wh[i] = *e0.begin();
					e0.erase(wh[i]);
				}
				else
				{
					tn++;
					wh[i] = tn;
				}
				e1.insert(wh[i]);
			}
			else
			{
				if (!e1.empty())
				{
					wh[i] = *e1.begin();
					e1.erase(wh[i]);
				}
				else
				{
					tn++;
					wh[i] = tn;
				}
				e0.insert(wh[i]);
			}
		}
		cout << tn << "\n";
		for (int i = 0; i < n; i++)
			cout << wh[i] << " ";
		cout << "\n";
	}
	return 0;
}