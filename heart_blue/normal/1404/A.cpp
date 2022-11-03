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
bool check(string& str, int k)
{
	int tot0 = 0, tot1 = 0;
	for (int i = 0; i < k; i++)
	{
		int cnt0 = 0, cnt1 = 0;
		for (int j = i; j < str.length(); j += k)
		{
			if (str[j] == '0') cnt0++;
			if (str[j] == '1') cnt1++;
		}
		if (cnt0 > 0 && cnt1 > 0) return false;
		if (cnt0 > 0) tot0++;
		if (cnt1 > 0) tot1++;
	}
	if (tot0 > k / 2 || tot1 > k / 2) return false;
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		string str;
		cin >> n >> k >> str;
		if (check(str, k)) puts("YES");
		else puts("NO");
	}
	return 0;
}