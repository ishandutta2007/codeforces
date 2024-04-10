#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


using pnt = complex<int>;


ll operator%(const pnt &a, const pnt &b)
{
	return a.real() * (ll) b.imag() - a.imag() * (ll) b.real();
}


ll operator&(const pnt &a, const pnt &b)
{
	return a.real() * (ll) b.real() + a.imag() * (ll) b.imag();
}


ll len2(const pnt &a)
{
	return a & a;
}


using ld = long double;


ld len(const pnt &a)
{
	return sqrtl(len2(a));
}

namespace std
{
	bool operator<(const pnt &a, const pnt &b)
	{
		if (a.real() != b.real())
			return a.real() < b.real();
		return a.imag() < b.imag();
	}
}


ld solve_offline(const pnt &offline, const vector<pnt> &online, size_t l, size_t r)
{
	if (r <= l)
		return 0;

	return len(online[r - 1] - online[l]) + min(len(offline - online[l]), len(offline - online[r - 1]));
}


ld solve_offline(const pnt &offline, const vector<pnt> &online, size_t st = 0)
{
	return solve_offline(offline, online, st, online.size());
}


template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


ld solve_half(const pnt &offline, const vector<pnt> &online, int ind)
{
	vector<ld> suff(online.size());

	suff.back() = len(online.back() - offline);
	for (int j = (int) suff.size() - 2; j >= 0; j--)
		suff[j] = min(len(online[j] - online[j + 1]) + suff[j + 1],
		              len(online[j] - offline) + solve_offline(offline, online, j + 1));

	ld ans = numeric_limits<ld>::max();

	for (int j = ind; j + 1 < online.size(); j++)
	{
		auto right = len(online[j] - online[ind]);
		auto left = len(online[j] - online.front());
		auto to_nxt = len(online[j + 1] - online.front());
		auto to_off = len(offline - online.front());

		remin(ans,
		      min(right + left + to_nxt + suff[j + 1],
		          right + left + to_off + solve_offline(offline, online, j + 1)));
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;
	k--;

	vector<pnt> arr(n);

	for (auto &it: arr)
	{
		int x, y;

		cin >> x >> y;

		it = {x, y};
	}

	pnt st = arr[k];

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	assert(arr.size() >= 3);

	pair<pnt, pnt> line;

	bool ok = false;

	for (int i = 0; !ok && i < 3; i++)
		for (int j = 0; !ok && j < i; j++)
		{
			assert(arr[i] != arr[j]);

			line = {arr[j], arr[i]};

			int cnt = 0;

			for (const auto &it: arr)
				if ((it - line.first) % (line.second - line.first) == 0)
					cnt++;

			ok = (cnt == arr.size() - 1);
		}

	assert(ok);

	vector<pnt> online;
	pnt offline;

	for (const auto &it: arr)
		if ((it - line.first) % (line.second - line.first) == 0)
			online.push_back(it);
		else
			offline = it;

	sort(online.begin(), online.end());

	cout << fixed << setprecision(numeric_limits<ld>::digits10);

	if (st == offline)
	{
		cout << solve_offline(offline, online) << endl;

		return;
	}

	int ind = 0;

	while (online[ind] != st)
		ind++;

	auto ans = len(offline - online[ind]) + solve_offline(offline, online);

	remin(ans, solve_half(offline, online, ind));
	reverse(online.begin(), online.end());
	ind = online.size() - 1 - ind;
	remin(ans, solve_half(offline, online, ind));

	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}