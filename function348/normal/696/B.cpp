#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n;
int fa[N],dep[N],size[N];
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++) scanf("%d",&fa[i]);
	dep[1]=1;
	for (int i=2;i<=n;i++) dep[i]=dep[fa[i]]+1;
	for (int i=n;i>=1;i--)
	{
		size[i]++;
		size[fa[i]]+=size[i];
	}
	for (int i=1;i<=n;i++) printf("%.1lf ",dep[i]+(n-dep[i]-size[i]+1)*0.5);
}