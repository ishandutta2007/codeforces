#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
string s;
int cal(string s)
{
	vector<int> a(26);
	for (auto c : s)
		a[c - 'a'] = 1;
	return accumulate(all(a), 0);
}
int cnt1, cnt2;
char ask1(int x)
{
	++cnt1;
	cout << "? 1 " << x + 1 << endl;
	// return s[x]; //
	char c;
	cin >> c;
	return c;
}
int ask2(int l, int r)
{
	++cnt2;
	// assert(l < r && l >= 0 && r <= s.size());
	cout << "? 2 " << l + 1 << ' ' << r << endl;
	// return cal(s.substr(l, r - l)); //
	cin >> l;
	return l;
}
void answer(const string &S)
{
	cout << "! " << S << endl;
	// assert(s == S);
	exit(0);
}
struct Q
{
	int l, r;
};
mt19937 rnd(99824);
const int S = 26;
int main()
{
	ios::sync_with_stdio(0);
	int n, m, i, j;
	cin >> n;
	// s.resize(n);
	// for (auto &c : s)
	//	c = rnd() % S + 'a';
	// cerr << s << endl;
	vector<Q> a(n);
	for (i = 0; i < n; i++)
		a[i] = {i, i + 1};
	m = a.size();
	vector<int> pre(m, -1);
	vector<char> col(m);
	set<int> q{0};
	int cur = 1;
	for (j = 1; j < m;)
	{
		int now = ask2(a[*q.begin()].l, a[j].r);
		if (now == cur)
		{
			// cerr << "111 " << j << '\n';
			vector<int> pos(all(q));
			pos.push_back(j);
			int l = 0, r = pos.size() - 2;
			while (l < r)
			{
				int mid = l + r >> 1;
				if (ask2(a[pos[mid + 1]].l, a[j].r) + mid + 1 == now)
					l = mid + 1;
				else
					r = mid;
			}
			pre[j] = pos[l];
			// cerr << pos[l] << '\n';
			q.erase(pos[l]);
			q.insert(j);
			++j;
		}
		else
		{
			// cerr << "222 " << j << '\n';
			q.insert(j);
			++j;
			++cur;
		}
	}
	assert(cur <= 26);
	for (auto x : q)
		col[x] = ask1(a[x].l);
	for (i = m - 1; i >= 0; i--)
		if (pre[i] != -1)
			col[pre[i]] = col[i];
	string s;
	for (i = 0; i < m; i++)
	{
		int len = a[i].r - a[i].l;
		for (j = 0; j < len; j++)
			s += col[i];
	}
	// cerr << cnt1 << ' ' << cnt2 << '\n';
	assert(cnt1 <= 26 && cnt2 <= 6000);
	// assert(s.size() == 5);
	answer(s);
}