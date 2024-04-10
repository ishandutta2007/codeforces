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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int INF = 0x3f3f3f3f;
int a[101];
int b[101];
int c[101][101];
int m;
bool check(int x, int y)
{
	if(a[x] > a[y] && a[x] < b[y]) return true;
	if(b[x] > a[y] && b[x] < b[y]) return true;
	return false;
}


void check2(int t)
{
	list<int> l;
	l.push_back(t);
	int flag[101];
	MEM(flag,0);
	flag[t] = 1;
	while(!l.empty())
	{
		int x = l.front();
		l.pop_front();
		for(int i = 1; i < m; i++)
		{
			if(flag[i]) continue;
			if(c[x][i])
			{
				l.push_back(i);
				c[t][i] = 1;
				flag[i] = 1;
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	MEM(c,0);
	cin >> n;
	int q,x,y;
	m = 1;
	for(int i = 0; i < n; i++)
	{
		cin >> q >> x >> y;
		if(q == 1)
		{
			a[m] = x;
			b[m] = y;
			
			for(int j = 1; j < m; j++)
			{
				if(check(j,m))
				{
					c[j][m] = 1;
				}
				if(check(m,j))
				{
					c[m][j] = 1;
				}
			}
			m++;
		}

		if(q == 2)
		{
			check2(x);
			if(c[x][y])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;

}