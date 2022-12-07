#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[100005],st1[100005],st2[100005],st3[100005],top1,top2,top3;
vector<pair<int,int> > ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0) continue;
		if(a[i]==1)
		{
			ans.push_back(make_pair(i,i));
			st1[++top1]=i;
		}
		if(a[i]==2)
		{
			if(top1==0)
			{
				printf("-1\n");
				return 0;
			}
			ans.push_back(make_pair(st1[top1],i));
			top1--;
			st2[++top2]=i;
		}
		if(a[i]==3)
		{
			if(top3!=0)
			{
				ans.push_back(make_pair(i,i));
				ans.push_back(make_pair(i,st3[top3]));
				top3--;
				st3[++top3]=i;
				continue;
			}
			if(top1==0 && top2==0) 
			{
				printf("-1\n");
				return 0;
			}
			if(top2==0)
			{
				ans.push_back(make_pair(i,i));
				ans.push_back(make_pair(i,st1[top1]));
				top1--;
			}
			else
			{
				ans.push_back(make_pair(i,i));
				ans.push_back(make_pair(i,st2[top2]));
				top2--;
			}
			st3[++top3]=i;
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}