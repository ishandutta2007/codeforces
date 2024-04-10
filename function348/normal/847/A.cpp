#include<cstdio>
#include<iostream>
using namespace std;
int a[1000],b[1000],v[1000];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	int last=0;
	for (int i=1;i<=n;i++)
	if (v[i]==0)
	{
		int p=i,q=i;v[i]=1;
		while (a[p]) p=a[p],v[p]=1;
		while (b[q]) q=b[q],v[q]=1;
		if (last) b[last]=p,a[p]=last;
		last=q;
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",a[i],b[i]);
	return 0;
}