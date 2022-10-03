#include<bits/stdc++.h>
using namespace std;

int num[200010],sum[200010],n;
char s[200010];

inline bool check()
{
	if (sum[n]!=0) return false;
	for (int i=1;i<=n;i++) if (sum[i]<0) return false;
	return true;
}

int main()
{
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++) num[i]=(s[i]=='(')?1:-1;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+num[i];
	if (check()) { puts("Yes");return 0; }
	if (sum[n]!=0) { puts("No");return 0; }
	int id=0;
	for (int i=1;i<=n;i++) if (num[i]==-1) { id=i;break; }
	int now=0;
	bool flag=true;
	for (int i=1;i<=n;i++)
	{
		if (i!=id) now+=num[i];
		if (now<0) flag=false;
	}
	if (flag) { puts("Yes");return 0; }
	id=0;
	for (int i=n;i;i--) if (num[i]==1) { id=i;break; }
	now=1;flag=true;
	for (int i=1;i<=n;i++)
	{
		if (i!=id) now+=num[i];
		if (now<0) flag=false;
	}
	if (flag) { puts("Yes");return 0; }
	puts("No");
	return 0;
}