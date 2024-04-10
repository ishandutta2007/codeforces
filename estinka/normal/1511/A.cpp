#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iomanip>
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
		vector<int> r(n);
		for (int i = 0; i < n; i++)
		{
			cin >> r[i];
		} //cout << "				";
		cout << count(r.begin(), r.end(), 1) + count(r.begin(), r.end(), 3) << "\n";
	}
	return 0;
}