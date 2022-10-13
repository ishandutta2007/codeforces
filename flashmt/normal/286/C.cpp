#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

int n, p[1000100], isClose[1000100];
stack <int> unknown, close;

int findOpen(int x)
{
	close.push(x);
	while (!close.empty())
	{
		int x = close.top();
		isClose[x] = 1;
		if (unknown.empty()) return 0;
		int y = unknown.top(); unknown.pop();
		if (p[x] == p[y]) close.pop();
		else close.push(y);
	}
	return 1;
}

int main()
{
	int t, x;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	cin >> t;
	while (t--) scanf("%d", &x), isClose[x] = 1;
	
	for (int i = 1; i <= n; i++)
		if (!isClose[i]) unknown.push(i);
		else
			if (!findOpen(i)) 
			{
				puts("NO");
				return 0;
			}
			
	while (!unknown.empty())
	{
		int x = unknown.top(); unknown.pop();
		if (!findOpen(x))
		{
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", (isClose[i] ? -p[i] : p[i]));
}