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
char getnext(char c1, char c2)
{
	char ret;
	string rgb = "RGB";
	for (auto &c : rgb)
	{
		if (c == c1) continue;
		if (c == c2) continue;
		ret = c;
		break;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n;
	cin >> str;
	int ans = 0;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i-1])
		{
			str[i] = getnext(str[i-1], i + 1 == str.length()?str[i-1]:str[i+1]);
			ans++;
		}
	}
	cout << ans << endl;
	cout << str << endl;
	return 0;
}