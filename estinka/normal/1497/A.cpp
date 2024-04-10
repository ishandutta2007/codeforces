#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <bitset>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> f(128, 0);
		for (int i = 0; i < n; i++) cin >> a[i], f[a[i]]++;
		int i = 0;
		while (f[i])
		{
			cout << i << " ";
			f[i]--; i++;
		}
		for (int k = 0; k < f.size(); k++) for (int j = 0; j < f[k]; j++) cout << k << " ";
		cout << "\n";
	}
	return 0;
}