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
#include <cassert>
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
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v, v1, v2;
	int m;
	cin >> m;
	while (m--)
	{
		int cost;
		string type;
		cin >> cost >> type;
		if (type == "USB") v1.push_back(cost);
		else v2.push_back(cost);
	}
	int cnt = 0;
	LL tot = 0;
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++)
	{
		if (i < a)
		{
			cnt++;
			tot += v1[i];
		}
		else
		{
			v.push_back(v1[i]);
		}
	}
	for (int i = 0; i < v2.size(); i++)
	{
		if (i < b)
		{
			cnt++;
			tot += v2[i];
		}
		else
		{
			v.push_back(v2[i]);
		}
	}
	if (!v.empty())
		sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (i < c)
		{
			cnt++;
			tot += v[i];
		}
	}
	cout << cnt << ' ' << tot << endl;
	return 0;
}