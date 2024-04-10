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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
char str[N];
LL lsum[N], rsum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	str[0] = '+';
	str[n + 1] = '+';
	vector<LL> v;
	for (int i = 1; i <= n; i += 2)
	{
		if (str[i - 1] == '+')
		{
			LL tot = 0;
			for (auto& x : v)
				tot += x;
			v.clear();
			v.push_back(tot);
			v.push_back(str[i] - '0');
		}
		else
		{
			if (v.empty()) v.push_back(1);
			v.back() *= str[i] - '0';
		}
		LL sum = 0;
		for (auto& x : v)
			sum += x;
		lsum[i] = sum;
	}
	v.clear();
	for (int i = n; i >= 1; i -= 2)
	{
		if (str[i + 1] == '+')
		{
			LL tot = 0;
			for (auto& x : v)
				tot += x;
			v.clear();
			v.push_back(tot);
			v.push_back(str[i] - '0');
		}
		else
		{
			if (v.empty()) v.push_back(1);
			v.back() *= str[i] - '0';
		}
		LL sum = 0;
		for (auto& x : v)
			sum += x;
		rsum[i] = sum;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i += 2)
	{
		LL lcur = 1;
		LL lkey = 0;
		for (int j = i; j >= 1; j -= 2)
		{
			if (str[j - 1] == '*') lcur *= str[j - 2] - '0';
			else if (j - 2 >= 0)
			{
				lkey = lsum[j - 2];
				break;
			}
		}
		vector<LL> v;
		for (int j = i; j <= n; j += 2)
		{
			if (str[j - 1] == '+' || j == i)
			{
				LL tot = 0;
				for (auto& x : v)
					tot += x;
				v.clear();
				v.push_back(tot);
				v.push_back(str[j] - '0');
			}
			else
			{
				if (v.empty()) v.push_back(1);
				v.back() *= str[j] - '0';
			}
			LL sum = 0;
			for (auto& x : v)
				sum += x;
			LL rcur = 1;
			LL rkey = 0;
			for (int k = j; k <= n; k += 2)
			{
				if (str[k + 1] == '*') rcur *= str[k + 2] - '0';
				else
				{
					rkey = rsum[k + 2];
					break;
				}
			}
			//cout << i << ' ' << j << ' ' << lcur << ' ' << lkey << ' ' << rcur << ' ' << rkey << endl;
			//cout << sum * rcur * lcur + lkey + rkey << endl;
			ans = max(ans, sum * rcur * lcur + lkey + rkey);
		}
	}
	printf("%lld\n", ans);
	return 0;
}