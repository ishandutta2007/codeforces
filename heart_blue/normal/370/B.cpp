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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
vector<int> v[N];
int ans[N];
bool contain(vector<int> &v1, vector<int> &v2)
{
	int ptr = 0;
	int cnt = 0;
	for (auto &x : v2)
	{
		while (ptr < v1.size() && v1[ptr] < x) ptr++;
		if (ptr == v1.size()) break;
		if (v1[ptr] == x)
		{
			cnt++;
			ptr++;
		}
	}
	return cnt == v2.size();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v[i].resize(m);
		for (auto &x : v[i]) cin >> x;
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < n; i++) ans[i] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (contain(v[i], v[j]))
			{
				ans[i] = 0;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) puts(ans[i] ? "YES" : "NO");
	return 0;
}