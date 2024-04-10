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
const int N = 1e2 + 10;
vector<string> vs = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
map<string, int> ms;
int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void init()
{
	for (int i = 0; i < vs.size(); i++) ms[vs[i]] = i;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	init();
	cin >> s1 >> s2;
	int x = ms[s1];
	int y = ms[s2];
	for (int i = 0; i < 12; i++)
	{
		if ((x + a[i]) % 7 == y % 7)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}