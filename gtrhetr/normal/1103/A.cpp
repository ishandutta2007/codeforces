#include<bits/stdc++.h>
using namespace std;
#define y1 DCXISSOHANDSOME

const int x1[4]={1,1,2,2},y1[4]={1,3,1,3},x2[4]={3,3,3,3},y2[4]={1,2,3,4};

int n;
char s[1010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int h1=0,h2=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='1')
		{
			printf("%d %d\n",x1[h1%4],y1[h1%4]);
			h1++;
		}
		else
		{
			printf("%d %d\n",x2[h2%4],y2[h2%4]);
			h2++;
		}
	}
	return 0;
}