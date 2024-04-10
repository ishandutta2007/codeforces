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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tot = 0;
	for (int i = 1; i <= 10; i++)
	{
		cout << (i + 13) % 10 << endl;
		string str;
		getline(cin, str);
		if (str.length() == 2)
		{
			tot++;
			if (tot > 3)
			{
				cout << "normal" << endl;
				return 0;
			}
			continue;
		}
		if (str.length() == 6)
		{
			if (str[0] == 'n')
			{
				cout << "grumpy" << endl;
			}
			else
			{
				cout << "normal" << endl;
			}
			return 0;
		}
		if (str.length() == 7)
		{
			cout << "normal" << endl;
			return 0;
		}
		if (str.length() == 4)
		{
			cout << "normal" << endl;
			return 0;
		}
		if (str.length() == 15)
		{
			cout << "normal" << endl;
			return 0;
		}
		if (str.length() == 14)
		{
			cout << "normal" << endl;
			return 0;
		}
		cout << "grumpy" << endl;
		return 0;
	}
	return 0;
}