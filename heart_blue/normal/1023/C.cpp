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
	int n, k;
	cin >> n >> k;
	string str;
	string ans;
	cin >> str;
	int o = 0;
	for (auto &c : str)
	{
		if (k == 0) break;
		if (c == '(') ans.push_back('('), o++, k--;
		else
		{
			if (o == 0) continue;
			o--;
			k--;
			ans.push_back(')');
		}
		if (o == k)
		{
			while (k--) ans.push_back(')');
			break;
		}
	}
	cout << ans << endl;
	return 0;
}