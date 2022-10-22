#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int t,g,h,n,m,a[3000000];
vector<int> vec;
bool check(int x)
{
	if(x>m) return true;
	if(a[2*x]==0 && a[2*x+1]==0)
		return false;
	if(a[2*x]>a[2*x+1])
		return check(2*x);
	else 
		return check(2*x+1);
}
void work(int x)
{
	if(a[2*x]==0 && a[2*x+1]==0)
	{
		a[x]=0;
		return;
	}
	if(a[2*x]>a[2*x+1])
	{
		a[x]=a[2*x];
		work(2*x);
	}
	else
	{
		a[x]=a[2*x+1];
		work(2*x+1);
	}
} 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		vec.clear();
		scanf("%d%d",&h,&g);
		n=(1<<h)-1;
		m=(1<<g)-1;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			while(check(i))
			{
				sum-=a[i];
				vec.push_back(i);
				work(i);
			}
		}
		printf("%lld\n",sum);
		for(int i=0;i<vec.size();i++)
		{
			printf("%d ",vec[i]);
		}
		printf("\n");
		memset(a,0,sizeof(int)*n);
	}
}