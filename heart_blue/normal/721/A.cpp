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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int n;
	cin >> n;
	cin >> str;
	str = "W" + str + "W";
	vector<int> ans;
	int cnt = 0;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i - 1])
		{
			if (str[i] == 'W') cnt = 0;
			else cnt++;
		}
		else
		{
			if (str[i] == 'W')
			{
				ans.push_back(cnt);
				cnt = 0;
			}
			else
			{
				cnt = 1;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}