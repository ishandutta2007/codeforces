#include<bits/stdc++.h>
using namespace std;

int c[100010],t[100010],a[100010],b[100010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) c[i]=rd();
	for (int i=1;i<=n;i++) t[i]=rd();
	if (c[1]!=t[1]) { puts("No");return 0; }
	for (int i=1;i<n;i++) a[i]=c[i+1]-c[i];
	for (int i=1;i<n;i++) b[i]=t[i+1]-t[i];
	sort(a+1,a+n);sort(b+1,b+n);
	bool flag=true;
	for (int i=1;i<n;i++) if (a[i]!=b[i]) flag=false;
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}