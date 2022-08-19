#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 1000005
using namespace std;
int mod = 1000000007;
int p[maxn];
char inp[maxn];
int main()
{
	p[0] = 1;
	for(int i = 1; i < maxn; i++)
		p[i] = p[i - 1] << 1, p[i] %= mod;
	scanf("%s", inp);
	int l = strlen(inp);
	int ns = 0;
	int ans = 0;
	for(int i = 0; i < l; i++)
		if(inp[i] == 'a') ns++;
		else ans += p[ns] - 1, ans %= mod;
	ans += mod, ans %= mod;
	printf("%d\n", ans); 
	return 0;
 }