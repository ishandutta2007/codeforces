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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int n;
	cin >> n;
	cin >> str;
	if (count(str.begin(), str.end(), str[0]) == str.length())
	{
		cout << str.substr(1) << endl;
		return 0;
	}
	else
	{
		string ans = str.substr(0, n - 1);
		for (int i = 0; i + 1 < n; i++)
		{
			if (str[i] > str[i + 1])
			{
				ans = min(ans, str.substr(0, i) + str.substr(i + 1));
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}