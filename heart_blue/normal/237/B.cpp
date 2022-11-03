
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
int c[51];
int a[51][51];
int ans[4][10000];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= c[i]; j++)
		{
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= c[i]; j++)
		{
			int x,y;
			int tx,ty;
			tx = ty = -1;
			int m = a[i][j];
			for(x = i; x <= n; x++)
			{
				if(x == i) y = j;
				else y = 1;
				for(; y <= c[x]; y++)
				{
					if(m > a[x][y])
					{
						m = a[x][y];
						tx = x;
						ty = y;
					}
				}
			}
			if(m != a[i][j])
			{
				swap(a[i][j],a[tx][ty]);
				ans[0][cnt] = i;
				ans[1][cnt] = j;
				ans[2][cnt] = tx;
				ans[3][cnt] = ty;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	for(int i = 0; i < cnt; i++)
	{
		cout << ans[0][i] << ' ' << ans[1][i] << ' ' << ans[2][i] << ' ' << ans[3][i] << endl;
	}


	return 0;
}