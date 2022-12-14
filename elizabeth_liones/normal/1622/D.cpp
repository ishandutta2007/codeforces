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

const int mod = 998244353, maxn = 5005;
void upd(int& a, int b) { a = (a + b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % ((ll)mod); }
int c[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < maxn; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
		}
	}
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> o;
	for (int i = 0; i < n; i++) if (s[i] == '1') o.push_back(i);
	int ans = 0;
	if (k && k <= o.size())
	{
		for (int i = 0; i + k <= o.size(); i++)
		{
			int l = (i ? o[i - 1] + 1 : 0), r = (i + k < o.size() ? o[i + k] - 1 : n - 1);
			upd(ans, c[r - l + 1][k]);
			if (i + k != o.size()) upd(ans, mod - c[r - o[i]][k - 1]);
		}
	}
	else ans = 1;
	cout << ans << "\n";
	return 0;
}