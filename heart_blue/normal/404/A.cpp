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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
#define ABS(x) ((x) > 0 ? (x):(-x))
const int N = 301;
char c[N][N];
string check(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}
	char ch = c[0][0];
	for (int i = 0; i < n; i++)
	{
		if (c[i][i] != ch) return "NO";
		if (c[i][n - i - 1] != ch) return "NO";
	}
	char t = c[0][1];
	if (t == ch) return "NO";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (i + j == n - 1) continue;
			if (c[i][j] != t) return "NO";
		}
	}
	return "YES";
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	cout << check(n) << endl;
	return 0;
}