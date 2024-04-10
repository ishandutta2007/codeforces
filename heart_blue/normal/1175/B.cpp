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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];
set<int> s[N];
void check(LL sum)
{
	if (sum >= (1LL << 32)) puts("OVERFLOW!!!"), exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	vector<LL> v;
	v.push_back(0);
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		v.push_back(0);
		if (str == "end")
		{
			LL sum = 0;
			while (!v.empty())
			{
				if (v.back() < 0)
				{
					sum *= -v.back();
					v.pop_back();
					v.push_back(sum);
					break;
				}
				else
				{
					sum += v.back();
					v.pop_back();
				}
				check(sum);
			}
		}
		if (str == "for")
		{
			int x;
			cin >> x;
			v.push_back(-x);
		}
		if (str == "add")
		{
			v.push_back(1);
		}
	}
	LL sum = 0;
	for (auto& x : v)
	{
		sum += x;
		check(sum);
	}
	cout << sum << endl;
	return 0;
}