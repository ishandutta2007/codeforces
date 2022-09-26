#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll L,R;

ll sum(ll n)
{
	ll even = 2,odd = 1,cur = 1,res = 0;
	int op = 0;
	while (cur <= n)
	{
		if (op & 1)
		{
			ll len = min(1ll << op,n - cur + 1);
			ll st = even,ed = (even + (len - 1) * 2) % MOD;
			cur = cur + len;
			len %= MOD;
			(res += (st + ed) % MOD * len % MOD * ((MOD + 1) >> 1)) %= MOD;
			even = (ed + 2) % MOD;
		}
		else
		{
			ll len = min(1ll << op,n - cur + 1);
			ll st = odd,ed = (odd + (len - 1) * 2) % MOD;
			cur = cur + len;
			len %= MOD;
			(res += (st + ed) % MOD * len % MOD * ((MOD + 1) >> 1)) %= MOD;
			odd = (ed + 2) % MOD;
		}
		op++;
	}
	return res;
}

int main()
{

	cin >> L >> R;
	cout << (sum(R) - sum(L - 1) + MOD) % MOD << endl;
	return 0;
}