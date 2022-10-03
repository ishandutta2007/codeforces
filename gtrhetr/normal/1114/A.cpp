#include<bits/stdc++.h>
using namespace std;

int x,y,z,a,b,c;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	x=rd();y=rd();z=rd();a=rd();b=rd();c=rd();
	int sum=a+b+c;
	if (x>a) { puts("NO");return 0; }
	sum-=x;a-=x;
	if (y>a+b) { puts("NO");return 0; }
	sum-=y;
	if (z>sum) { puts("NO");return 0; }
	puts("YES");
	return 0;
}