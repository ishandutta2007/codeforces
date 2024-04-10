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

int a[1000000];
int main()
{
	//freopen("input.txt","w",stdin);
	int n,m;
	cin >> n >> m;
	MEM(a,0);
	int x,y;
	x = 0;
	y = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 1)
		{
			x++;
		}
		else y++;
	}
	int t = MIN(x,y);
	int l,r;
	for(int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		int tmp = r-l+1;
		if(tmp % 2 == 1)
		{
			cout << 0 << endl;
		}
		else if(tmp / 2 <= t)
		{
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}




	return 0;
}