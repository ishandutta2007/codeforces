#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=300010;
int n;
int a[N],b[N],id[N];
int cmp(int i,int j) { return a[i]<a[j];}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	for (int i=1;i<=n;i++)
	if (a[id[i]]>b[i-1]) b[i]=a[id[i]];else b[i]=b[i-1]+1;
	for (int i=1;i<=n;i++) a[id[i]]=b[i];
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}