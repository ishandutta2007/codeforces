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
int fail[N];
int cur[N];
vector<string> vs1;
vector<string> vs2;

int getans()
{
	int sz = vs2.size() - 1;
	cur[0] = 0;
	vector<string> vs;
	vs.push_back("");
	int flag = 0;
	int ans = 0;
	for (int i = 1; i < vs1.size(); i++)
	{
		if (flag == 1)
		{
			flag = 0;
			vs.pop_back();
			i--;
			continue;
		}
		string& str = vs1[i];
		if (str.front() == '/')
		{
			vs.pop_back();
			flag = 0;
			continue;
		}
		int j = cur[vs.size() - 1];
		if (str.back() == '/')
		{
			flag = 1;
			vs.push_back(str.substr(0, str.length() - 1));
		}
		else
		{
			vs.push_back(str);
		}
		if (vs2[j + 1] == vs.back()) j++;
		if (j == sz)
		{
			ans++;
			j--;
		}
		cur[vs.size() - 1] = j;
	}
	return ans;
}
void build(vector<string>& vs, string& str)
{
	vs.clear();
	vs.push_back("");
	stringstream sin(str);
	while (sin >> str)
	{
		vs.push_back(str);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	getline(cin, str);
	for (auto& c : str)
	{
		if (c == '<') c = ' ';
		if (c == '>') c = ' ';
	}
	build(vs1, str);
	int n;
	cin >> n;
	getline(cin, str);
	while (n--)
	{
		getline(cin, str);
		build(vs2, str);
		printf("%d\n", getans());
	}
	return 0;
}