#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

class segment_tree
{
	vector<int> lazy, sum, l, r;
	void unlazy(int vr)
	{
		if (lazy[vr] == -1) return;
		lazy[vr * 2 + 1] = lazy[vr * 2 + 2] = lazy[vr];
		sum[vr * 2 + 1] = sum[vr * 2 + 2] = lazy[vr] * (r[vr * 2 + 1] - l[vr * 2 + 1] + 1);
		lazy[vr] = -1;
	}
public:
	segment_tree(int n, string &f)
	{
		int n2 = 1;
		while (n2 < n) n2 <<= 1;
		lazy.resize(n2 * 2, -1);
		sum.resize(n2 * 2, 0);
		l.resize(n2 * 2);
		r.resize(n2 * 2);
		for (int i = n2 - 1; i < n2 * 2 - 1; i++)
		{
			l[i] = r[i] = i - (n2 - 1);
			if (l[i] < n) sum[i] = (f[l[i]] - '0');
		}
		for (int i = n2 - 2; i >= 0; i--)
		{
			l[i] = l[i * 2 + 1];
			r[i] = r[i * 2 + 2];
			sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
		}
	}
	void set(int li, int ri, int val, int vr = 0)
	{
		if (li > r[vr] || ri < l[vr]) return;
		if (li <= l[vr] && r[vr] <= ri)
		{
			sum[vr] = val * (r[vr] - l[vr] + 1);
			lazy[vr] = val;
			return;
		}
		unlazy(vr);
		set(li, ri, val, vr * 2 + 1);
		set(li, ri, val, vr * 2 + 2);
		sum[vr] = sum[vr * 2 + 1] + sum[vr * 2 + 2];
	}
	int sum1(int li, int ri, int vr = 0)
	{
		if (li > r[vr] || ri < l[vr]) return 0;
		if (li <= l[vr] && r[vr] <= ri) return sum[vr];
		unlazy(vr);
		return sum1(li, ri, vr * 2 + 1) + sum1(li, ri, vr * 2 + 2);
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		string s, f;
		cin >> s >> f;
		segment_tree st(n, f);
		vector<int> l(q), r(q);
		for (int i = 0; i < q; i++) cin >> l[i] >> r[i];
		bool bad = false;
		for (int i = q - 1; i >= 0; i--)
		{
			int sum1 = st.sum1(--l[i], --r[i]), half = (r[i] - l[i]) / 2;
			if (sum1 <= half) st.set(l[i], r[i], 0);
			else if ((r[i] - l[i] + 1) - sum1 <= half) st.set(l[i], r[i], 1);
			else
			{
				bad = true;
				break;
			}
		}
		if (!bad)
		{
			for (int i = 0; i < n; i++)
			{
				if (s[i] - '0' != st.sum1(i, i))
				{
					bad = true;
					break;
				}
			}
		}
		cout << (bad ? "NO\n" : "YES\n");
	}
	return 0;
}