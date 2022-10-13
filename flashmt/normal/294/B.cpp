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
#include <sstream>
using namespace std;

int f[222];

int main()
{
	int n, t[111], w[111], W = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i] >> w[i], W += w[i];

	for (int j = 1; j <= 200; j++) f[j] = - (1 << 29);
	for (int i = 0; i < n; i++)
		for (int j = 200; j >= 0; j--)
			if (j >= t[i]) f[j] = max(f[j], f[j - t[i]] + w[i]);
			
	for (int i = 0; i <= 200; i++)
		if (i >= W - f[i])
		{
			cout << i << endl;
			return 0;
		}
}