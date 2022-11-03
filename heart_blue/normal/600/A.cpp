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
const int N = 2e5 + 10;

bool check(string &s)
{
	if (s.empty()) return false;
	for (auto c : s) if (!isdigit(c)) return false;
	if (s.length() > 1 && s[0] == '0') return false;
	return true;
}

void output(vector<string> &vs)
{
	if (vs.empty()) cout << "-" << endl;
	else
	{
		cout << "\"";
		for (int i = 0; i < vs.size(); i++)
		{
			cout << vs[i] << ",\""[i == vs.size() - 1];
		}
		cout << endl;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	str.push_back(';');
	for (auto &c : str) if (c == ',') c = ';';
	int pre = -1;
	vector<string> v1, v2;
	while (1)
	{
		int o = str.find(';', pre + 1);
		if (o == -1) break;
		string s = str.substr(pre + 1, o - pre - 1);
		if (check(s)) v1.push_back(s);
		else v2.push_back(s);
		pre = o;
	}
	output(v1);
	output(v2);

	return 0;
}