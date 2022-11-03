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
const int N = 1e6 + 10;
int a[N], b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '8' || str[i] == '0')
		{
			cout << "YES" << endl;
			cout << str[i] << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int x = str[i] - '0';
			int y = str[j] - '0';
			if ((x * 10 + y) % 8 == 0)
			{
				cout << "YES" << endl;
				cout << x * 10 + y << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n;j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int x = str[i] - '0';
				int y = str[j] - '0';
				int z = str[k] - '0';
				int tot = x * 100 + y * 10 + z;
				if (tot % 8 == 0)
				{
					cout << "YES" << endl;
					cout << tot << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}