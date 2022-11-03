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
#define MP(x,y) make_pair(x,y) 
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
const int N = 30001;
int flag[N];
vector<int> v[N];
int deg[N];
vector<int> ans;
void dfs(int x)
{
	
	flag[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (flag[v[x][i]]) continue;
		dfs(v[x][i]);
	}
	ans.push_back(x);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	MEM(flag, 0);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i]) dfs(i);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (i) putchar(' ');
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}