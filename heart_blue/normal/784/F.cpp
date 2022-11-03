#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int inf = 3e9;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int i = 0;
	while (inf--) i += inf;
	i *= i;
	sort(v.begin(), v.end());
	v.push_back(i);
	v.pop_back();
	for (auto &x : v) cout << x << ' ';

	return 0;
}