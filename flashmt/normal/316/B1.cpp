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

vector <int> a[1111], line;
int n, S, front[1111], back[1111], rank[1111], f[1111];

int main()
{
	int x, save;
	cin >> n >> S;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x) front[i] = x, back[x] = i;
	}
	
	for (int i = 1; i <= n; i++)
		if (!front[i])
		{
			int cnt = 1, hasS = 0, j = i;
			if (S == i) save = hasS = 1;
			while (back[j]) 
			{
				j = back[j]; cnt++;
				if (S == j) save = cnt, hasS = 1;
			}
			
			if (!hasS) line.push_back(cnt);
		}
		
	f[0] = 1;
	for (int i = 0; i < int(line.size()); i++)
		for (int j = 1000; j >= line[i]; j--)
			f[j] |= f[j - line[i]];
			
	for (int i = 0; i <= 1000; i++)
		if (f[i]) cout << i + save << endl;
}