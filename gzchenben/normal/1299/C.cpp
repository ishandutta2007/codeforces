#include<cstdio>
#include<algorithm> 
using namespace std;
struct node
{
	int num;
	double val; 
}st[1000005];
int n,top;
bool check()
{
	if(top==0) return false;
	return st[top].val<st[top-1].val;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		st[++top]=(node){1,(double)x};
		while(check())
		{
			st[top-1].val=(st[top].val*st[top].num+st[top-1].val*st[top-1].num)/(st[top].num+st[top-1].num);
			st[top-1].num=st[top-1].num+st[top].num;
			top--;
		}
	}
	for(int i=1;i<=top;i++)
	{
		for(int j=1;j<=st[i].num;j++)
		{
			printf("%.12lf\n",st[i].val);
		}
	}
}