#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector> 
#include<algorithm>
using namespace std;
int n,m;
int main()
{
//	freopen("in.txt","w",stdout);
	scanf("%d%d",&n,&m);
	int top=0,now=0;
	if(n==1 || n==2)
	{
		if(m) printf("-1\n");
		else if(n==1) printf("1\n");
		else printf("1 2\n");
		return 0;
	}
	while(m-now>=top/2)
	{
		now+=top/2;
		top++;
	}
	if(top>n || (top==n && m-now!=0))
	{
		printf("-1\n");
		return 0;
	} 
	for(int i=1;i<=top;i++)
	{
		printf("%d ",i);
	}
	if(m-now!=0)
	{
		printf("%d ",2*top-2*(m-now)+1);
		top++;
	}
	now=1e6+1;
	while(top<n)
	{
		printf("%d ",now);
		now+=1e5;
		top++;
	}
	return 0;
}