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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
vector<int> even, odd;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, p;
	cin >> n >> k >> p;
	int ptr1 = 0;
	int ptr2 = p;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x & 1)
		{
			if (ptr2 < k) v[ptr2++].push_back(x);
			else odd.push_back(x);
		}
		else
		{
			if (ptr1 < p) v[ptr1++].push_back(x);
			else even.push_back(x);
		}
	}
	while (ptr1 < p && odd.size() >= 2)
	{
		v[ptr1].push_back(odd.back());
		odd.pop_back();
		v[ptr1].push_back(odd.back());
		odd.pop_back();
		ptr1++;
	}
	if (ptr1 < p || ptr2 < k || odd.size() % 2 == 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (auto &x : odd) v[0].push_back(x);
	for (auto &x : even) v[0].push_back(x);
	for (int i = 0; i < k; i++)
	{
		cout << v[i].size();
		for (auto &x : v[i]) cout << ' ' << x;
		cout << '\n';
	}
	return 0;
}