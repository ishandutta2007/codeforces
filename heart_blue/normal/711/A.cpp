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
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int flag = 0;
	while (n--)
	{
		string str;
		cin >> str;
		int o = str.find("OO");
		if (!flag && o != -1) str[o] = str[o + 1] = '+', flag = 1;
		vs.push_back(str);
	}
	if (flag == 1)
	{
		cout << "YES" << endl;
		for (auto &str : vs)
		{
			cout << str << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}