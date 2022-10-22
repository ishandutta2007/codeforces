#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

int l = 0, c = 0;
void update(int len)
{
	if (len > l) l = len, c = 1;
	else if (len == l) c++;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n), ib(n, 1), ie(n, 1), db(n, 1), de(n, 1);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		if (i && p[i - 1] < p[i]) ie[i] = ie[i - 1] + 1;
		if (i && p[i - 1] > p[i]) de[i] = de[i - 1] + 1;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (p[i + 1] > p[i]) ib[i] = ib[i + 1] + 1;
		if (p[i + 1] < p[i]) db[i] = db[i + 1] + 1;
	}
	for (int i = 0; i < n; i++)
	{
		update(ib[i]);
		update(db[i]);
	}
	int ans = 0;
	if (c == 2 && (l & 1))
	{
		for (int i = 0; i < n; i++)
		{
			if (ie[i] == l && db[i] == l) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}