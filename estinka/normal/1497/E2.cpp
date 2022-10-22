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

class segment_tree
{
	vector<int> mini;
	int n;
public:
	void update(int pos, int val)
	{
		mini[pos += n] = val;
		for (pos = (pos >> 1); pos; pos >>= 1) mini[pos] = min(mini[pos << 1], mini[pos << 1 | 1]);
	}
	int query(int l, int r)
	{
		int ans = n + 1;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1) ans = min(ans, mini[l++]);
			if (r & 1) ans = min(ans, mini[--r]);
		}
		return ans;
	}
	segment_tree(int N) :n(N), mini(vector<int>(N * 2, N + 1)) {}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int A = 1e7 + 128;
	//const int A =  128;
	vector<int> lp(A, 1), pr;
	for (int i = 2; i < A; i++)
	{
		if (lp[i] == 1) lp[i] = i, pr.push_back(i);
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < A; j++) lp[pr[j] * i] = pr[j];
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1);
		vector<segment_tree> st(k + 1, segment_tree(n + 1));
		st[0].update(0, 0);
		vector<vector<int> > dp(n + 1, vector<int>(k + 1, n + 1));
		map<int, int> last;
		vector<int> l(k + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			for (int c = a[i]; c > 1;)
			{
				if (c % (lp[c] * lp[c]) == 0)
				{
					a[i] /= lp[c] * lp[c];
					c /= lp[c] * lp[c];
				}
				else c /= lp[c];
			}
			l.push_back(last.count(a[i]) ? last[a[i]] : 0);
			sort(l.begin(), l.end(), greater<int>()); l.pop_back();
			for (int c1 = 0; c1 <= k; c1++)
			{
				for (int c2 = 0; c2 + c1 <= k; c2++)
				{
					dp[i][c1 + c2] = min(dp[i][c1 + c2], st[c1].query(l[c2], i) + 1);
				}
			}
			for (int c = 0; c <= k; c++) st[c].update(i, dp[i][c]);
			last[a[i]] = i;
		}
		cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
	}
	return 0;
}