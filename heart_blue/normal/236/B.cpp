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
const int M = 1000001;
const int N = 1073741824 ;
int a[M];
int prime[M];

int main()
{
	a[1] = 1;
	MEM(prime,0);
	prime[0] = prime[1] = 1;
	for(int i = 2; i < M; i++) a[i] = 1;
	for(int i = 2; i < M; i++)
	{
		if(prime[i] == 0)
		{
			a[i] = 2;
			for(int j = i+i; j < M; j += i)
			{
				int n = j;
				int cnt = 0;
				while(n%i == 0)
				{
					cnt++;
					n/=i;
				}
				a[j] *= (cnt+1);
				prime[j] = 1;

			}
		}
	}

	int ans = 0;
	int x,y,z;
	cin >> x >> y >> z;
	for(int i = 1; i <= x; i++)
	{
		for(int j = 1; j <= y; j++)
		{
			for(int k = 1; k <= z; k++)
			{
				ans += a[i*j*k];
				ans %= N;
			}
		}
	}
	cout << ans << endl;





	return 0;
}