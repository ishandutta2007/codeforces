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
int a[int(2e6+2)];

/*

l1          l2
r1


		rm


r2			l2
*/


	


int main()
{
	int n;
	cin >> n;
	int k = 1;
	int t = n;
	while(t >= 4)
	{
		t /= 4;
		k++;
	}
	int m = int(sqrt(double(n)));
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int i = n;
	t = 1;
	int pre = 0;
	long long ans = 0;
	for(int s = 1; s <= n; s*=4)
	{
		for(int i = n; i > n-s; i--)
		{
			ans += a[i];
		}
	}
	cout << ans << endl;

	
}