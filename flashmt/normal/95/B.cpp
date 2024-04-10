#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

int n;
char a[100100],b[100100];

int biggest()
{
	for (int i=0;i<n;i++)
		if (a[i]>'7') return 1;
		else
			if (a[i]<'7') return 0;
	return 0;
}

void att(int i,int n4,int n7,int big)
{
	if (n4+n7==0)
	{
		for (int i=0;i<n;i++) printf("%c",b[i]);
		printf("\n");
		exit(0);
	}
	
	if (big)
	{
		if (n4)
		{
			b[i]='4';
			att(i+1,n4-1,n7,1);
		}
		else
		{
			b[i]='7';
			att(i+1,n4,n7-1,1);
		}
	}
	
	if (a[i]<='4' && n4)
	{
		b[i]='4';
		att(i+1,n4-1,n7,(a[i]<'4'));
	}
	if (a[i]<='7' && n7)
	{
		b[i]='7';
		att(i+1,n4,n7-1,(a[i]<'7'));
	}
}

int main()
{
	scanf("%s",&a);
	n=strlen(a);
	if (n%2 || biggest()) 
	{
		if (n%2) n++;
		else n+=2;
		for (int i=1;i<=n;i++)
			if (i*2<=n) printf("4");
			else printf("7");
		printf("\n");
		return 0;
	}
	att(0,n/2,n/2,0);
	n+=2;
	for (int i=1;i<=n;i++)
		if (i*2<=n) printf("4");
		else printf("7");
	printf("\n");
	return 0;
}