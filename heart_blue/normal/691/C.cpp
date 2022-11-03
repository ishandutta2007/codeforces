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
	if (str.find('.') == string::npos) str.push_back('.');
	int o = str.find('.');
	int cnt = count(str.begin(), str.begin() + o + 1, '0');
	int tot = 0;
	if (cnt == o)
	{
		for (int i = o; i + 1 < str.length(); i++)
		{
			swap(str[i], str[i + 1]);
			tot--;
			if (str[i] != '0') break;
		}
	}
	str = str.substr(str.find_first_not_of('0'));
	o = str.find('.');
	for (int i = o; i - 1 > 0; i--)
	{
		swap(str[i], str[i - 1]);
		tot++;
	}
	str = str.substr(0, str.find_last_not_of('0') + 1);
	if (str.back() == '.') str.pop_back();
	printf(str.c_str());
	if (tot != 0) printf("E%d\n", tot);

	return 0;
}