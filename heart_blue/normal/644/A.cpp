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
const int N = 2e3;

int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	if (n > a * b)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> v1, v2;
	for (int i = 1; i <= n; i += 2) v1.push_back(i);
	for (int i = 2; i <= n; i += 2) v2.push_back(i);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (((i + j) & 1) == 0)
			{
				if (v1.empty()) cout << '0';
				else
				{
					cout << v1.back();
					v1.pop_back();
				}
			}
			else
			{
				if (v2.empty()) cout << '0';
				else
				{
					cout << v2.back();
					v2.pop_back();
				}
			}
			cout << (j == (b - 1) ? '\n' : ' ');
		}
	}
	return 0;
}