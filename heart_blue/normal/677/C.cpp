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
const int N = 64;
int cnt[N];
int a[N * 2];
void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cnt[i&j]++;
		}
	}
	for (int i = 0; i < 10; i++) a[i + '0'] = i;
	for (int i = 0; i < 26; i++) a[i + 'A'] = i + 10;
	for (int i = 0; i < 26; i++) a[i + 'a'] = i + 36;
	a['-'] = 62;
	a['_'] = 63;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ans = 1;
	init();
	string str;
	cin >> str;
	for(auto &c : str)
	{
		ans = ans*cnt[a[c]] % INF;
	}
	cout << ans << endl;
	return 0;
}