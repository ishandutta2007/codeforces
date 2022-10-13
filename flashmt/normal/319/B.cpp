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

int n, a[100100], l[100100], r[100100], killed[100100];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], l[i] = i - 1, r[i] = i + 1;
	l[n + 1] = n; r[0] = 1; a[n + 1] = n + 1;
	
	vector <int> q[2];
	for (int i = n - 1; i; i--)
		if (a[i] > a[i + 1]) q[0].push_back(i), killed[i + 1] = 1;
		
	int ans = 0, z = 0;
	while (!q[z].empty())
	{
		ans++;
		q[1 - z].clear();
		
		for (int i = 0; i < int(q[z].size()); i++)
		{
			int x = q[z][i], rr = r[r[x]];
			r[x] = rr; l[rr] = x; 
			if (a[x] > a[rr] && !killed[x]) q[1 - z].push_back(x), killed[rr] = 1;
		}
		
		z ^= 1;
	}
	
	cout << ans << endl;
}