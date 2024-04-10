#include<bits/stdc++.h>
using namespace std;

int num[100010],t,n,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print1() { putchar('y');putchar('e');putchar('s');putchar('\n'); }
inline void print2() { putchar('n');putchar('o');putchar('\n'); }

inline void work()
{
	n=rd();k=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	if (n==1) { (num[1]==k)?print1():print2();return; }
	bool flag=false;
	for (int i=1;i<=n;i++) if (num[i]==k) flag=true;
	if (!flag) { print2();return; }
	int lst=0;flag=false;
	for (int i=1;i<=n;i++) if (num[i]>=k)
	{
		if (lst&&i-lst<=2) { flag=true;break; }
		lst=i;
	}
	if (flag) print1();
	else print2();
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}