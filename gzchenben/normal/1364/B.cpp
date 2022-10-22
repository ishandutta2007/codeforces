#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,x,t,a[100005];
vector<int> vec;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		vec.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		vec.push_back(a[1]);
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]<=a[i-1] && a[i+1]<=a[i]) continue;
			if(a[i]>=a[i-1] && a[i+1]>=a[i]) continue;
			vec.push_back(a[i]);
		}
		vec.push_back(a[n]);
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();i++)
		{
			printf("%d ",vec[i]);
		}
		printf("\n");
	}
}