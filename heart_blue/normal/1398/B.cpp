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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		vector<int> v;
		cin >> str;
		str.push_back('0');
		int cnt = 0;
		for (auto& c : str)
		{
			if (c == '1') cnt++;
			else
			{
				v.push_back(cnt);
				cnt = 0;
			}
		}
		sort(v.rbegin(), v.rend());
		int ans = 0;
		for (int i = 0; i < v.size(); i += 2)
		{
			ans += v[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}