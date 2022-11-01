#include<cstdio>
#include<iostream>
using namespace std;
int n;
int v[10000];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		v[x]=1;
	}
	int f=0;
	for (int i=1;i<=998;i++)
	if (v[i]&&v[i+1]&&v[i+2]) f=1;
	if (f) printf("YES\n");else printf("NO\n");
	return 0;
}