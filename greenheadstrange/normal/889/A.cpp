#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 200005 
using namespace std;
int t[maxn];
bool hv[maxn];
int main() 
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for(int i = 1; i <= n; i++)
	{
		if(!t[i] || !hv[t[i]]) ans++;
		hv[t[i]] = 0, hv[i] = 1;
	}
	printf("%d\n", ans);
	return 0;
}