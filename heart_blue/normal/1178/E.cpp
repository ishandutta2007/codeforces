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
const int N = 1e6 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int l = 1, r = n;
	string ans1, ans2;
	while (l <= r)
	{
		if (str[l] == str[r])
		{
			ans1.push_back(str[l]);
			if(l != r) ans2.push_back(str[r]);
			l++, r--;
			continue;
		}
		if (r - l <= 2)
		{
			ans1.push_back(str[l]);
			l = r + 1;
			continue;
		}
		int flag = 1;
		for (int i = 0; i < 2 && flag; i++)
		{
			for (int j = 0; j < 2 && flag; j++)
			{
				if (str[l + i] == str[r - j])
				{
					ans1.push_back(str[l + i]);
					ans2.push_back(str[r - j]);
					l = l + i + 1;
					r = r - j - 1;
					flag = 0;
				}
			}
		}
	}
	reverse(ans2.begin(), ans2.end());
	cout << ans1 << ans2 << '\n';
	return 0;
}