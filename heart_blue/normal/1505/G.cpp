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
const int N = 1e5 + 10;
int y[27] = { 10010,11020,20011,21012,11011,21021,22022,12021,11011,12012,10120,11130,20121,21122,11121,21131,22132,12131,11121,12122,10221,11231,12113,20222,21223,11222 };
char x[30000];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, s, z;
	for (int i = 0; i < 26; i++) 
	{
		if (!x[y[i]]) x[y[i]] = i + 'a';
	}
	scanf("%d", &t);
	while (t--)
	{
		z = 0;
		for (int i = 0; i < 5; i++)
			scanf("%d", &s), z = z * 10 + s;
		putchar(x[z]);
	}
	return 0;
}