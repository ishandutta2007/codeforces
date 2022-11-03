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
const long long INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	vector<string> vs;
	int n;
	cin >> n;
	vs.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	int m = vs[0].size();
	string ans = vs[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ans[j] == '!') continue;
			if (ans[j] == '?' || vs[i][j] == '?')
			{
				ans[j] = '?'^ans[j]^vs[i][j];
				continue;
			}
			if (ans[j] != vs[i][j]) ans[j] = '!';

		}
	}
	for (int i = 0; i < m; i++)
	{
		if (ans[i] == '?') ans[i] = 'a';
		if (ans[i] == '!') ans[i] = '?';
		
	}
	cout << ans << endl;
	return 0;
}