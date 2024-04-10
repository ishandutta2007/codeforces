#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num[200010],n;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int cnt=0;
	for (int i=1;i<=n;i++) if (num[i]==1) cnt++;
	int cnt2=0;
	for (int i=1;i<=n;i++) if (num[i]==2) cnt2++;
	if (!cnt)
	{
		for (int i=1;i<=n;i++) printf("%d ",num[i]);
		puts("");
		return 0;
	}
	if (!cnt2)
	{
		for (int i=1;i<=n;i++) printf("%d ",num[i]);
		puts("");
		return 0;
	}
	printf("2 1 ");
	for (int i=1;i<cnt2;i++) printf("%d ",2);
	for (int i=1;i<cnt;i++) printf("%d ",1);
	puts("");
	return 0;
}