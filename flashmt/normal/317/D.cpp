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
const int G[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

int main()
{
	int n, sumXor = 1, i, done[100100] = {0}; 
	vector <int> seen;
	cin >> n;
	
	for (i = 2; i * i <= n; i++)
		if (!done[i])
		{
			int u = 1, power = 0;
			while (n / i >= u)
			{
				u *= i;
				seen.push_back(u);
				if (u < 100000) done[u] = 1;
				power++;
			}
			
			sumXor ^= G[power];
		}
	
	int rest = n - i + 1;
	for (int j = 0; j < int(seen.size()); j++)
		if (seen[j] >= i) rest--;
	
	sumXor ^= rest % 2;
	puts(sumXor ? "Vasya" : "Petya");
}