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

int a[100091];
long long sum(long long n)
{
	return n*(n-1)/2;
}
int b[100091];
int main()
{
	int n,d;
	cin >> n >> d;
	int i,j;
	i = j = 0;
	for(int k = 0; k < n; k++)
	{
		cin >> a[k];
		b[k] = k;
	}
	i = 0;
	j = 2;
	long long ans = 0;

	while(i + 2 < n)
	{
		if(a[j] - a[i] > d)
		{
			b[i] = j-1;
			i++;
		}
		else if(j < n-1)
		{
			j++;
		}
		else if(j == n-1)
		{
			b[i] = j;
			i++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(i + 2 <= b[i])
		{
			ans += sum(b[i]-i);
		}
	}
	cout  << ans << endl;

}