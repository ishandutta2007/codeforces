#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
#define ll long long
using namespace std;
int num[N],h[N];
ll q[N];
ll sum;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&h[i]);
	int sum=0;
	for(int i=1;i<m;i++) sum+=h[i],q[i]=sum%n;
	q[m]=n;
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++) num[i]=q[i]-q[i-1];
	printf("%d\n",(sum+h[m]+n-1)/n);
	for(int i=1;i<=m;i++) printf("%d ",num[i]);
	puts("");
	int u=1;
	for(int i=1;i<=m;i++)
	while(h[i]>0)
	{
		h[i]-=num[u++];
		printf("%d ",i);
		if(u==m+1){u=1;puts("");}
	}
	while(u!=1 && u++!=m+1) printf("%d ",m);
	return 0;
}