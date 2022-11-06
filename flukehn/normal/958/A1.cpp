#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
char mp1[55][55],mp2[55][55],temp[55][55];
int n;
void reverse()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		temp[n-i+1][j]=mp2[i][j];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) mp2[i][j]=temp[i][j];
}
void reverse2()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		temp[i][n-j+1]=mp2[i][j];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) mp2[i][j]=temp[i][j];
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	scanf("%s",mp1[i]+1);
	for(int i=1;i<=n;i++)
	scanf("%s",mp2[i]+1);
	bool ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[i][j])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-j+1][i])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-i+1][n-j+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[j][n-i+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	
	reverse();
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[i][j])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-j+1][i])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-i+1][n-j+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[j][n-i+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	reverse();
	
	reverse2();
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[i][j])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-j+1][i])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-i+1][n-j+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[j][n-i+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	reverse2();
	
	reverse2();
	reverse();
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[i][j])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-j+1][i])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[n-i+1][n-j+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	ac=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp1[i][j]!=mp2[j][n-i+1])
			{
				ac=0;
			}
		}
	}
	if(ac)
	{
		puts("Yes");
		return 0;
	}
	puts("No");
}