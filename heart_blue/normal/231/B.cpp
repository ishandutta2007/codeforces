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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
const  int INF = 0x7fffffff;
int a[100];

int main()
{
	int n,d,l;
	cin >> n >> d >> l;
	int k = 0;
	bool flag = true;
	while(k < n)
	{
		if(k == n-1)
		{
			if(d <= l && d >= 1)
			{
				a[k++] = d;
			}
			else
			{
				flag = false;
			}
			break;
		}
		else
		{
			if(d < l && d >= 1)
			{
				a[k++] = d+1;
				a[k] = 1;
				d = a[k];
			}
			else if(d > 0)
			{
				a[k++] = l;
				a[k] = l-d;
				d = a[k];
			}
			else
			{
				a[k++] = 1;
				a[k] = 1-d;
				d = a[k];
			}
		}
	}
	if(flag)
	{
		cout << a[0];
		for(int i = 1; i < n; i++) cout << ' ' << a[i];
		cout << endl;
	}
	else cout << -1 << endl;

			

	return 0;
}