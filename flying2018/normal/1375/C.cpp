#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n,c=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int b;
			scanf("%d",&b);
			while(c>1 && a[c]<b) c--;
			if(!c) a[++c]=b;
			else if(a[c]>b) a[++c]=b;
		}
		puts(c==1?"YES":"NO");
	}
	return 0;
}