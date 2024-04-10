#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 1005
using namespace std;
int a[maxn], b[maxn];
int mnp[maxn], mns = 0; 
int p[maxn], use[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
		if(a[i] != b[i]) mnp[mns++] = i;
	for(int i = 1; i <= n; i++)
		if(i != mnp[0] && i != mnp[1]) 
			p[i] = a[i], use[p[i]] = 1;
	
	if(mns == 1)
	{
		for(int i = 1; i <= n; i++)
			if(!use[i]) p[mnp[0]] = i; 
	} 
	else
	{
		if(!use[a[mnp[0]]] && !use[b[mnp[1]]] && a[mnp[0]] != b[mnp[1]]) p[mnp[0]] = a[mnp[0]], p[mnp[1]] = b[mnp[1]];
		else p[mnp[0]] = b[mnp[0]], p[mnp[1]] = a[mnp[1]];
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	return 0;
 }