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
const int N = 4e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v1, v2;
	int ans = 0;
	int n;
	cin >> n;
	int cur = 0;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 1 || op == 3 || op == 5)
		{
			if (op == 1)
			{
				cin >> cur;
			}
			if (op == 3)
			{
				int x;
				cin >> x;
				v1.push_back(x);
			}
			if (op == 5) v1.push_back(INF);
			while (!v1.empty() && v1.back() < cur) v1.pop_back(), ans++;
		}
		else
		{
			if (op == 2)
			{
				while (!v2.empty() && v2.back() == 6) v2.pop_back(), ans++;
			}
			else v2.push_back(op);
		}
	}
	cout << ans << endl;
	return 0;
}