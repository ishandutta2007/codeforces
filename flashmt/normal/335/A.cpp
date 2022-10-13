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
	int d[256] = {0}, n;
	string s;
	cin >> s >> n;
	for (int i = 0; i < int(s.size()); i++) d[s[i]]++;
	
	int cntDif = 0;
	for (char c = 'a'; c <= 'z'; c++)
		if (d[c])
			cntDif++;
			
	if (cntDif > n) puts("-1");
	else
		for (int ans = 1; ans <= 10000; ans++)
		{
			int need = 0;
			for (char c = 'a'; c <= 'z'; c++) need += (d[c] + ans - 1) / ans;
			if (need <= n)
			{
				cout << ans << endl;
				for (char c = 'a'; c <= 'z'; c++)
					for (int i = 0; i < (d[c] + ans - 1) / ans; i++)
						cout << c;
				while (need < n) need++, cout << 'a';
				cout << endl;
				break;
			}
		}
}