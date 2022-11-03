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
	int n = str.length();
	reverse(str.begin(), str.end());
	str.push_back('0');
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '2') str[i] = '0', str[i + 1]++;
		if (i == n - 1&& str[i] == '1') break;
		cnt++;
		if (str[i] == '1') cnt++, str[i + 1]++;
	}
	cout << cnt << endl;
	return 0;
}