#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[N];
void add(vector<int>& v1, vector<int>& v2)
{
	for (auto& x : v2)
		v1.push_back(x);
}
int ask(int l1, int r1, int l2 = 0, int r2 = -1)
{
	int sz = 0;
	vector<int> key;
	for (int i = l1; i <= r1; i++)
		add(key, v[i]);
	for (int i = l2; i <= r2; i++)
		add(key, v[i]);
	sort(key.begin(), key.end());
	key.resize(unique(key.begin(), key.end()) - key.begin());
	if (key.empty()) return 0;
	cout << "? " << key.size();
	for (auto& x : key)
		cout << " " << x;
	cout << endl;
	int ret;
	cin >> ret;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= k; i++)
		{
			v[i].clear();
			int sz;
			scanf("%d", &sz);
			v[i].resize(sz);
			for (auto& x : v[i])
				cin >> x;
		}

		int l = 1, r = k;
		int id = 1;
		int maxv1 = ask(1, k);
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (ask(l, mid) == maxv1) id = mid, r = mid - 1;
			else l = mid + 1;
		}
		int maxv2 = 0;
		{
			set<int> s;
			for (int i = 1; i <= n; i++)
				s.insert(i);
			for (auto& x : v[id])
				s.erase(x);
			if (s.size() != 0)
			{
				cout << "? " << s.size();
				for (auto& x : s)
					cout << ' ' << x;
				cout << endl;
				cin >> maxv2;
			}
		}
		if (maxv2 >= maxv1)
			maxv1 = maxv2;
		cout << "! ";
		for (int i = 1; i <= k; i++)
		{
			if (i == id) cout << maxv2;
			else cout << maxv1;
			if (i == k) cout << endl;
			else cout << ' ';
		}
		string str;
		cin >> str;
		if (str == "Incorrect") break;
	}
	return 0;
}