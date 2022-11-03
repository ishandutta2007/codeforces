
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
const int M = 1000000;
int a[M+1];
int b[M+1];
int main()
{
	MEM(a,0);
	MEM(b,0);
	a[0] = a[1] = 1;
	for(int i = 2; i <= M; i++)
	{
		b[i] = b[i-1];
		if(a[i] == 0)
		{
			b[i]++;
			for(int j = i+i; j <= M; j+= i)
			{
				a[j] = 1;
			}
		}
	}
	int n,m,k;
	cin >> n >> m >> k;
	if(k > b[m]-b[n-1])
	{
		cout << -1 << endl;
	}
	else
	{
		int l = 1;
		int r = m-n+1;
		int last = -1;
		while(l <= r)
		{
			int mid = (l+r)>>1;
			int flag= 1;
			for(int x = n; x <= m-mid+1; x++)
			{
				if(b[x+mid-1] - b[x-1] < k)
				{
					flag = 0;
					break;
				}
			}
			if(flag) last = mid,r = mid-1;
			else l = mid+1;
		}
		cout << last << endl;
	}


			

	return 0;
}