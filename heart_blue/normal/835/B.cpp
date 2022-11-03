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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> k;
	string s;
	cin >> s;
	int sum = 0;
	for (auto &c : s)
	{
		sum += c - '0';
		a[c - '0']++;
	}
	int ans = 0;
	if (k > sum)
	{
		for (int i = 0; i < 10; i++)
		{
			while (a[i]--)
			{
				if (k <= sum) break;
				sum += 9 - i;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}