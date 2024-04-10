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

int n, S, T, p[100100], d[100100];

int main()
{
	cin >> n >> S >> T;
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	
	int ans = 0;
	while (!d[S])
	{
		d[S] = 1;
		if (S == T) break;
		S = p[S];
		ans++;
	}
	
	if (!d[T]) puts("-1");
	else cout << ans << endl;
}