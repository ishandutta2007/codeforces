#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 300005
using namespace std;
int nm[maxn]; 
int main()
{
	int n;
	scanf("%d", &n);
	int ans = 1;
	printf("1 ");
	nm[n + 1] = 1;
	int pl = n;
	
	for(int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);
		nm[p] = 1;
		while(nm[pl] == 1) pl--;
		printf("%d ", i + 2 - (n - pl));
	}
	return 0;
 }