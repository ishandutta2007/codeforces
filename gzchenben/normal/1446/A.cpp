#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,t,a[200005];
long long w,sum;
vector<int> ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&w);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sum=0;
		ans.clear();
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>w) continue;
			if(a[i]>=(w+1)/2) 
			{
				printf("1\n%d\n",i);
				flag=true;
				break;
			}
		}
		if(flag) continue;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>w) continue;
			ans.push_back(i);
			sum+=a[i];
			if(sum>=(w+1)/2)
			{
				flag=true;
				break;
			}
		}
		if(!flag) printf("-1\n");
		else
		{
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
			printf("\n");
		}
	}
}