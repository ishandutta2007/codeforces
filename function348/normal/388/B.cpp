#include<cstdio>
#include<iostream>
using namespace std;
int num;
int a[1010][1010];
void add(int x,int y) { a[x][y]=a[y][x]=1;}
void work(int t,int k,int len)
{
	if (k%2==1)
	{
		int last=1;
		for (int i=1;i<len;i++)
		{
			int p=++num;
			add(last,p);
			last=p;
		}
		add(last,t);
		k--;
	}
	if (k==0) return;
	int p=++num,q;
	q=++num;add(p,q);add(q,t);
	q=++num;add(p,q);add(q,t);
	work(p,k/2,len-2);
}
int main()
{
	int k;
	scanf("%d",&k);
	num=2;
	work(2,k,60);
	printf("%d\n",num);
//	return 0;
	for (int i=1;i<=num;i++)
	{
		for (int j=1;j<=num;j++)
			printf("%c",a[i][j]?'Y':'N');
		printf("\n");
	}
	return 0;
}