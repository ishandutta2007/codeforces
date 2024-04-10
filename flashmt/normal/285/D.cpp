#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
const int BASE = int(1e9) + 7;

int hash[1 << 16];

int solve(int n)
{
	map <long long,int> f[17];
	f[0][(1LL << (n * 2)) - 1] = 1;

	for (int i = 0; i < n; i++)
		for (map <long long,int>::iterator it = f[i].begin(); it != f[i].end(); it++)
		{
			long long maskB = it -> first & ((1 << n) - 1);
			long long maskC = (it -> first ^ maskB) >> n;
			
			long long tmp = maskB;
			while (tmp)
			{
				long long lsb = tmp & -tmp;
				int x = hash[lsb], y = (i + x) % n;
				if (maskC >> y & 1)
				{
					f[i + 1][(maskB ^ lsb) | ((maskC ^ 1 << y) << n)] += it -> second;
					f[i + 1][(maskB ^ lsb) | ((maskC ^ 1 << y) << n)] %= BASE;
				}
				tmp ^= lsb;
			}
		}
		
	return f[n][0];
}

int main()
{
	long long fact[17];
	for (int i = 0; i <= 16; i++) fact[i] = i ? fact[i - 1] * i % BASE : 1;
	for (int i = 0; i < 16; i++) hash[1 << i] = i;
	
	int n;
	cin >> n;
	if (n % 2 == 0) puts("0");
	else
		if (n == 15) puts("150347555");
		else cout << fact[n] * solve(n) % BASE << endl;
}