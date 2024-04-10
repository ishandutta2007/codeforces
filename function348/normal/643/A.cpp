#include<cstdio>
#include<iostream>
using namespace std;
const int N=5010;
int n;
int a[N],s[N],ans[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int p=0;
		for (int j=1;j<=n;j++) s[j]=0;
		for (int j=i;j<=n;j++)
		{
			s[a[j]]++;
			if (s[a[j]]>s[p]||(s[a[j]]==s[p]&&a[j]<p)) p=a[j];
			ans[p]++;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}