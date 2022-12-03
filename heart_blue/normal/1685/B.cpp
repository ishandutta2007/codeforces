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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int refrain(int& cnt, vector<int>& v)
{
	for (auto& x : v)
	{
		if (cnt == 0) break;
		if (x == 1)
		{
			cnt--;
			x = 0;
		}
	}
	sort(v.rbegin(), v.rend());
	while (!v.empty() && v.back() <= 1)
		v.pop_back();
	int ret = 0;
	for (auto& x : v)
		ret += x;
	return ret;
}
bool check(int ab, int ba, vector<int>& vab, vector<int>& vba, int sum)
{
	int rab = refrain(ab, vab);
	int rba = refrain(ba, vba);
	ba -= rba;
	for (int i = 0; i <= vab.size(); i++)
	{
		if (max(0, ab - rab) + max(0, ba) <= sum)
		{
			return true;
		}
		if (i == vab.size()) break;
		ba--;
		rab -= vab[i];
		sum += vab[i] - 2;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, ab, ba;
		scanf("%d%d%d%d", &a, &b, &ab, &ba);
		string str;
		cin >> str;
		if (count(str.begin(), str.end(), 'A') != a + ab + ba)
		{
			puts("NO");
			continue;
		}
		str += str.back();
		int sum0 = 0;
		vector<int> vab, vba;
		int cnt = 1;
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == str[i - 1])
			{
				if (cnt & 1) sum0 += cnt / 2;
				else if (str[i] == 'A') vba.push_back(cnt / 2);
				else vab.push_back(cnt / 2);
				cnt = 1;
			}
			else cnt++;
		}
		int rab = refrain(ab, vab);
		int rba = refrain(ba, vba);
		if (ab > rab + rba - vba.size() + sum0 ||
			ba > rab + rba - vab.size() + sum0 ||
			ab + ba > rab + rba + sum0)
		{
			puts("NO");
			continue;
		}
		if (ab == 0 || ba == 0)
		{
			puts("YES");
			continue;
		}
		if (check(ab, ba, vab, vba, sum0) ||
			check(ba, ab, vba, vab, sum0))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}