#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 2000

typedef long long lint;

const lint mod = 1000000007LL;

using namespace std;

int next[MAXN], indeg[MAXN];
lint binom[MAXN+1][MAXN+1];
lint fact[MAXN+1];

void precalc_binoms_fact(int max)
{
	for (int i = 0; i <= max; i++)
		binom[i][0] = binom[i][i] = 1;

	for (int i = 2; i <= max; i++)
		for (int j = 1; j < i; j++)
			binom[i][j] = (binom[i-1][j] + binom[i-1][j-1])%mod;

	fact[0] = 1;
	for (int i = 1; i <= max; i++)
		fact[i] = fact[i-1] * i % mod;
}

lint calc_good(int path, int single)
{
	lint ret = 0;

	for (int s = 0; s <= single; s++) {
		lint v = binom[single][s] * fact[path+single-s] % mod;

		if (s%2 == 0)
			ret = (ret+v)%mod;
		else
			ret = (ret-v+mod)%mod;
	}

	return ret;
}

int main(int argc, char ** argv)
{
	int n;

	cin >> n;

	precalc_binoms_fact(n);

	for (int i = 0; i < n; i++)
		indeg[i] = 0;

	for (int i = 0; i < n; i++) {
		cin >> next[i];
		if (next[i] != -1) {
			next[i] --;
			indeg[next[i]] ++;
		}
	}

	int path = 0, single = 0;

	for (int i = 0; i < n; i++)
		if (indeg[i] == 0) {
			if (next[i] == -1)
				single ++;
			else
				path ++;
		}

	cout << calc_good(path, single) << endl;

	return 0;
}