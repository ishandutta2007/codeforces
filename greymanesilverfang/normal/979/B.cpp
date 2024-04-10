#include <algorithm>
#include <iostream>
using namespace std;

int cnt[128];
int solve(const string &s, int n)
{
	fill(cnt, cnt + 128, 0);
	int cntmax = 0;
	for (char c : s)
		cntmax = max(cntmax, ++cnt[c]);
	return (int)s.size() == cntmax && n == 1 ? (int)s.size() - 1 : min((int)s.size(), cntmax + n);
}

int main()
{
	int n; cin >> n;
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	int x1 = solve(s1, n);
	int x2 = solve(s2, n);
	int x3 = solve(s3, n);
	int x = max({x1, x2, x3});
	int res = 0;
	if (x == x1) 
		res += 1;
	if (x == x2) 
		res += 2;
	if (x == x3) 
		res += 4;
	switch (res)
	{
	case 1:
		cout << "Kuro";
		break;
	case 2:
		cout << "Shiro";
		break;
	case 4:
		cout << "Katie";
		break;
	default:
		cout << "Draw";
		break;
	}
	return 0;
}