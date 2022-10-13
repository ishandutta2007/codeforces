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

int main()
{
	string s;
	vector <int> a, from;
	cin >> s;
	s += '.';
	for (int i = 1, cur = 0; i + 1 < int(s.size()); i++)
		if (s[i - 1] == s[i + 1]) cur++;
		else 
			if (cur) a.push_back(cur), from.push_back(i - cur + 1), cur = 0;
			
	int g[5050] = {0};
	g[1] = g[2] = 1;
	for (int i = 3; i <= 5000; i++)
	{
		set <int> s;
		s.insert(g[i - 2]);
		for (int j = 0; j <= i - j - 3; j++) s.insert(g[j] ^ g[i - j - 3]);
		while (s.count(g[i])) g[i]++;
	}
	
	int sumG = 0;
	for (int i = 0; i < int(a.size()); i++) sumG ^= g[a[i]];
	
	if (!sumG) puts("Second");
	else
	{
		puts("First");
		for (int i = 0; i < int(a.size()); i++)
			if (a[i] < 3 && sumG == 1)
			{
				cout << from[i] << endl;
				return 0;
			}
			else
			{
				if ((sumG ^ g[a[i]]) == g[a[i] - 2])
				{
					cout << from[i] << endl;
					return 0;
				}
				
				for (int j = 0; j <= a[i] - j - 3; j++)
					if ((sumG ^ g[a[i]]) == (g[j] ^ g[a[i] - j - 3]))
					{
						cout << from[i] + 1 + j << endl;
						return 0; 
					}
			}
	}
}