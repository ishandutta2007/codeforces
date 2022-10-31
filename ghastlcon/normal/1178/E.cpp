#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxl=1000100;

char s[maxl];
int a[maxl];

int Next[maxl][3];
int last[maxl][3];

int ans[maxl];
int cnt=0;
int mid=-1;

int n;

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1; i<=n; i++) a[i]=s[i-1]-'a';
	
	for (int i=2; i<=n+1; i++)
	{
		for (int j=0; j<3; j++) last[i][j]=last[i-1][j];
		last[i][ a[i-1] ]=i-1;
	}
	for (int i=n-1; i>=0; i--)
	{
		for (int j=0; j<3; j++) Next[i][j]=Next[i+1][j];
		Next[i][ a[i+1] ]=i+1;
	}
	
	int L=0,R=n+1;
	while (1)
	{
		int nl=n+1,nr=0;
		for (int i=0; i<3; i++)
		{
			int x=Next[L][i];
			int y=last[R][i];
			if ( x>=y || !x || !y ) continue;
			if ( y-x+1<nr-nl+1 ) continue;
			nr=y;
			nl=x;
		}
		if (nl>=nr) break;
		
		ans[++cnt]=a[nl];
		L=nl;
		R=nr;
	}
	
	if (L+1<R) mid=a[L+1];
	int num=cnt*2;
	if (mid>-1) num++;
	if (num<(n/2))
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	
	for (int i=1; i<=cnt; i++) putchar('a'+ans[i]);
	if (mid>-1) putchar('a'+mid);
	for (int i=cnt; i>=1; i--) putchar('a'+ans[i]);
	printf("\n");
	
	return 0;
}