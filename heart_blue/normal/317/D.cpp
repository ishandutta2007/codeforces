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
int a[1<<20];
map<long long,int> m1,m2;
int n;
int sg[] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
	
int main()
{
	int n;
	cin >> n;
	int m = int(sqrt(double(n)));
	int cnt = 0;
	for(int i = 2; i <= m; i++)
	{
		int tmp = 0;
		if(m2[i]) continue;
		for(long long t = i; t <= n; t*=i)
		{
			m2[t] = 1;
			if(t > m)
			{
				if(!m1[t])
				{
					cnt ++;
				}
				
			}
			tmp++;
		}
		a[tmp] ^= 1;
	}
	a[1] = (n-m-cnt+1)&1;
	int ans = 0;
	for(int i = 1; i < 100; i++)
	{
		if(a[i])
		{
			ans ^= sg[i];
		}
	}
	if(ans) cout << "Vasya" << endl;
	else cout << "Petya" << endl;


	return 0;
}