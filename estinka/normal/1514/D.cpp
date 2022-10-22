#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <random>
#include <chrono>
#include <algorithm>
typedef long long ll;
using namespace std;

const int iter = 60;
int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	vector<vector<int> > o(n);
	for (int i = 0; i < n; i++) o[a[i]].push_back(i);
	while (q--)
	{
		int l, r; 
		cin >> l >> r; l--, r--;
		int half = (r - l + 2) / 2;
		int big = -1;
		for (int i = 0; i < iter; i++)
		{
			int x = a[rng() % (r - l + 1) + l];
			int cnt = upper_bound(o[x].begin(), o[x].end(), r) - lower_bound(o[x].begin(), o[x].end(), l);
			if (cnt > half)
			{
				big = cnt;
				break;
			}
		}
		if (big == -1) cout << "1\n";
		else
		{
			int rest = (r - l + 1) - big;
			cout << big - rest << "\n";
		}
	}
	return 0;
}