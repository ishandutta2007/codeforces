#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10010
using namespace std;
int num[2][N],link[2][N];
int a[N];
void swap_(int a,int x,int y){swap(num[a][x],num[a][y]);swap(link[a][num[a][x]],link[a][num[a][y]]);}
int main()
{
	int n;
	scanf("%d",&n);
	n=1<<n;
	for(int i=0;i<n;i++) num[0][i]=num[1][i]=link[0][i]=link[1][i]=i;
	int swp=0;
	for(int i=0;i<n;i++) scanf("%d",&a[i]),swp^=a[i];
	if(swp){puts("Fou");return 0;}
	puts("Shi");
	for(int i=0;i<n;i++)
	{
		int u=i;
		while((num[0][u]^num[1][u])!=a[u])
		{
			int x=link[0][a[u]^num[1][u]];
			swap_(0,u,x);
			if(x>i) break;
			swap_(1,i+1,x);
			u=x;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",num[0][i]);
	puts("");
	for(int i=0;i<n;i++)
		printf("%d ",num[1][i]);
	return 0;
}