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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int flag = 0;
		for (int i = 1; i <= s1.length(); i++)
		{
			string s3 = s1.substr(0, i);
			reverse(s3.begin(), s3.end());
			s3 = s1.substr(0, i - 1) + s3;
			if (s3.find(s2) != s3.npos)
			{
				flag = 1;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}