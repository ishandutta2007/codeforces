#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 100005
using namespace std;
int n;
int a[maxn]; 
int c[maxn]; 
int uact[2]={0};
int ucnt[2]={0};
int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		char b;
		scanf("%c",&b);
		if(b=='b') a[i]=0;
		else a[i]=1;
	}
	
	a[n]=2;
	for(int i=0;i<=n;i++) c[i]=a[i];
	int bs0=0;
	for(int i=0;i<n;i++)
		if(a[i]!=(i%2))
			uact[(i%2)]++;
	bs0=max(uact[0],uact[1]);
	int bs1=0;
	for(int i=0;i<n;i++)
		if(c[i]!=(i+1)%2)
			ucnt[(i+1)%2]++;
	bs1=max(ucnt[0],ucnt[1]);
	printf("%d\n",min(bs1,bs0));
	return 0;
}