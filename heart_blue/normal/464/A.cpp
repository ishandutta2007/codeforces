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
const int N = 1e5 + 10;
int n, p;
char check(char c, char c1 = 0, char c2 = 0)
{
	for (int i = 0; i < 26; i++)
	{
		c++;
		if (c >= p + 'a') return 0;
		if (c == c1 || c == c2) continue;
		return c;
	}
	return 0;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> n >> p >> str;
	for (int i = n - 1; i >= 0; i--)
	{
		char c = check(str[i], i >= 1 ? str[i - 1] : 0, i >= 2 ? str[i - 2] : 0);
		if (c != 0)
		{
			str[i] = c;
			for (int j = i + 1; j < n; j++)
			{
				str[j] = check('a' - 1, j >= 1 ? str[j - 1] : 0, j >= 2 ? str[j - 2] : 0);
			}
			cout << str << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}