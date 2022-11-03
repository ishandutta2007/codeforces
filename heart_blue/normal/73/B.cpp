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
vector<string> vs;
int solve1(vector<int> v1, vector<int> v2)
{
	int n = v1.size();
	sort(v2.rbegin(), v2.rend());
	int ret = 0;
	int cur = v1[0] + v2[0];
	v1.erase(v1.begin());
	v2.erase(v2.begin());
	sort(v1.rbegin(), v1.rend());
	int low = 0;
	for (auto& x : v1)
	{
		if (x + v2.back() <= cur)
		{
			low++;
			v2.pop_back();
		}
	}
	return n - low;
}
int solve2(vector<int> v1, vector<int> v2)
{
	int n = v1.size();
	sort(v2.begin(), v2.end());
	int ret = 0;
	int cur = v1[0] + v2[0];
	v1.erase(v1.begin());
	v2.erase(v2.begin());
	sort(v1.begin(), v1.end());
	int up = 0;
	for (auto& x : v1)
	{
		if (x + v2.back() > cur)
		{
			up++;
			v2.pop_back();
		}
	}
	return up + 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	vector<int> v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		int val;
		cin >> str >> val;
		vs.push_back(str);
		v1.push_back(val);
	}
	v2.resize(n, 0);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		cin >> v2[i];
	}
	string key;
	cin >> key;
	for (int i = 0; i < n; i++)
	{
		if (vs[i] < key)
			v1[i]++;
		if (vs[i] == key)
			swap(v1[i], v1[0]);
	}
	printf("%d %d\n", solve1(v1, v2), solve2(v1, v2));
	return 0;
}