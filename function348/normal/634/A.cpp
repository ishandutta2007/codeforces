#include<cstdio>
#include<iostream>
using namespace std;
const int N=200010;
int n;
int a[N],b[N];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&b[i]);
	for (int i=0;i<n;i++)
	if (a[i]==0)
	{
		for (int j=i;j<n;j++) a[j]=a[j+1];
		break;
	}
	for (int i=0;i<n;i++)
	if (b[i]==0)
	{
		for (int j=i;j<n;j++) b[j]=b[j+1];
		break;
	}
	int p1,p2;n--;
	for (int i=0;i<n;i++) if (a[i]==1) p1=i;
	for (int i=0;i<n;i++) if (b[i]==1) p2=i;
	for (int i=0;i<n;i++) 
	if (a[(p1+i)%n]!=b[(p2+i)%n]) 
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}