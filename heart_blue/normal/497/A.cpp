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
const int N = 5e2 + 10;
vector<string> vs;
vector<string> vs2;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vs.resize(n);
	vs2.resize(n);
	for (auto &str : vs) cin >> str;

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			vs2[i].push_back(vs[i][j]);
		}
		int flag = 0;
		for (int i = 1; i < n; i++)
		{
			if (vs2[i - 1] > vs2[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag) 
			for (int i = 0; i < n; i++) vs2[i].pop_back();
	}
	cout << m - vs2[0].length() << endl;
	
	return 0;
}