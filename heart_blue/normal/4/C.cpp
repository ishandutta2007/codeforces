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
const int N = 1E7;
map<string, int> ms;
string num2str(int n)
{
	string str;
	while (n)
	{
		str.push_back(n % 10 + '0');
		n /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);

	string str;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str;
		if (!ms.count(str))
		{
			cout << "OK" << endl;
			ms[str] = 1;
		}
		else
		{

			cout << str << ms[str] << endl;
			ms[str + num2str(ms[str]++)] = 1;
		}
	}
	return 0;
}