#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,t,a[4005],ed;
bool vis[4005];
vector<int> vec;
bool judge()
{
	memset(vis,false,sizeof(vis));
	vis[0]=true;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=n-vec[i];j>=0;j--)
		{
			if(vis[j]) vis[j+vec[i]]=true;
		}
	}
	return vis[n];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		vec.clear();
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		int ed=2*n;
		bool flag=true;
		while(ed)
		{
			int maxn=0;
			for(int i=1;i<=ed;i++)
			{
				if(a[i]>a[maxn]) maxn=i;
			}
//			printf("push %d\n",ed-maxn+1);
			vec.push_back(ed-maxn+1);
			ed=maxn-1;
		}
		if(judge()) printf("YES\n");
		else printf("NO\n");
	}
}