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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		vector<int> ans;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != '0')
				ans.push_back(stoi(str[i] + (string(str.length() - i - 1, '0'))));
		}
		printf("%d\n", ans.size());
		for (auto& x : ans) printf("%d ", x);
		puts("");
	}
	return 0;
}