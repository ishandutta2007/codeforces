#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[110],b[110],t,n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=n;i++) b[i]=rd();
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
	for (int i=1;i<=n;i++) printf("%d ",b[i]);puts("");
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}