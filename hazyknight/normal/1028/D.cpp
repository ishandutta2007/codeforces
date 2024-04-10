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

const int MAXN = 400005;
const int MOD = 1000000007;

int n,ans,MAX,MIN,spj,op;

string tp;

set<int> val;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	ans = spj = 1;
	MIN = -1e9;
	MAX = 1e9;
	val.insert(-1e9);
	val.insert(1e9);
	for (int i = 1;i <= n;i++)
	{
		cin >> tp >> op;
		if (tp == "ADD")
		{
			spj += (op > MIN && op < MAX);
			val.insert(op);
		}
		else
		{
			spj = 1;
			if (op > MIN && op < MAX)
				(ans <<= 1) %= MOD;
			else if (op < MIN || op > MAX)
				ans = 0;
			set<int>::iterator it = val.find(op);
			MIN = *(--it);
			it++;
			MAX = *(++it);
			val.erase(op);
		}
	}
	printf("%d\n",(int)((long long)ans * spj % MOD));
	return 0;
}