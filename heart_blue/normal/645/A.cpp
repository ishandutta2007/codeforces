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

string comb(string s1, string s2)
{
	reverse(s2.begin(), s2.end());
	string str = s1 + s2;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'X')
		{
			str = str.substr(0, i) + str.substr(i + 1);
			break;
		}

	}
	return str;

}
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str1, str2;
	string s1, s2;
	cin >> s1 >> s2;
	str1 = comb(s1, s2);
	cin >> s1 >> s2;
	str2 = comb(s1, s2);
	string ans = "NO";
	for (int i = 0; i < 3; i++)
	{
		str1 = str1.substr(2) + str1.substr(0, 2);
		if (str1 == str2)
		{
			ans = "YES";
		}
	}
	cout << ans << endl;
	return 0;
}