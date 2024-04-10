#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

int ans;

string s;

char a,b; 

int main()
{
	cin >> s >> s;
	for (int i = 'A';i <= 'Z';i++)
		for (int j = 'A';j <= 'Z';j++)
		{
			int cnt = 0;
			for (int k = 0;k < s.size() - 1;k++)
				if (s[k] == i && s[k + 1] == j)
					cnt++;
			if (cnt > ans)
			{
				ans = cnt;
				a = i;
				b = j;
			}
		}
	cout << a << b << endl;
	return 0;
}