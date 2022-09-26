#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		long long n, k;
		cin >> n >> k;
		long long now = 0;
		for(int i = 1; i <= n; i ++)
		{
			now = 4 * now + 1;
			if(now >= k)
				break;
		}
		if(now < k)
		{
			cout << "NO" << endl;
			continue;
		}
		if(n == 2 && k == 3)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES ";
		now = 1;
		while(now <= k)
		{
			k -= now;
			n --;
			now = (now + 1) * 2 - 1;
		}
		cout << max(0ll,n) << endl;
	}
	
	return 0;
}