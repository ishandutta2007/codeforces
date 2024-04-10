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
int b[1000000];
map<int,int> mp;
int main()
{
	//freopen("input.txt","w",stdin);
	int n,m;
	cin >> n >> m;
	MEM(a,0);
	MEM(b,0);
	a[1] = 1;
	int c,t;
	for(int i = 1; i <= n; i++)
	{
		cin >> c >> t;
		a[i+1] = a[i] + c*t;
	}
	a[n+1] = 1e9;
	int k = 1;
	int x;
	for(int i = 1; i <= m; i++)
	{
		cin >> x;
		while(1)
		{
			if(x < a[k+1])
			{
				cout << k << endl;
				break;
			}
			else
			{
				k++;
			}
		}
	}



	return 0;
}