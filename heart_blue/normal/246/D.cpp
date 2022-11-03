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
ifstream fin("aa.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))

const long long M = 1e5;
int c[M+1];
int a[M+1];
map<long long ,int> mm;
map<int,int> mp;
int main()
{
	//freopen("aa.txt","r",stdin);
	int n,m;
	int x,y;
	MEM(c,0);
	int ans = 0;
	int k = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mp[a[i]] = 1;
	}
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		int tx = x;
		int ty = y;
		x = a[x];
		y = a[y];

		if(x != y)
		{
			if(mm[x*M+y] == 0)
			{
				c[x] ++;
				mm[x*M+y] = 1;
			}
			if(mm[y*M+x] == 0)
			{
				c[y]++;
				mm[y*M+x] = 1;
			}
			if(ans < c[x])
			{
				ans = c[x];
				k = tx;
			}
			if(ans < c[y])
			{
				ans = c[y];
				k = ty;
			}
		}
	}
	ans = M;
	for(int i = 1; i < M+1; i ++)
	{
		if(c[a[k]] == c[a[i]] && mp[a[i]])
		{
			if(a[i] < ans)
			{
				ans = a[i];
			}
		}
	}
	cout << ans << endl;

	return 0;
}