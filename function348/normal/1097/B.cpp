#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<signal.h>
using namespace std;
int n,x;
int f[1234],g[1234];
int main()
{
	scanf("%d",&n);
	f[0]=1;
	while (n--)
	{
		scanf("%d",&x);
		for (int i=0;i<360;i++)
		if (f[i])
			g[(i+x)%360]=g[(i+360-x)%360]=1;
		for (int i=0;i<360;i++) f[i]=g[i],g[i]=0;
	}
	puts(f[0]?"YES":"NO");
}