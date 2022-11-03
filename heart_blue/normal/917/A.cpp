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
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int l = 0, r = 0;
		for (int j = i; j < str.length(); j++)
		{
			if (str[j] == '(') l++, r++;
			else if (str[j] == ')') l--, r--;
			else l--, r++;
			if (r < 0) break;
			if (l < 0) l += 2;
			if (l == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}