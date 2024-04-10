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
const int N = 2e2 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	for (int i = n - 1; i >= 0; i--)
	{
		v[str[i]].push_back(i);
	}
	for (int i = 'a'; k > 0 && i <= 'z'; i++)
	{
		while (k > 0 && !v[i].empty())
		{
			k--;
			str[v[i].back()] = '0';
			v[i].pop_back();
		}
	}
	for (auto &c : str) if (isalpha(c)) putchar(c);
	return 0;
}