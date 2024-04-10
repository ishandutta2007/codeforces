#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[110];
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s",s);int n=strlen(s);
	int x=0,y=0;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='U') y++;
		if (s[i]=='D') y--;
		if (s[i]=='L') x--;
		if (s[i]=='R') x++;
	}
	int X=x,Y=y;
	x=0,y=0;
	int f=0;
	for (int i=0;i<n;i++)
	{
		if (X==0&&Y==0)
		{
			if (a-x==0&&b-y==0) { f=1;break;}
		}
		if (X==0&&Y!=0)
		{
			if (a-x==0&&(b-y)%Y==0&&(b-y)/Y>=0) { f=1;break;}
		}
		if (X!=0&&Y==0)
		{
			if ((a-x)%X==0&&(a-x)/X>=0&&b-y==0) { f=1;break;}
		}
		if (X!=0&&Y!=0)
		{
			if ((a-x)%X==0&&(b-y)%Y==0&&(a-x)/X==(b-y)/Y&&(a-x)/X>=0) { f=1;break;}
		}
		if (s[i]=='U') y++;
		if (s[i]=='D') y--;
		if (s[i]=='L') x--;
		if (s[i]=='R') x++;
	}
	if (f) printf("Yes\n");else printf("No\n");
	return 0;
}