#include<bits/stdc++.h>
using namespace std;
#define y1 DCXISSOHANDSOME

int n;
char s[100010],s1[100010],t[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool check(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	scanf("%s",t+1);
	if (t[1]=='Y') return true;
	return false;
}

int main()
{
	n=rd();
	int h1=1,h2=1;
	int tt=0,t1=0;
	while (233)
	{
		if (tt==n-1) break;
		bool flag1=check(h1,h2+1,n,n),flag2=check(h1+1,h2,n,n);
		if (flag1) { s[++tt]='R';h2++; }
		else { s[++tt]='D';h1++; }
	}
	h1=h2=n;
	while (233)
	{
		if (t1==n-1) break;
		bool flag1=check(1,1,h1-1,h2),flag2=check(1,1,h1,h2-1);
		if (flag1) { s1[++t1]='D';h1--; }
		else { s1[++t1]='R';h2--; }
	}
	printf("! ");
	for (int i=1;i<=tt;i++) putchar(s[i]);
	for (int i=t1;i;i--) putchar(s1[i]);
	putchar('\n');
	fflush(stdout);
	return 0;
}