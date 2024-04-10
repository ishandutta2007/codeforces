#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
ll n,p;
 
int main()
{
	cin >> n >> p;
	for (ll i = 1;i <= 1000 && n - p * i >= 0;i++)
	{
		ll v = n - p * i,cnt = 0;
		while (v > 0)
		{
			cnt++;
			v -= v & -v;
		}
		if (cnt <= i && i <= n - p * i)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}