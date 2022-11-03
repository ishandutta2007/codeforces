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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int zeros(string &s)
{
	int sum = 0;
	for (auto &c : s) if (c == '0') sum++;
	return sum;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int flag0 = 0;
	string key = "1";
	int n;
	cin >> n;
	string str;
	int sum = 0;
	while (n--)
	{
		cin >> str;
		if (str == "0")
		{
			flag0 = 1;
			break;
		}
		int cnt = zeros(str);
		if (cnt + 1 != str.length() || str[0] != '1') key = str;
		else sum += cnt;
	}
	if (flag0)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << key << string(sum, '0');
	return 0;
}