#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
typedef long long ll;
using namespace std;

struct song
{
	int p, q, i, s;
};
bool cmp(song a, song b)
{
	if (a.s == b.s) return a.p > b.p;
	return a.s > b.s;
}
bool cmpi(song a, song b)
{
	return a.i < b.i;
}
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
		vector<song> s(n);
		for (int i = 0; i < n; i++) cin >> s[i].p, s[i].i = i;
		string l;
		cin >> l;
		for (int i = 0; i < n; i++) s[i].s = l[i] - '0';
		sort(s.begin(), s.end(), cmp);
		for (int i = 0; i < n; i++) s[i].q = n - i;
		sort(s.begin(), s.end(), cmpi);
		for (int i = 0; i < n; i++) cout << s[i].q << " \n"[i == n - 1];
	}
	return 0;
}