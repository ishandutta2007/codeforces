#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>

using namespace std;

const double pi = 3.14159265358979323846;

long long maxd = 1, bound = 1e5;
int inf = int(1e9) + 7;

int up(int n)
{
	int ret = 1;

	while (ret < n)
		ret <<= 1;

	return ret;
}

class segtree
{
	vector<int> arr;
	int n;

	void mad(int p, int x)
	{
		while (p > 0)
		{
			arr[p] += x;
			p >>= 1;
		}
	}

	int mum(int l, int r, int cl, int cr, int pos)
	{
		if (cr <= l || r <= cl)
			return 0;

		if (l <= cl && cr <= r)
			return arr[pos];

		int t = (cl + cr) / 2;

		return mum(l, r, cl, t, 2 * pos) + mum(l, r, t, cr, 2 * pos + 1);
	}

public:
	segtree(int siz) : arr(2 * up (siz)), n (up (siz))
	{}

	void add(int p, int x)
	{
		mad(p + n, x);
	}

	int sum(int l, int r)
	{
		return mum(l, r, 0, n, 1);
	}
};

void add_char(vector<vector<vector<segtree>>> &ch, int pos, int type, int diff = 1)
{
	for (int i = 0; i < 10; i++)
		ch[type][i][pos % (i + 1)].add(pos / (i + 1), diff);
}

const string obr = "ATGC";

int main()
{
	ios_base::sync_with_stdio(false);

	string str;

	cin >> str;

	int n = 1;

	while (n < str.size())
		n <<= 1;

	vector<vector<vector<segtree>>> ch (4, vector<vector<segtree>> (10));

	for (int i = 0; i < 10; i++)
		for (int j = 0; j <= i; j++)
			for (auto &it : ch)
				it[i].push_back(segtree((n + i) / (i + 1)));

	for (int i = 0; i < str.size(); i++)
		add_char(ch, i, obr.find(str[i]));

	int q;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int t;

		cin >> t;

		if (t == 1)
		{
			int p;
			char c;

			cin >> p >> c;

			p--;

			add_char(ch, p, obr.find(str[p]), -1);
			add_char(ch, p, obr.find(c));
			str[p] = c;
		}
		else
		{
			int l, r;
			string s;

			cin >> l >> r >> s;

			l--;

			int ans = 0;

			for (int i = 0; i < s.size(); i++)
				ans += ch[obr.find(s[i])][s.size() - 1][(l + i) % s.size()].sum((l + i) / s.size (),
																				(r - i - l + s.size () - 1) / s.size () + (l + i) / s.size());

			cout << ans << endl;
		}
	}

	return 0;
}