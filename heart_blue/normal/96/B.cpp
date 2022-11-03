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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
void refrain(string &str)
{
	if (str.length() % 2 == 1)
	{
		int o = (str.length() + 1) / 2;
		str = string(o, '4') + string(o, '7');
		return;
	}
	int l = str.length();
	for (int i = 0; i < l; i++)
	{
		if (str[i] == '4' || str[i] == '7') continue;
		if (str[i] > '7')
		{
			int c = 1;
			str[i] = '4';
			for (int j = i + 1; j < l; j++) str[i] = '4';
			for (int j = i - 1; j >= 0; j--)
			{
				if (str[j] >= '7') str[j] = '4', c = 1;
				else if(str[j] >= '4') str[j] = '7', c = 0;
				else str[j] = '4', c = 0;
				if (c == 0) break;
			}
			if (c == 1)
			{
				l++;
				if (l & 1) l++;
				int o = l / 2;
				str = string(o, '4') + string(o, '7');
				return;
			}
		}
		else if (str[i] > '4')
		{
			str[i] = '7';
			for (int j = i + 1; j < l; j++) str[j] = '4';
		}
		else
		{
			str[i] = '4';
			for (int j = i + 1; j < l; j++) str[j] = '4';
		}

	}
	int a4 = 0, a7 = 0;
	int key = -1;
	for (int i = 0; i < l; i++)
	{
		if (str[i] == '4')
		{
			if (a4 <= l / 2 && a7 + 1 <= l / 2) key = i;
		}
		if (str[i] == '4') a4++;
		else a7++;
	}
	if (a4 == a7) return;
	if (key == -1)
	{
		int o = l / 2 + 1;
		str = string(o, '4') + string(o, '7');
		return;
	}
	a4 = a7 = 0;
	for (int i = 0; i < key; i++)
	{
		if (str[i] == '4') a4++;
		else a7++;
	}
	str[key++] = '7';
	a7++;
	while (a4++ < l / 2) str[key++] = '4';
	while (a7++ < l / 2) str[key++] = '7';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	refrain(str);
	cout << str << endl;
	return 0;
}